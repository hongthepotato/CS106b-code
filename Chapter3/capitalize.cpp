#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string capitalize(string str){
    string result;
    int start = -1;
    for (auto s:str){
        if (!isalpha(s)){
            result += s;
        } else if (start == -1) {
            result += toupper(s);
            start += 1;
        } else{
            result += tolower(s);
        }
    }
    return result;
}

void capitalize_test(string str, string expected){
    string result = capitalize(str);
    if (result == expected){
        cout << "Test Passed!" << endl;
    } else{
        cout << "Test Failed! Your result gives " << result << " while expected " << expected << endl; 
    }
}

int main(){
    capitalize_test("926519746 iauyg aury 21569 ,,,!@$@#^#&%#^&", "926519746 Iauyg aury 21569 ,,,!@$@#^#&%#^&");
    capitalize_test("#&#%^&airgsutgUYSRBGUAYG  3635 airgb", "#&#%^&Airgsutguysrbguayg  3635 airgb");
    capitalize_test("aISBTGSUTBSYT", "Aisbtgsutbsyt");
}