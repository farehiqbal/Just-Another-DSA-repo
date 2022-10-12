#include <iostream>

using namespace std;

const int DEFAULT_SIZE = 10;

class CustomStack{
    
    private:
        int arr[DEFAULT_SIZE];
        int top;
    
    public:
        CustomStack() {
            top = -1;
        }

    void push (int item){
        if(top == DEFAULT_SIZE - 1){
            cout << "Stack full";
            return;
        }

        arr[++top] = item;
    }

    int pop(){

        if(top == -1){
            cout << "Stack is empty";
            return NULL;
        }

        int data = arr[top--];

        return data;
    }
    int peek(){
        return arr[top];
    }

};

int main(){

    CustomStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);


    cout << stack.pop() << endl;


    cout << stack.peek();

}