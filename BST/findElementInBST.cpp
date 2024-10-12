#include<iostream>
#include<queue>
#include "BinaryTreeClass.h"
using namespace std;



BinaryTreeNode<int> * takeInputLevelWise(){

    int rootData;
    cout<<"Enter node data"<<endl;
    cin>>rootData;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* node = pendingNodes.front();
        pendingNodes.pop();

        int leftData, rightData;
        cout<<"enter left child of "<<node->data<<endl;
        cin>>leftData;
        if(leftData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftData);
            node->left = leftChild;
            pendingNodes.push(leftChild);
        }
        else{
            node->left = NULL;
        }


        cout<<"enter right child of "<<node->data<<endl;
        cin>>rightData;
        if(rightData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightData);
            node->right = rightChild;
            pendingNodes.push(rightChild);
        }
        else{
            node->right = NULL;
        }
    }

    return root;

}


bool findElement(BinaryTreeNode<int> *root, int data) {
    if(root == NULL) return false;

    if(root->data == data) {
        return true;
    }
    else if(data < root->data) return findElement(root->left, data);
    else return findElement(root->right, data);
}



// 10 5 15 2 8 12 20 -1 -1 -1 -1 -1 -1 -1 -1
// 20

int main() { 

    BinaryTreeNode<int>* root = takeInputLevelWise();
    int el;
    cin>>el;
    cout<<findElement(root, el)<<endl;

    return 0;
}