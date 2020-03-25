#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

bool isPerfect(int x){
    int sum = 0;
    for (int i = 1; i < x; i++){
        if (x % i == 0){
            int quotient = x / i;
            if (quotient > i){
                /* At this step i add the number x itself to sum implicitly, so it should be subtracted*/
                sum = sum + i + quotient ;
            }else{
                break;
            }
            
        }
    }
    return sum - x == x;
}

int main(){
    chrono::steady_clock sc;
    auto start = sc.now();
    for (int i = 1; i < 999999; i++){
        if (isPerfect(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
    auto end = sc.now();
    auto time_span = static_cast<chrono::duration<double>>(end - start);
    cout << time_span.count() << endl;
}