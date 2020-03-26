#include <string>
#include <iostream>

using namespace std;

bool end_with(string str, string suffix){
    if (suffix.length() > str.length()){
        return false;
    }   
    for (int i = 0; i < suffix.length(); i--){
        if (suffix[i] != str[str.length() - suffix.length() + i]){
            return false;
        }
    }
    return true;
}

void end_with_test(string str, string suffix, bool expected){
    bool judge = end_with(str, suffix);
    if (judge == expected){
        cout << "Test Passed!" << endl;
    } else{
        cout << "Test Failed!" << endl;
    }
    
    
}

int main(){
    end_with_test("apple", "e", true);
    end_with_test("banana", "a", true);
    end_with_test("abcdrfdff", "fdff", true);
    end_with_test("ab", "abcd", false);
    end_with_test("adirugleai", "akrf", false);

}