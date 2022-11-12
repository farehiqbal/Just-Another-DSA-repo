#include <iostream>

using namespace std;

const int MAX_ORDERS = 5;


class PizzaHut{

    public:

        int *orders;
        int front;
        int rear;

    PizzaHut(){

        orders = new int[MAX_ORDERS];
        front = -1;
        rear = -1;
    }

    bool isFull(){

        return ((rear + 1) % MAX_ORDERS == front);
    }

    bool isEmpty(){
        
        return (front == -1);
    }


    // Enque or placing orders, return true if order is successfully placed

    void placeOrder(int orderNo){

        if(isFull()){
            cout << "Maximum orders are placed, please wait.";
            return;
        }

        else{

            if(isEmpty()){

                front = rear = 0;

            }

            else{
                rear = (rear + 1) % MAX_ORDERS;
            }
        }

        orders[rear] = orderNo;

        cout << "Order placed successfully with order id: " << orders[rear] << endl; 
    }

    void serveOrder(){

        if(isEmpty()){
            
            cout << "No order to be served!";
            return;
        }

        else{
            cout << "Serving order no: " << orders[front] << endl;

            // serving an order means theres no need of it in orders queue.
            // i.e. the order has been completed

            if(front == rear){
                front = rear = -1;
            }

            else{
                front = (front + 1) % MAX_ORDERS;
            }

            cout << "Served successfully"<< endl;
        }
    }

    void displayOrders(){

        if(isEmpty()){
            cout << "No orders to display" << endl;
            return;
        }

        else{

            for(int i = front; i<= rear; i++){
                cout << orders[i] << "<--";
            }
        }
    }


};



int main(){

    PizzaHut pizzaHut;

    pizzaHut.placeOrder(1);
    pizzaHut.placeOrder(2);
    pizzaHut.placeOrder(3);
    pizzaHut.placeOrder(4);
    pizzaHut.placeOrder(5);
    // pizzaHut.placeOrder(6);
    pizzaHut.displayOrders();

}