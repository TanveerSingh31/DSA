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
    
    int n;
    cin>>n;

    Node *head = NULL;
    Node *tail = NULL;

    for(int i=0; i<n; i++){
        int data;
        cin>>data;

        Node *n = new Node(data);
        
        cout<<n<<endl;


        if(head == NULL){
            cout<<"==========="<<head<<endl;
            head = n;
        }    

        if(tail != NULL){
            tail->next = n;  // link prevNode(tail) with currNode
        } 
        tail = n;   // update tail to newNode
    }
    
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    
}
