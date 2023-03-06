#include "heap.h"
#include <fstream>

using namespace std;
#include <math.h> 

Heap::Heap(){
  numOfNodes = 0;
  array = new int[100];
}

Heap::~Heap(){
  delete array;
}

void Heap::addValue(int num){
  // If the array is empty
  if(numOfNodes < 100){
    array[numOfNodes] = num;
    numOfNodes++;
    reHeap();
  }
  else{
    cout << "Heap is full" << endl;
  }
}

void Heap::addFile(char* fileName){
  ifstream tempFile;
  tempFile.open(fileName);

  if(tempFile){
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
  if(numOfNodes > 0){
    cout << array[0] << endl;
    for(int i = 0;i < numOfNodes; i++){
      array[i] = array[i+1];
    }
    numOfNodes--;
    reHeap();
  }
  else{
    cout << "List is empty." << endl;
  }
  
}

void Heap::removeAll(){
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
  if(currentLevel != levels){
    recurseHeap((2*index)+2,levels,currentLevel+1);
  }

  for(int j = 0; j < currentLevel-1; j++){
    cout << "\t";
  }
  if(array[index]!=0){
    cout << array[index];
  } 
  cout << endl;
  if(currentLevel != levels){
    recurseHeap((2*index)+1,levels,currentLevel+1);
  }
}

void Heap::reHeap(){
  //Algorithm
  
  for(int i = numOfNodes;i > 0; i--){
    int parent = array[(i-1)/2];
    // Check if left child node is larger
    if(parent < array[i]){
      // If so, swap positions
      array[(i-1)/2] = array[i];
      array[i] = parent;
    }
  }
}


