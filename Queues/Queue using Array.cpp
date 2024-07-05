#include <bits/stdc++.h>
using namespace std;



class Queue_custom{
  
  private:
  
  int *arr;
  int nextIndex;
  int firstIndex;
  int size;
  
  
  public: 
  
  Queue_custom(){
    arr = new int[5];
    nextIndex = 0;
    firstIndex = -1;
    size = 0;
  }
  
  
  void enqueue(int element){
    
    if(nextIndex > 4){
        nextIndex = 0;
    }
    
    if(nextIndex == firstIndex){
        cout<<"QUEUE IS FULL"<<endl;
        return;
    }
    
    if(firstIndex == -1) firstIndex = nextIndex; 
    arr[nextIndex] = element;
    nextIndex++;
    size++;
  }
  
  
  int dequeue(){
    if(firstIndex > 4){
        firstIndex = 0;
    }  
    
    if(size == 0){
        cout<<"QUEUE IS EMPTY"<<endl;
        return -1;
    }
      
    int element = arr[firstIndex];
    firstIndex++;
    size--;
    
    return element;
  }
  
  
  int getFront(){
      if(firstIndex < 0 || firstIndex == nextIndex) return -1;
      
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

    Queue_custom q1;
    
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
}
