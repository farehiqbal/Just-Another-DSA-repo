// When pizza hut introduces new scheme to serve boomers first.

#include <iostream>

using namespace std;

class Person{
    public:
        int age;
        int id;

};

class BoomerPizzaHutt{

    public:
        int front;
        int rear;
        Person* p;
        int size;

    
    public:
        BoomerPizzaHutt(){
            front = rear = -1;
            p = new Person[128];
        }

        BoomerPizzaHutt(int size){
            front = rear = -1;
            p = new Person[this -> size = size];
        }


        void customerInTake(int id, int age){
            
            if(isFull()){
                cout << "Queue is currently full, please wait";
                return;
            }

            Person person = Person();
            person.id = id;
            person.age = age;

            if(isEmpty()){
                front = rear = 0;
                p[front] = person;
                return;
            }

            int i = rear;

            while(i >= front && age > p[i].age){
                p[i+1] = p[i];
                i--;
            }
            p[++i]= person;
            rear++;
        }

        void serveOrder(){
            if(isEmpty){
                cout << "No order to serve";

            }

            if(isFull()){
                front = rear = -1;
            }

            else{
                front++;
            }
        }


        bool isFull(){
            return rear == size - 1;
        }

        bool isEmpty(){
            return front < 0;
        }
};

