
// This is your motivation to start using nullptr when dealing with pointers, lol.
// This file demonstrates why you should be using nullptr while most people use NULL.
// it is an instance and keyword at the same time, of class nullptr_t.

// I haved created an overloaded method, one takes int as parameter and other as pointer.



#include <iostream>

using namespace std;

void fun(char *s){
    cout << "Hi, yes me, fun2 was called. Surprised?";
}

void fun(int x){
    cout << "Hi, fun1 was called";
}

int main(){

    fun(NULL); 

    // Although it looks like that the first method will be called, afterall, passing in what seems to
    // be a pointer. 

    // he trouble is that because NULL is 0, and 0 is an integer,
    // the second version of func will be called instead.

    // Even the compiler gives you warning. 
}