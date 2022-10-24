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

        }
        else {
            if(isEmpty()){
                
            }
        }
    }

    int Dequeue(){

        int x;

        if(isEmpty()){
            cout << "Nothing to dequeue" << endl;
        }

        else if(front == rear){

            x = p[front];

           front = rear = -1;
        }

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
        
    }

    int peek(){
        
        if(front == rear){
            cout << "empty queue";
        }

        return p[front];
        
    }
    

};
