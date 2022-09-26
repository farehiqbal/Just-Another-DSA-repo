// Not only you can create pointers to a variables you can also edit and modify the pointers.

// Changing the value of pointers also changes the value of original varibale to whom the 
// pointer was pointing.

#include <iostream>
#include <string>
using namespace std;

int main() {
  string food = "Pizza";
  string *ptr;
  string **ptr2;

  ptr = &food;
  ptr2 = &ptr;


  // Output the value of food
  cout << food << "\n";

  // Output the memory address of food
  cout << &food << "\n";

  // Access the memory address of food and output its value
  cout << *ptr << "\n";
  
  // Change the value of the pointer
  *ptr = "Hamburger";
  
  // Output the new value of the pointer
  cout << *ptr << "\n";
  
  // Output the new value of the food variable
  cout << food << "\n";

  cout << **ptr2 << endl;

  cout << ptr;

  return 0;
}