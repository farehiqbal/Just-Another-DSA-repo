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
        else{

            p[++rear] = x;
        }
    }

    int Dequeue(){
        if(isEmpty()){
            cout << "Nothing to dequeue" << endl;
        }

        else{
            int x = p[front];

            if(front == rear){
                front = rear = -1;
                return p[front];
            }

            else{

                for (int i = 0; i <= rear; i++)
                {
                    p[i] = p[i+1];
                }

                rear--;
                return x;
            }
        }


        
    }
    

};

int main(){


    return 0;
}