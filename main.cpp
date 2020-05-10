#include <iostream>
#include "experienceevent.h"
#include "experienceconverter.h"

using namespace std;

int main(int argc, const char** argv) {

	YAML::Node src = YAML::LoadFile("experience.yaml");

	experienceevent event = src.as<experienceevent>();

	cout << "Character: " << event.character << endl
		<< "Points: " << event.points << endl
		<< "Reason: " << event.reason << endl;

	return 0;
}
