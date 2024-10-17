#include<iostream>
using namespace std;
#include "BSTClass.h"



int main(){
    
    BST* bst1 = new BST();

    bst1->insertData(10); 
    bst1->insertData(20); 
    bst1->insertData(5); 

    bst1->printBSTLevelWise();

    bst1->deleteData(10);

    bst1->printBSTLevelWise();

    cout<<bst1->hasData(10)<<endl;
    cout<<bst1->hasData(5)<<endl;

    bst1->deleteData(10);
    bst1->printBSTLevelWise();

    return 0;
}