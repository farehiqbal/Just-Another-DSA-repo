#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue <int> input;
    queue <int> output;
    MyStack() {
        
    }
    
    void push(int x) {
        output.push(x);
        
        while(!input.empty()){
            output.push(input.front());
            input.pop();
        }
        
        swap(input,output);
    }
    
    int pop() {
        
        int result = top();
        input.pop();
        return result;
    }
    
    int top() {
        return input.front();
    }
    
    bool empty() {
        return input.empty();
    }
};






int main(){

    return 0;
}