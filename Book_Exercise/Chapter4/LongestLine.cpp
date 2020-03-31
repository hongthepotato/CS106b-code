#include <fstream>
#include "simpio.h"
#include <iostream>
#include <string>
using namespace std;

string file_name_prompt(ifstream & infile, string prompt=""){
    while (true){
        cout << prompt << endl;
        string file_name;
        getline(cin, file_name);
        infile.open(file_name.c_str());
        if (!infile.fail()) return file_name;
        infile.clear();
        cout << "Unable to open file, try again!" << endl;
        prompt = "Input File:";
    }
}

int main(){
    string line;
    string longst_line;
    ifstream infile;
    file_name_prompt(infile, "Input file: ");
    while (true) {
        getline(infile, line);
        if (line.length() > longst_line.length()) longst_line = line;
        if (infile.eof()) break;
    }
    infile.close();
    cout << "The longest line is: " << longst_line << endl;
    return 0;
}

