#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string trim(string words){
    string result;
    for (auto s:words){
        if (!isspace(s)){
            result += s;
        }
    }
    return result;
}

void trim_test(string str, string expected){
    string result = trim(str);
    if (result == expected){
        cout << "Test Passed!" << endl;
    } else{
        cout << "Your result gives " << result << " but expected " << expected << endl;
    }
}

int main(){
    trim_test("akerb kaub   autgb  aer", "akerbkaubautgbaer");
    trim_test(" ","");
    trim_test("     aeruburygb      ub", "aeruburygbub");
    trim_test("7146  #$^#$^  *%*argyg     ury", "7146#$^#$^*%*argygury");
}