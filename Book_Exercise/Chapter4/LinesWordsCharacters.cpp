#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

string file_name_prompt(ifstream & infile, string prompt=""){
    while (true){
        cout << prompt << endl;
        string file_name;
        getline(cin, file_name);
        infile.open(file_name.c_str());
        if (!infile.fail()) return file_name;
        infile.clear();
        cout << "Unable to open file try again!" << endl;
        prompt = "Input File: ";
    }
}

int num_of_word_in_line(string line){
    int num_words = 0;
    char prev = ' ';
    for (char s:line){
        if (isspace(prev) && !isspace(s)){
            num_words += 1;
        }
        prev = s;
    }
    return num_words;
}

int main(){
    int num_lines = 0;
    int num_chars = 0;
    int num_words = 0;
    string line;
    ifstream infile;
    file_name_prompt(infile, "Input File:");
    while (true){
        getline(infile, line);
        if (infile.fail()) break;
        num_lines += 1;
        num_words += num_of_word_in_line(line);
        num_chars += line.length();
    }
    cout << "Chars: " << setw(3) << right << num_chars << endl;
    cout << "Words: " << setw(3) << right << num_words << endl;
    cout << "Lines: " << setw(3) << right << num_lines << endl;
    return 0;
}