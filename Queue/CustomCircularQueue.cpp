#include <iostream>

using namespace std;

class CustomCircularQueue{

    public:
        int size;
        int *p;
        int front;
        int rear;

    CustomCircularQueue(){
        size = 100;
        p = new int[size];
        front = -1;
        rear = -1;
    }

    CustomCircularQueue(int x){
        size = x;
        p = new int[size];
        front = -1;
        rear = -1;

    }

    bool isFull(){

        return ((rear + 1) % size == front);
    }

    bool isEmpty(){
        
        return (front == -1);
    }
    
    void Enqueue(int x){

        if(isFull()){
            cout << "Can't Enqueue, No space"<< endl;
            return;
        }
        else {
            if(isEmpty()){
                
                front = rear = 0;
            }

            else{
                rear = (rear + 1)% size;
            }
        }

        p[rear] = x;
    }

    int Dequeue(){

        int x;

        if(isEmpty()){
            cout << "Empty queue.";

            return -1;
        }

        else{
            x = p[front];

            if(front == rear){
                front = rear = -1;
            }

            else{
                front = (front + 1) % size;
            }

            
        }

        return x;
    }


    void Display(){
        
        if(isEmpty()){
            cout << "Empty queue";
        }

        // if(front == rear){
        //     cout << p[front];
        // }

        else{
            for (int i = front; i <= rear; i++)
            {
                cout << p[i] << "<--";
            }
        }
        cout <<endl;
    }

    int peek(){
        
        if(isEmpty()){
            cout << "EMPTY QUEUE";
        }


        return p[front];
        
    }
    

};

int main(){

    CustomCircularQueue cq(5);

    cq.Enqueue(1);
    cq.Enqueue(2);
    cq.Enqueue(3);
    cq.Enqueue(4);
    cq.Enqueue(5);
    // cq.Display();
    // cq.Dequeue();
    // cq.Display();
    // cout << cq.peek();
    cq.Enqueue(6);
    cq.Enqueue(7);
    // cq.Display();
    // cout << cq.p[4];
    cq.Display();
}