#include<iostream>
using namespace std;

double celsius_to_fahrenheit(double cel){
    double fahren = cel * 9 / 5 + 32;
    return fahren;
}

int main(){
    cout << "Enter a temperature in celsius degrees: " << endl;
    double cel;
    cin >> cel;
    double fahren = celsius_to_fahrenheit(cel);
    cout << cel << " degrees in celsius equals " << fahren << " in fahrenheit" << endl;
    return 0;
}
