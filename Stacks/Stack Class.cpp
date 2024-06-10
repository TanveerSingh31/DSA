#include <bits/stdc++.h>
using namespace std;


class Stack1{
        
    private: 
        int *arr;
        int nextIndex;
        int totalSize;
      
    public:
        // Constructor
        Stack1(int size){
            arr = new int[size];
            nextIndex = 0;
            totalSize = size;
        }
        
        void push(int element){
            // Stack full
            if(nextIndex == totalSize) return;
            
            arr[nextIndex] = element;
            nextIndex++;
        }
        
        int top(){
            // Stack empty
            if(nextIndex == 0) return -1;
            
            return arr[nextIndex-1];
        }
        
        
        int pop(){
            // Stack empty
            if(nextIndex == 0) return -1;
            
            int element = arr[nextIndex-1];
            nextIndex--;
            return element;
        }
        
        int getSize(){
            return nextIndex;
        }
        
        bool isEmpty(){
            return nextIndex == 0;
        }
};



int main() {
	// your code goes here
	
	Stack1 s1(5);
	
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	
	cout<<s1.getSize()<<endl;
	
	cout<<s1.top()<<endl;

    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    
    cout<<s1.top()<<endl;
        
    cout<<s1.getSize()<<endl;
}
