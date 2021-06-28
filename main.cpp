#include "daysummary.h"
#include "experienceevent.h"
#include "gameday.h"
#include <filesystem>
#include <fstream>
#include <functional>
#include <getopt.h>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>


namespace fs = std::filesystem;

using namespace std;

void display_summary(DaySummary &);
void display_summary_md(DaySummary &d);

vector<gameday> &load_gamedays(vector<string> &paths);

void usage() {
  cerr << "usage:" << endl
       << "experiencetable [--markdown] (source.yaml|sourcedir) " << endl;
}

int main(int argc, char *const *argv) {
  std::function<void(DaySummary &)> display_delegate = display_summary;
  static struct option long_options[] = {{"markdown", no_argument, 0, 'm'},
                                         {0, 0, 0, 0}};
  int opt;
  const char *source = nullptr;

  while ((opt = getopt_long(argc, reinterpret_cast<char *const *>(argv), "mh",
                            long_options, 0)) != -1) {
    switch (opt) {
    case 'm':
      display_delegate = display_summary_md;
      break;
    case 'h':
    case '?':
      usage();
      return EXIT_FAILURE;
    }
  }

  if (optind < argc) {
    source = argv[optind];
  }

  if (nullptr == source) {
    usage();
    return EXIT_FAILURE;
  }

  if (!fs::exists(source)) {
    cerr << "File " << source << " does not exist." << endl;
    return 1;
  }

  try {
    vector<gameday> campaign;
    vector<string> gamefiles;

    if (fs::is_directory(source)) {
      for (auto e : fs::directory_iterator(source)) {
        if (e.path().extension().string() == ".yaml") {
          gamefiles.push_back(e.path().string());
        }
      }
    } else {
      gamefiles.push_back(source);
    }

    campaign = load_gamedays(gamefiles);
    DaySummary d(campaign);
    display_delegate(d);

    return 0;
  } catch (exception &e) {
    cerr << e.what() << endl;
    return 1;
  }
}

vector<gameday> &load_gamedays(vector<string> &paths) {
  static vector<gameday> campaign;

  campaign.clear();
  for (auto filename : paths) {
    gameday g;
    experienceevent ev;
    ifstream in(filename);
    while (in) {
      in >> ev;
      g.events.push_back(ev);
    }
    campaign.push_back(g);
  }

  return campaign;
}

void display_summary(DaySummary &d) {
  int max = 0;
  for (auto p : d) {
    if (p.first.length() > max) {
      max = p.first.length();
    }
  }

  string label;
  for (auto p : d) {
    label = p.first + ":";
    cout << setw(max + 1) << left << label << " " << p.second << endl;
  }
}

void display_summary_md(DaySummary &d) {
  int max = 0;
  for (auto p : d) {
    if (p.first.length() > max) {
      max = p.first.length();
    }
  }

  cout << "| Character | XP  |" << endl << "| --------- | --- |" << endl;

  string label;
  for (auto p : d) {
    label = p.first;
    cout << "| " << setw(max) << left << label << " | " << p.second << " |"
         << endl;
  }
}
