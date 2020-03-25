#include<iostream>
#include <cmath>

using namespace std;

int roundToNearestInt(float x){
    if (x >= 0)
    {
        return x + 0.5;
    } return x - 0.5;
    
}

void claim(bool if_true, int calInt, int expected){
    if (if_true)
    {
        cout << "Test Passed" << endl;
    }   else {
        cout << "Expected " << expected << " but you give " << calInt <<" test failed." << endl;
    }  
}

void roundToNearestIntTest(double x, int expected){
    int calInt = roundToNearestInt(x);
    bool if_true = (calInt == expected);
    claim(if_true, calInt, expected);
}

int main(){
    roundToNearestIntTest(3.999, 4);
    roundToNearestIntTest(-3.999, -4);
    roundToNearestIntTest(0.1, 0);
    roundToNearestIntTest(3.21, 3);
}