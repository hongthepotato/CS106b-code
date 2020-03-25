#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int x){
    if (x > 1)
    {
        int boundry = sqrt(x);
        int frac_num = 0;
        for (int i = 1; i <= boundry; i++)
        {
            if (x % i == 0){
                frac_num += 1;
            }
        }
        return frac_num == 1;
    }
    return false;
}

int main(){
    for (int i = 1; i <= 100; i++){
        if (is_prime(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}