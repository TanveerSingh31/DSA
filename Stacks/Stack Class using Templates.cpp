#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack1{
        
    private: 
        T *arr;
        int nextIndex;
        int totalSize;
      
    public:
        // Constructor
        Stack1(int size){
            arr = new T[size];
            nextIndex = 0;
            totalSize = size;
        }
        
        void push(T element){
            // Stack full
            if(nextIndex == totalSize) return;
            
            arr[nextIndex] = element;
            nextIndex++;
        }
        
        T top(){
            // Stack empty
            if(nextIndex == 0) return 0;
            
            return arr[nextIndex-1];
        }
        
        
        T pop(){
            // Stack empty
            if(nextIndex == 0) return 0;
            
            T element = arr[nextIndex-1];
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
	cout<<"=====================CHAR STACK========================="<<endl;
	Stack1<char> s1(5);
	Stack1<int> s2(5);
	
	s1.push('a');
	s1.push('b');
	s1.push('c');
	s1.push('d');
	
	cout<<s1.getSize()<<endl;
	
	cout<<s1.top()<<endl;

    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    
    cout<<s1.top()<<endl;
        
    cout<<s1.getSize()<<endl;
    
    cout<<"=====================FLOAT STACK========================="<<endl;
    
    Stack1<float> s3(5);
    
    s3.push(1.110);
	s3.push(2.897);
	s3.push(3.786);
	s3.push(2.915);
	
	cout<<s3.getSize()<<endl;
	
	cout<<s3.top()<<endl;

    cout<<s3.pop()<<endl;
    cout<<s3.pop()<<endl;
    cout<<s3.pop()<<endl;
    cout<<s3.pop()<<endl;
    cout<<s3.pop()<<endl;
    
    cout<<s3.top()<<endl;
        
    cout<<s3.getSize()<<endl;
    
}
