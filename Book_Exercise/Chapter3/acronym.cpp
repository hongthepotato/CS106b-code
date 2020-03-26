#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string acromym(string words){
    bool indicate = true;
    string result;
    for (auto s:words){
        if (isalpha(s) && indicate){
            result += toupper(s);
            indicate = false;
        } else if (!isalpha(s)){
            indicate = true;
        }
    }
    return result;
}

void acromym_test(string words, string expected){
    string result = acromym(words);
    if (result == expected){
        cout << "Test Passed!" << endl;
    } else{
        cout << "Test Filed! Your result gives " << result << " expected " << expected;
    }
}

int main(){
    acromym_test("self-contained underwater breathing apparatus", "SCUBA");
    acromym_test("Acquired Immune Deficiency Syndrome", "AIDS");
    acromym_test("%&$^*$lsigbst eirgbr#%#&^%&arygaeurgy", "LEA");
}