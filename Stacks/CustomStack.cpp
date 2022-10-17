#include <iostream>

using namespace std;

const int DEFAULT_SIZE = 10;

class CustomStack{
    
    char arr[DEFAULT_SIZE];
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

int priority(char x)
{
    if(x == '('){
        return 0;
    }
    if(x == '+' || x == '-'){
        return 1;
    }
    if(x == '*' || x == '/'){
        return 2;
    }
    
}

void infixToPostfix(string exp){

    CustomStack stack;

    for (int i = 0; i < exp.size(); i++)
    {
        if(isalnum(exp[i])){
            cout << exp[i];
        }

        else if (exp[i]== '('){
            stack.push(exp[i]);
        }

        else if (exp[i] == ')'){
            while(stack.peek() != '('){
                cout << stack.pop();
            }

            stack.pop();
        }

        else{
            while(priority(stack.peek()) >= priority(exp[i])){
                cout << stack.pop();

            }
            stack.push(exp[i]);
        }
    }

    while(!stack.isEmpty()){
        cout << stack.pop();
    }
    
}

int evaluatePostFix(string exp){



}

int priorityMultipleBraces(char data){
    if(data == '(' || data == ')'){
        return 1;
    }
    if(data == '{' || data == '}'){
        return 2;
    }
    if(data == '[' || data == ']'){
        return 3;
    }
}

bool checkMultipleTyped(string s){
    CustomStack stack;

    int length = s.size();
    for (size_t i = 0; i < length; i++)
    {
        if(stack.isEmpty()){
            stack.push(s[i]);
        }
        else if((stack.peek() == '(' && s[i] == ')') || (stack.peek() == '{' && s[i] == '}') || (stack.peek() == '[' && s[i] == ']')){
            stack.pop();
        }
        else{
            if(priorityMultipleBraces(s[i]) <= priorityMultipleBraces(stack.peek())){
                stack.push(s[i]);
            }
            else{
                return false;
            }
        }
    }
    if(stack.isEmpty()){
        return true;
    }
    else{
        return false;
    } 
}



bool checkMutliTypedBraces(string exp){

    CustomStack stack;
    char ch;

    for (int i = 0; i < exp.size(); i++){

        if(exp[i] == '(' || exp[i] == '['|| exp[i] == '{'){
            stack.push(exp[i]);
            continue;
        }

        if(stack.isEmpty()) return false;

        switch(exp[i]){
            case ')':
                ch = stack.peek();

                if(ch == '[' || ch == '{')
                return false;
                break;

            case ']':
                ch = stack.peek();

                if(ch == '(' || ch == '{')
                return false;
                break;

            case '}':
                ch = stack.peek();

                if(ch == '(' || ch == '[')
                return false;
                break;
        }

    }

    return(stack.isEmpty());

    

}


bool checkSingleTypedBraces(string exp){

    CustomStack stack;

    for(int i = 0; i< exp.size(); i++){

        if(exp[i] == '('){
            stack.push(exp[i]);
            // cout << exp[i];
        }

        else if(exp[i] == ')'){
            if(stack.isEmpty())return false;
            stack.pop();
            // cout << exp[i];
        }

    }

    return(stack.isEmpty());
    
    
}

bool isPalindromeV3(string exp){

    CustomStack stack;

    int length = exp.size();
    int mid = length / 2;

    int temp = mid;

    while(temp < length){
        stack.push(exp[temp++]);
    }

    temp = 0;

    while(temp < mid){
        if(exp[temp++] != stack.pop()){
            return false;
        }
    }

    return true;
}

bool isPalindromeV2(string exp){

    CustomStack stack;

    int len = exp.size();

    int count = 0;

    for (int i = 0; i < len; i++)
    {
        stack.push(exp[i]);
    }

    for (int i = 0; i < len; i++)
    {
        if(exp[i] != stack.pop()){
            return false;
        }
        count++;
    }

    if(len == count) return true;

    return false;
    
    
}



bool isPalindrome(string exp){

    CustomStack stack;

    int len = exp.size();


    for (int i = 0; i < len; i++)
    {
        stack.push(exp[i]);

    }

    int i = 0;

    while(exp[i] != '0'){

        if (exp[i] != stack.peek()) return false;
        
        stack.pop();
        i++;
    }

    return true;
    


}

int main(){

//    cout << isPalindromeV2("civic");

   cout << checkSingleTypedBraces("())");

    // cout << checkMutliTypedBraces("[{()}]");
    // cout << checkMultipleTyped("[{()}]");

    // infixToPostfix("7+(5-3*6)+8/2+9");


    cout << isPalindromeV2("mango");

}