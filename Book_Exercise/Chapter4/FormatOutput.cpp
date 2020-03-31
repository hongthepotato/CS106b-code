#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    cout << setw(7) << "theta" << "|" << setw(12) << "sin(theta)" << "|" << setw(12) << "cos(theta)" << "|" << endl;
    cout << setw(8) << setfill('-') << "|" << setw(13) << "|" << setw(13) << "|" << endl;
    int theta = -90;
    for (int i = 0; i < 13; ++i){
        cout << setfill(' ') << setw(7)<< fixed << setprecision(7) << theta + i*15 << "|" << setw(12) << sin(theta + i*15) << "|" << setw(12) << cos(theta + i*15) <<"|"<< endl;
    }
}