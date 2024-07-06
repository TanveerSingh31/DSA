#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node{
  public:
  
  T data;
  Node<T> *next;
  
  Node(T el){
      data = el;
      next = NULL;
  }

};


template <typename T>
class Queue_custom{
  
  private:
  
  Node<T> *front;
  Node<T> *tail;
  int size;
  
  
  public: 
  
  Queue_custom(){
    front = NULL;
    tail = NULL;
    size = 0;
  }
  
  
  void enqueue(T element){

    if(front == NULL){
        front = new Node<T>(element);
        tail = front;
    }
    else{
        Node<T> *newNode = new Node<T>(element);
        tail->next = newNode;
        tail = newNode;
    }
    size++;
  }
  
  
  T dequeue(){
    
    if(size == 0){
        cout<<"QUEUE IS EMPTY"<<endl;
        return 0;
    }
      
    T element = front->data;
    Node<T> *oldFront = front;
    front = front->next;
    delete oldFront;
    size--;
    
    return element;
  }
  
  
  T getFront(){
      if(size == 0)
        return 0; // Queue is empty
      
      return front->data;
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

    Queue_custom<char> q1;
    
    q1.enqueue('a');
    q1.enqueue('b');
    q1.enqueue('c');
    q1.enqueue('d');
    q1.enqueue('e');
    
    cout<<q1.getSize()<<endl;
    cout<<q1.getFront()<<endl;
    
    // cout<<q1.getCapacity()<<endl;
    
    q1.enqueue('f');
    
    // cout<<q1.getCapacity()<<endl;
    
    cout<<q1.getSize()<<endl;
    
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    
    cout<<q1.getSize()<<endl;
    cout<<q1.getFront()<<endl;
    cout<<q1.dequeue()<<endl;
    
    cout<<q1.getFront()<<endl;
}
