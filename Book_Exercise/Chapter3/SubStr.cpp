#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string substr(string str, string::size_type pos, string::size_type n){
    if ( pos > str.length()){
        cerr << "Specified length larger than the length of the whole string" << endl;
        exit(1);
    }
    string result;

    //'str.length() - pos' gives num of chars from pos (included) to end of string
    string::size_type boundary = min(str.length() - pos, n);
    for (auto i = pos; i < pos + boundary; i++){
        result += str[i];
    }
    return result;
}

void substr_test(string str, string::size_type pos, string::size_type n, string expected){
    string result = substr(str, pos, n);
    if (result == expected){
        cout << "Test Passed!" << endl;
    } else{
        cout << "Test Failed!" << "Your result is " << result <<" expected "<< expected << endl;
    }
}

int main(){
    substr_test("abcdefg", 1, 10, "bcdefg");
    substr_test("ligsrstgbyrsugy", 5, 3, "stg");
}