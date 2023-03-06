#include "heap.h"
#include <math.h> 
#include <fstream>

using namespace std;

Heap::Heap(){
  numOfNodes = 0;
  array = new int[100];
}

Heap::~Heap(){
  delete array;
}

void Heap::addValue(int num){
  // Checks if heap is full
  if(numOfNodes < 100){
    // Adds value to bottom of heap
    array[numOfNodes] = num;
    numOfNodes++;
    // Reorders heap
    reHeap();
  }
  else{
    cout << "Heap is full" << endl;
  }
}

void Heap::addFile(char* fileName){
  // Checks if file exists
  ifstream tempFile;
  tempFile.open(fileName);
  
  if(tempFile){
    // Reads through every value in file, adds to heap
    cout << "File found." << endl;
    ifstream MyReadFile(fileName);
    int temp;
    while (MyReadFile >> temp){
      addValue(temp);
    }
    cout << "Values have been added." << endl;
  }
  else{
    cout << "Unable to find file" << endl;
  }
}

void Heap::removeMax(){
  // Checks if list is empty
  if(numOfNodes > 0){
    cout << array[0] << endl;
    // Shifts every value in array one slot over to the left
    for(int i = 0;i < numOfNodes; i++){
      array[i] = array[i+1];
    }
    // Reorders heap
    numOfNodes--;
    reHeap();
  }
  else{
    cout << "List is empty." << endl;
  }  
}

void Heap::removeAll(){
  // Removes every value in heap
  int numToRemove = numOfNodes;
  for(int i = 0;i < numToRemove; i++){
    removeMax();
  }
}

void Heap::printHeap(){
  // Calculates how many "levels" are in the heap
  float levels;
  float log = log2(numOfNodes+1);
  if((fmod(log,1.0))>0){
    levels = 1+log-(fmod(log,1.0));
  }
  else{
    levels = log;
  }
  recurseHeap(0,levels,1);
  
}

void Heap::recurseHeap(int index,int levels,int currentLevel){
  // Recurses into right child node
  if(currentLevel != levels){
    recurseHeap((2*index)+2,levels,currentLevel+1);
  }

  // Prints appropriate number of spaces
  for(int j = 0; j < currentLevel-1; j++){
    cout << "\t";
  }
  // Prints value of array at index
  if(array[index]!=0){
    cout << array[index];
  } 
  cout << endl;
  // Recurses into left child node
  if(currentLevel != levels){
    recurseHeap((2*index)+1,levels,currentLevel+1);
  }
}

void Heap::reHeap(){
  // Reorders heap
  
  for(int i = numOfNodes;i > 0; i--){
    int parent = array[(i-1)/2];
    // Checks if child is larger than parent
    if(parent < array[i]){
      // Swaps positions
      array[(i-1)/2] = array[i];
      array[i] = parent;
    }
  }
}


