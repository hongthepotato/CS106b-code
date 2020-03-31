#include <cmath>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <time.h>
using namespace std;

string file_name_prompt(ifstream & infile, string prompt);
int random_integer(int low, int high);
char random_letter();
string replace(string line);

int main(){
    srand(int(time(NULL)));
    ifstream infile;
    file_name_prompt(infile, "Input file :");
    string line;
    string result;
    while (true){
        getline(infile, line);
        if (infile.fail()) break;
        result = replace(line);
        cout << result << endl;
    }
    
}

string file_name_prompt(ifstream & infile, string prompt=""){
    while (true){
        cout << prompt << endl;
        string file_name;
        getline(cin, file_name);
        infile.open(file_name);
        if (!infile.fail()) return file_name;
        infile.clear();
        cout << "Unable to open file, try again! " << endl;
        prompt = "Input File: ";
    }
}

char random_letter(){
    char ch = 'a';
    return ch + random_integer(0, 25);
}

int random_integer(int low, int high){
    double normalize = rand()/(double(RAND_MAX + 1));
    double rescale = normalize * (double(high) - low + 1);
    int num = floor(rescale + low);
    return num;
}

string replace(string line){
    string result;
    for (char s:line){
        if (!isalpha(s)) {
            result += s;
        } else if (isupper(s)) {
            result += toupper(random_letter());
        } else{
            result += random_letter();
        }   
    }
    return result;
}