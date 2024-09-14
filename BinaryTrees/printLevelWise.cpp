#include<iostream>
#include<queue>
#include "BinaryTreeClass.h"
using namespace std;


void printLevelWise(BinaryTreeNode<int>* root){

    if(root == NULL) return;

    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {
        BinaryTreeNode<int>* node = pendingNodes.front();
        pendingNodes.pop();

        cout<<node->data<<" :";

        if(node->left){
            cout<<"L "<<node->left->data<<" ";
            pendingNodes.push(node->left);
        }
        if(node->right){
            cout<<"R "<<node->right->data;
            pendingNodes.push(node->right);
        }

        cout<<endl;
    }

    return;
}



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

int main() { 

    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);

    return 0;
}