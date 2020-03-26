#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool is_sentence_palindrome(string sentence){
    string str;
    for (auto s:sentence){
        if (isalpha(s)){
            str += s;
        }
    }
    for (int i = 0; i < str.length() / 2; ++i){
        if (tolower(str[i]) != tolower(str[str.length() -1 -i])){
            return false;
        }
    }
    return true;
}

void palindrome_test(string sentence, bool expected){
    bool judge = is_sentence_palindrome(sentence);
    if (judge == expected){
        cout << "Test Passed! " << endl;
    } else{
        cout << "Test Failed! " << endl;
    }
}

int main(){
    cout << "This program tests for sentence palindrome." << endl;
    cout << "Indicate the end of the input with a blank line." << endl;
    cout << "Enter a sentence: " << endl;
    string sentence;
    getline(cin, sentence);
    if (is_sentence_palindrome(sentence)){
        cout << "This sentence is a palindrome." << endl;
    } else{
        cout << "That sentence is not a palindrome." << endl;
    }
    return 0;
}