#include <iostream>

using namespace std;


// returns nth fibonacci number.

int fibo(int n){

    if (n < 2){
        return n;
    }

    return fibo(n-1) + fibo(n - 2);


}

int main(){

    cout << fibo(6);
    
}