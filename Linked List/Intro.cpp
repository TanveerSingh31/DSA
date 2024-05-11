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
    

    Node n1(12);
    Node n2(145);
    
    n1.next = &n2;
    
    Node *head = &n1;
    while(head != NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
}
