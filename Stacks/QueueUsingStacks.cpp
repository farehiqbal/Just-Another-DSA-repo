#include <iostream>
#include <stack>

using namespace std;


class MyQueue {
public:
    stack<int> input;
    stack<int> output;

    MyQueue() {
        
    }
    
    void enque(int x) {
        input.push(x);
    }
    
    int deque() {
       
        int x = peek();
        output.pop();
        return x;
    }
    
    int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        
        return input.empty() && output.empty();
    }

    
};

int main(){


    MyQueue queue;

    queue.enque(1);
    queue.enque(2);
    queue.enque(3);

    // cout << queue.peek();

    cout << queue.deque();
    cout << queue.deque();

    queue.enque(4);
    queue.enque(5);
    queue.enque(6);

    cout << queue.deque();
}