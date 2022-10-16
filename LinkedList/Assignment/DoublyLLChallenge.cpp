#include <iostream>;

using namespace std;

class Car{
    public:
        string riderName;
        string carName;
        string regNo;
        string type;
        Car* next;
        Car* prev;
        Ride* ride;



};

class Ride{
    public:
        string riderName;
        float km;
        float charges;
        int numOfRides;
        Ride* next;
        

};

Car* head = NULL;
Car* last = NULL;
Car* currrent = NULL;
Ride* curr = NULL;
// int numberOfrides;



void registerNewCar(){

    Car* newCar = new Car();
    
    cout << "Enter rider name: ";
    cin >> newCar ->riderName;

    cout << "Enter car name: ";
    cin >> newCar -> carName;

    cout << "Enter RegNO: ";
    cin >> newCar -> regNo;

    cout << "Enter car type : ";
    cin >> newCar -> type;
    

    if(head == NULL){
        head = last = newCar;

    }else{
        last -> next = newCar;
        newCar -> prev = last;
        last = newCar;
    }

}

void displayAllCars(){
    int count = 1;

    if(!head) cout << "No data to display";


    while(head != NULL){
        cout << "Car" << count++ << endl;
        cout << head ->carName << endl;
        cout << head ->regNo << endl;
        cout << head -> riderName << endl;

        cout << head-> ride -> numOfRides;
        
        head = head -> next;
    }

}


void displayTypeTwoCars(){
    if(!head) cout << "No data to display";

    while(head != nullptr){

        if(head ->type == "2"){
            int count = 1;
            cout << "Car" << count++ << endl;
            cout << head ->carName << endl;
            cout << head ->regNo << endl;
            cout << head -> riderName << endl;

            cout << head-> ride -> numOfRides;
        }

        head = head -> next;
    }

}

void addNewRide(){

    Ride* newRide = new Ride();

    cout<<"Enter rider's name:";
    cin>>newRide->riderName;

    cout<<"Enter charrges:";
    cin>>newRide->charges;

    cout<<"Enter total km's:";
    cin>>newRide->km; 

    string reg;
    cout << "Enter regNO: ";
    cin >> reg;

    Car* temp = head;

    while(temp != nullptr){

        if(reg == temp -> regNo){

            if(temp -> ride == NULL){
                temp ->ride = newRide;
                temp -> ride -> numOfRides++;
            }
            else{
                Ride* traverser = temp -> ride;
                
                while (traverser -> next != nullptr)
                {
                    traverser = traverser -> next;
                }
                traverser -> next = newRide;
                temp -> ride -> numOfRides++;
            }
        break;
        }
        temp = temp -> next;
    }
}

int main(){

    

}


   


