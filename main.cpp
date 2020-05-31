#include "daysummary.h"
#include "experienceconverter.h"
#include "experienceevent.h"
#include "gameday.h"
#include "gamedayconverter.h"
#include <filesystem>
#include <iomanip>
#include <ios>
#include <iostream>

namespace fs = std::filesystem;

using namespace std;

void display_summary(DaySummary &);

int main(int argc, const char **argv) {

  try {

    if (argc < 2) {
      cerr << "usage: " << argv[0] << " file.yaml" << endl;
      return 1;
    }

    if (!fs::exists(argv[1])) {
      cerr << "File " << argv[1] << " does not exist." << endl;
      return 1;
    }

    if (fs::is_directory(argv[1])) {

      vector<gameday> campaign;

      for (auto e : fs::directory_iterator(argv[1])) {
        if (e.path().extension().string() == ".yaml") {
          YAML::Node n = YAML::LoadFile(e.path().c_str());
          gameday g = n.as<gameday>();
          campaign.push_back(g);
        }
      }

      DaySummary d(campaign);

      display_summary(d);
    } else {
      YAML::Node n = YAML::LoadFile(argv[1]);
      gameday g = n.as<gameday>();

      DaySummary d(g);

      display_summary(d);
    }

    return 0;
  } catch (exception e) {
    cerr << e.what() << endl;
    return 1;
  }
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