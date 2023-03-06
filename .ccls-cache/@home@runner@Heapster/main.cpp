
/*
* Author: Allam Syahriza
* Date: 3/5/23
* Project: Heap
* This program creates a max heap that stores integer values.
*/


#include <iostream>
#include <cstring>

#include "heap.h"
#include <math.h>


using namespace std; 
int main() {

  bool loop = true;
  Heap numHeap;
  char command[20];
  char* fileName = new char[20];
  int newNum;

  
  
  
  cout << "Enter ADD, ADD BY FILE, REMOVE, REMOVE ALL, PRINT, or QUIT" << endl;
  cout << "\n" << endl;

  while(loop){
    // Gets input from user
    cin.get(command,20,'\n');
    cin.clear();
    cin.ignore(99999,'\n');
    
    // Checks if the user wants to ADD a single number to the heap
    if(strcmp(command, "ADD") == 0){
      cout << "Enter a number: " << endl;
      cin >> newNum;
      numHeap.addValue(newNum);
      cout << "Value has been added." << endl;
      cout << "\n";
    }
    // Checks if the user wants to read in a file of numbers seperated by a space
    if(strcmp(command, "ADD BY FILE") == 0){
      cout << "Enter a file name: " << endl;
      cin.get(fileName,20,'\n');
      cin.clear();
      cin.ignore(99999,'\n');
      numHeap.addFile(fileName);
      cout << "\n";
      
    }
    // Removes the largest value in the heap
    if(strcmp(command, "REMOVE") == 0){
      numHeap.removeMax();
      cout << "\n";
    }
    // Removes every value in the heap, from largest to smallest
    if(strcmp(command, "REMOVE ALL") == 0){
      numHeap.removeAll();
      cout << "\n";
    }
    // Prints out the tree sideways
    if(strcmp(command, "PRINT") == 0){
      numHeap.printHeap();
      cout << "\n";
    }
    // Exits p
    if(strcmp(command, "QUIT") == 0){
      loop = false; 
    }
  }
  cout << "Goodbye!" << endl;
}