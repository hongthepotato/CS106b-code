#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

double my_sqrt(double x){
    if (x < 0){
        cerr << "Negative number cannot have real square root, try again." << endl;
        exit(1);
    }
    double guess = x/2;
    double precision = 1e-4;
    double boundary = x / guess;
    double ave = (guess + boundary)/2;
    while (abs(guess - ave)>precision && abs(boundary - ave)>precision)
    {
        guess = (guess + boundary)/2;
        boundary = x / guess;
        ave = (guess + boundary)/2;
    }
    return guess;
}


int main(){
    vector<double> test1{0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001};
    vector<double> test2{0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
    vector<double> test3{1,3,6,9,12,15};
    vector<double> test4{-1, 0, 3};
    for (int i = 0; i < 6; i++){
        cout << my_sqrt(test3[i]) << endl;
    }
    
}