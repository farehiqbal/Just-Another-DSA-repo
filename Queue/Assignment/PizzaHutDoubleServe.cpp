#include <iostream>

using namespace std;

class PizzaHutPro{
    public:
    int size;
    int *p;
    int front;
    int rear;

    PizzaHutPro(int s){
        size = s;
        p = new int[size];
        front = rear = -1;
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(front == 0 && rear == size-1){
            return true;
        }
        return false;
    }

    void orderFromFront(int id){
        if(isFull()){
            return;
        }
        if(isEmpty()){
            front = rear = 0;
            p[front] = id;
        }
        else{
            if(front != 0){
                front = front-1;
                p[front] = id;
            }
            else{
                for (int i = rear; i >= front; i--){
                p[rear+1] = p[rear];
                }
                rear = rear+1;
                p[front] = id;
            }
        }
    }

    int serveFromFront(){
        if(isEmpty()){
            return 0;
        
        }
        if(front == rear){
            int temp = p[front];
            front = rear = -1;
            return temp;
        
        }
        else{
            int temp = p[front];
            front = front+1;
            return temp;
        }
    }

    void orderFromRear(int id){
        if(isFull()){
            return;
        }
        if(isEmpty()){
            front = rear = 0;
            p[front] = id;
        }
        else{
            if(rear != size-1){
                p[++rear] = id;
            }
            else{
                for (int i = front; i <= rear; i++)
                {
                    p[i-1] = p[i];
                }
                front = front-1;
                p[rear] = id;
            }
        }
    }


    int serveFromRear(){
        if(isEmpty()){
            return 0;
        }
        else{
            int temp = p[rear];
            rear = rear-1;
            return temp;
        }
    }

};
