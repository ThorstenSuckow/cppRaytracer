module;

#include <iostream>
#include <fstream>
#include <string>
#include <ostream>

export module IOUtil;

using namespace std;

export namespace IOUtil {

    bool putContents(string filename, string content) {

        ofstream outfile{ filename };

        if (!outfile) {
            cerr << "Cannot write to " << filename << endl;
            return false;
        }

        outfile << content;
        
        outfile.close();

        return true;
    }

    string getContents(string filename) {

        ifstream infile{ filename };

        if (!infile) {
            cerr << "Cannot open " << filename << endl;
        }
        string line;
        string fileContents = "";
        while (getline(infile, line)) {
            fileContents += line + "\n";
        }

        return fileContents;
    }

    void readInto(string filename, string& contents) {

        ifstream infile{ filename };

        if (!infile) {
            cerr << "Cannot open " << filename << endl;
        }
        string line;
        string fileContents = "";
        while (getline(infile, line)) {
            fileContents += line + "\n";
        }

        contents = fileContents;
    }


}