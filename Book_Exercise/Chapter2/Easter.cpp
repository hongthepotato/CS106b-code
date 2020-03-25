#include <iostream>
#include <cmath>
using namespace std;

int my_remainder(int x){
    return x % 2 == 0? 0:x;
}

void find_easter_Gauss(int year, int & month, int & day){
    if (year > 1899 || year < 1700){
        cout << "Gauss' method can only be used for year between 1700 and 1899." << endl;
        cout << "If you want to find easter in other years, refer to 'general_find_easter'." << endl;
        exit(1);
    }
    int a, b, c, d, e;
    a = my_remainder(year % 19);
    b = my_remainder(year % 4);
    c = my_remainder(year % 7);
    d = my_remainder((19 * a + 23) % 30);
    if (year > 1799){
        e = (2 * b + 4 * c + 6 * d + 4) % 7;
    } else{
        e = (2 * b + 4 * c + 6 * d + 4) % 7;
    }
    if (d+e>9){
        month = 4;
        day = d+e-9;
    }else{
        month = 3;
        day = 22+d+e;
    }
}