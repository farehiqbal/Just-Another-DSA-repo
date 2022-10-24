// Priority Queue Implementation: Unordered array;
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class PriorityQueue{

    class item{
            public:
            int value;
            int priority;
        };

    public:
        int size;
        item *p;
        int front;
        int rear;

        
    
    PriorityQueue(){
        size = 100;
        p[size];
        front = -1;
        rear = -1;
    }

    PriorityQueue(int x){
        size = x;
        p[size];
        front = -1;
        rear = -1;
    }

    bool isFull(){

        return (front == size - 1);
    }

    bool isEmpty(){

        return (rear == -1);
    }

    void Enqueue(int value, int priority){

        rear++;

        p[rear].value = value;
        p[rear].priority = priority;
    }

    int peek(){

        int highestPriority = INT_MIN;
        int ind = -1;

        // Finding element with highest priority
        
        for (int i = 0; i < size; i++)
        {
            // If priority is same choose element with higheer value

            if(highestPriority == p[i].priority && ind > -1 && p[ind].value < p[i].value){

                highestPriority = p[i].priority;
                ind = i;

            }

            else if (highestPriority < p[i].priority){
                highestPriority = p[i].priority;
                ind = i;

            }
        }
        
        return ind;
    }

    void Dequeue(){

        int ind = peek();

        // left shift
        for (int i = 0; i < size; i++)
        {
            p[i] = p[i+1];
        }

        rear--;

        
    }
};


int main(){

    PriorityQueue pq(10);
    pq.Enqueue(100,1);
    pq.Enqueue(10,1);
    // cout << pq.isEmpty();

    cout << pq.peek();



}

