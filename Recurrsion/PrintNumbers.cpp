#include <iostream>

using namespace std;

void print(int x){

    if (x == 5){
        cout << x;
        return;
    }

    cout << x << endl;
    print(x + 1);
}

void print5(int n){
    cout << n;
}

void print4(int n){
    cout << n<< endl;
    print5(5);
}


void print3(int n){
    cout << n<< endl;
    print4(4);
}

void print2(int n){
    cout << n <<endl;
    print3(3);
}

void print1(int n){
    cout << n << endl;
    print2(2);
}

int main(){

    // print1(1);

    print(1);

}