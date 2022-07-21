#include <limits>
#include <iostream>
using namespace std;
int main()
{
    int input;
    int size = -1;
    int arr[5];

    std::cout << "Greetings user! We are going to find and display the biggest element in an array of integers\n" << "Please specify the size of the array\n";
    while (size <= 1) {
        std::cout << "Please input a posiive integer\n";
        std::cin >> size;
    }
    std::cout << "Please feed in a line of " << size << " integers sepearted by spaces\n";
    std::cout << "Please note that all integers enterd that overflow the array of " << size << " will be ignored\n" 
        << "All non-integers will be ignored and marked a 0. \n\n";
    //take user input and feed it into the array
    
    for (int i = 0; i < size; i++) {
        if (i >= size) {
            std::cin.clear();
            std::cin.ignore(INT_MAX);       //managing overflow
        }
      std::cin >> input; //reading it in
      if (std::cin.fail()) {        //if it fails then it resets the array
          std::cin.clear();
          std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
          std::cout << "Error, you inputed a non integer. we set that position to zero and cleard the stack.  Please enter " << size - (i+ 1) << " more numbers\n";
          
      }
      arr[i] = input;
      
    }
    //find the one that is biggest (hard search)
    input = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > arr[i+1]) {
            input = arr[i];
        }
    }

    //print it pretty
    std::cout << "The biggest number in the array of "<< size << " is " << input;
}

