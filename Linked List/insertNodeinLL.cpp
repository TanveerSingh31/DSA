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


Node * insertNode(Node *head, int pos, int data){
    
    Node *temp = head;
    Node *newHead = head;
    
    int i=0;
    
    while(temp!= NULL && i<pos-1){
        temp = temp->next;
        i++;
    }       
    
    if(temp!= NULL && pos!=0){
        Node * newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else if( temp!= NULL && pos==0){        // if node is to be inserted at pos 0 , Head will be updated to newNode
        Node * newNode = new Node(data);
        newNode->next = temp;
        newHead = newNode;
    }
    
    
    return newHead;
}


void printLL(Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main() {
	// your code goes here
    Node n1(10);
    Node n2(20);
    Node n3(30);
    
    n1.next = &n2;
    n2.next = &n3;
    
    printLL(&n1);
    cout<<endl;
    
    Node *newHead = insertNode(&n1, 0, 100);
    
    printLL(newHead);

}
