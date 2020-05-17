#include "experienceconverter.h"
#include "experienceevent.h"
#include <iostream>

using namespace std;

int main(int argc, const char **argv) {

  try {
    YAML::Node example;
    experienceevent exampleevent;
    exampleevent.character = "Francois";
    exampleevent.points = 3;
    exampleevent.reason = "Just because";

    example = exampleevent;

    YAML::Emitter out;
    out << example;

    cout << out.c_str() << endl;

    YAML::Node src = YAML::LoadFile("experience.yaml");

    experienceevent event = src.as<experienceevent>();

    cout << "Character: " << event.character << endl
         << "Points: " << event.points << endl
         << "Reason: " << event.reason << endl;

    cout << "Node size: " << src.size() << endl;
    return 0;
  } catch (exception e) {
    cerr << e.what() << endl;
    return 1;
  }
}
