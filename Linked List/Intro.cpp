#include <bits/stdc++.h>
using namespace std;

class Node{
    
    public: 
    int data;    // will store data
    Node * next;   // will store address of next Node
    
    Node(int a, Node * next = NULL){
        this->data = a;
        this->next = next;
    }
      
};


int main() {
	// your code goes here
    
    // Static allocation 
    Node n1(12);
    Node n2(145);
    
    n1.next = &n2;
    
    Node *head = &n1;
    while(head != NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
    
    // =================================================================
     
    // Dynamic Allocation
    Node * n3 = new Node(100);
    Node * n4 = new Node(200);

    // n3 , n4 contain address to the Nodes stored on heap memory
    
    n3->next = n4;    
    
    Node * newHead = n3;
    
    // iterating over linked list
    while(newHead != NULL){
        cout<<newHead->data<<endl;
        newHead = newHead->next;
    }
    
}
