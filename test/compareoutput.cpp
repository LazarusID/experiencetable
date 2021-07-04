#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, const char **argv) {
    
    string actual;
    string expected;

    if (argc != 2) {
        cerr << "usage: program_under_test.exe | " << argv[0] << " expected.txt" << endl;
        return EXIT_FAILURE;
    }
    ifstream expectedstream(argv[1]);

    while(cin && expectedstream) {
        getline(cin, actual);
        getline(expectedstream, expected);
        if (actual != expected) {
            cerr << "Expected: \"" << expected << "\"" << endl;
            cerr << "Actual:   \"" << actual   << "\"" << endl;
            return EXIT_FAILURE;
        }
    }     
    
    if (cin) {
        cerr << "Actual continues after expected end." << endl;
        return EXIT_FAILURE;
    }
    if (expectedstream) {
        cerr << "Expected continues after actual end." << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}