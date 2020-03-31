#include <iostream>
#include <fstream>
#include <cctype>
#include <stdlib.h>
#include <string>
#include "simpio.h"
#include <sstream>
using namespace std;

string infile_name_prompt(ifstream & infile, string prompt);
string outfile_name_prompt(ifstream & infile,string prompt);
string get_alpha(string prompt);
string eliminate_letters(string line, string eliminate);
void save_line(ofstream & output, string line);

int main(){
    
    ifstream infile, infile2;
    ofstream outfile;
    string output;
    string eliminate;
    string result;
    infile_name_prompt(infile, "Input File:");
    output = outfile_name_prompt(infile2, "Output File:");
    eliminate = get_alpha("Please enter letters you want to ignore: ");
    outfile.open(output.c_str());
    while (true){
        string line;
        getline(infile, line);
        if (infile.fail()) break;
        result = eliminate_letters(line, eliminate);
        save_line(outfile, result);
    }
    infile.close();
    outfile.close();  
}

string infile_name_prompt(ifstream &infile, string prompt=""){
    while (true){
        cout << prompt << endl;
        string file_name;
        getline(cin, file_name);
        infile.open(file_name.c_str());
        if (!infile.fail()) return file_name;
        infile.clear();
        cout << "Unable to open file, try again!" << endl;
        prompt = "Input File: ";
    }
    
}

string outfile_name_prompt(ifstream & infile, string prompt=""){
    while (true){
        cout << prompt << endl;
        string file_name;
        getline(cin, file_name);
        infile.open(file_name.c_str());
        infile.close();
        if (!infile.fail()) return file_name;
        infile.clear();
        cout << "Output file not exist, try again!" << endl;
        prompt = "Output File: ";
    }
}

string get_alpha(string prompt=""){
    cout << prompt << endl;
    string line;
    string letters;
    getline(cin, line);
    for (char s:line){
        if (isalpha(s)){
            letters += s;
        }
    }
    return letters;
}

string eliminate_letters(string line, string eliminate){
    string result;
    for (char s:line){
        bool indicator = false;
        for (char e:eliminate){
            if (tolower(s) == tolower(e)) {
                indicator = true;
                break;
            }
        }
        if (indicator == false) result += s;
    }
    return result;
}

void save_line(ofstream & outfile, string line){
    for (char ch:line){
        outfile.put(ch);
    }
    outfile.put('\n');
}