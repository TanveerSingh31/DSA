#include <bits/stdc++.h>
using namespace std;

// LL Class
template <typename T>
class Node{
    
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this->data = data;
        next = NULL;
    }
};

// Stack Class
template <typename T>
class StackusingLL{
        
    private: 
        // need to specify datatype, before using class name, if class is made using Templates
        Node<T>* head;
        int size;
      
    public:
        // Constructor
        StackusingLL(){
            head = NULL;
            size = 0;
        }
        
        void push(T element){
            // Stack full
            // need to specify datatype, before using class name, if class is made using Templates
            Node<T> *newNode = new Node<T>(element);
            
            newNode->next = head;
            head = newNode;
            size++;
        }
        
        T top(){
            // Stack empty
            if(head == NULL) return 0;
            
            return head->data;
        }
        
        
        T pop(){
            // Stack empty
            if(head == NULL) return 0;
            size--;
            T element = head->data;
            
            // need to specify datatype, before using class name, if class is made using Templates
            Node<T> *oldHead = head;
            head = head->next;
            
            delete oldHead;
            return element;
        }
        
        int getSize(){
            return size;
        }
        
        bool isEmpty(){
            return getSize()==0;
        }
};



int main() {
	// your code goes here
	cout<<"=====================INT STACK LL========================="<<endl;
	StackusingLL<int> s1;
	
// 	s1.push(1);
// 	s1.push(2);
// 	s1.push(3);
	s1.push(4);
	
	cout<<"size: "<<s1.getSize()<<endl;
	cout<<"top: "<< s1.top()<<endl;
	cout<<"pop: "<<s1.pop()<<endl;
	cout<<"pop "<<s1.pop()<<endl;
	
	cout<<"size: "<<s1.getSize()<<endl;
	cout<<"isEmpty: "<<s1.isEmpty()<<endl;
    
}
