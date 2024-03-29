#include <iostream>

using namespace std;

class CustomQueue{

    public:
        int size;
        int *p;
        int front;
        int rear;

    CustomQueue(){
        size = 100;
        p = new int[size];
        front = -1;
        rear = -1;
    }

    CustomQueue(int x){
        size = x;
        p = new int[size];
        front = -1;
        rear = -1;

    }

    bool isFull(){
        if(rear == size - 1) return true;
        return false;
    }

    bool isEmpty(){
        if(rear == -1){
            return true;
        }

        return false;
    }
    
    void Enqueue(int x){

        if(isFull()){
            cout << "Can't Enqueue, No space"<< endl;

        }
        if(front == -1){
            front++;
            p[++rear] = x;
        }
        else{
            rear++;
            p[rear] = x;
        }
    }

    int Dequeue(){

        int x;

        if(isEmpty()){
            cout << "Nothing to dequeue" << endl;
        }

        // else if(front == rear){

        //     x = p[front];

        //    front = rear = -1;
        // }

        else{
            
            x = p[front];

            for (int i = 0; i < rear; i++)
            {
                p[i] = p[i+1];
            }

            rear--;
            
            }
        return x;
    }


    void Display(){
        
        if(front == rear){
            cout << "Empty queue";
        }

        for (int i = 0; i <= rear; i++)
        {
            cout << p[i] << "<--";
        }
        
        cout << endl;
    }

    int peek(){
        
        if(front == rear){
            cout << "empty queue";
        }

        return p[front];
        
    }
    

};

int main(){

    CustomQueue queue(10);
    
    queue.Enqueue(1);
    // queue.Enqueue(2);
    // queue.Enqueue(3);
    // cout << queue.Dequeue()<<endl;
    // cout << queue.Dequeue()<<endl;
    // cout << queue.Dequeue();
    queue.Enqueue(2);
    // cout << queue.Dequeue();
    queue.Display();
    cout <<queue.peek();
}