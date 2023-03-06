#include <iostream>
#include <cstring>

class Heap{

public:
  Heap();
  ~Heap();
  void addValue(int num);
  void addFile(char* fileName);
  void removeMax();
  void removeAll();
  void reHeap();
  void printHeap();
  void recurseHeap(int index, int levels, int currentLevel);

  int numOfNodes;
  

private:
  int* array;
  

};