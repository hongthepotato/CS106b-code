#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string remove_doubled_letters(string str){
    char prev;
    string result;
    for (auto s:str){
        if (s != prev){
            result += s;
            prev = s;
        }
    }
    return result;
}

void remove_doubled_letters_test(string str, string expected){
    string result = remove_doubled_letters(str);
    if (result == expected){
        cout << "Test Passed! " << endl;
    } else{
        cout << "Test Fail! Your result gives " << result <<" while expected " << expected << endl;
    }
}

int main(){
    remove_doubled_letters_test("bookkeeper", "bokeper");
    remove_doubled_letters_test("ttjjnnffddly", "tjnfdly");
    remove_doubled_letters_test("committee", "comite");
}