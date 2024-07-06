#include <bits/stdc++.h>
using namespace std;



class Queue_custom{
  
  private:
  
  int *arr;
  int nextIndex;
  int firstIndex;
  int size;
  int capacity;
  
  
  public: 
  
  Queue_custom(int size){
    arr = new int[5];
    nextIndex = 0;
    firstIndex = -1;
    this->size = 0;
    capacity = size;
  }
  
  
  void enqueue(int element){
    
    if(size == capacity)
        return; // Queue is Full
    
    
    if(firstIndex == -1) firstIndex = nextIndex; 
    arr[nextIndex] = element;
    nextIndex = (nextIndex + 1) % capacity;
    size++;
  }
  
  
  int dequeue(){
    
    if(size == 0){
        cout<<"QUEUE IS EMPTY"<<endl;
        return -1;
    }
      
    int element = arr[firstIndex];
    firstIndex = (firstIndex + 1) % capacity;
    size--;
    
    return element;
  }
  
  
  int getFront(){
      if(size == 0)
        return -1; // Queue is empty
      
      return arr[firstIndex];
  }
  
  int getSize(){
      return size;
  }
  
  bool isEmpty(){
      return getSize() == 0;
  }
  
    
};

int main() {
	// your code goes here

    Queue_custom q1(5);
    
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    
    cout<<q1.getSize()<<endl;
    cout<<q1.getFront()<<endl;
    
    cout<<q1.dequeue()<<endl;
    
    q1.enqueue(60);
    
    cout<<q1.getSize()<<endl;
    
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    
    cout<<q1.getFront()<<endl;
}
