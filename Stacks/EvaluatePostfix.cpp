#include <iostream>

using namespace std;

const int DEFAULT_SIZE = 10;

class CustomStack{
    
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

    bool isEmpty(){

        if (top == -1) return true;

        return false;
    }

    bool isFull(){

        if(top == DEFAULT_SIZE - 1) return true;

        return false;
    }

};

int EvaluatePostfix(string exp){

    CustomStack stack;

    for(int i = 0; i < exp.size(); i++){

        if(isdigit(exp[i])){
            stack.push(exp[i] - '0');
        }

        else{
            int x = stack.pop();
            int y = stack.pop();

            if(exp[i] == '+'){
                stack.push(y+x);
            }
            else if(exp[i] == '-'){
                stack.push(y-x);
            }
            else if(exp[i] == '*'){
                stack.push(y*x);
            }
            else if(exp[i] == '/'){
                stack.push(y/x);
            }
            
        }

    }

    return stack.peek();

}

int main(){

    cout << EvaluatePostfix("6523+8*+3+*");
}