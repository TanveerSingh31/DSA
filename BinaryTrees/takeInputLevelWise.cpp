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


void printTree(BinaryTreeNode<int> *root) {
    if(root == NULL) return;

    cout<<root->data<<" : ";
    if(root->left != NULL) cout<<"L-"<<root->left->data<<", ";
    if(root->right != NULL) cout<<"R-"<<root->right->data;

    cout<<endl;

    printTree(root->left);
    printTree(root->right);
}


int main() { 

    BinaryTreeNode<int>* root = takeInputLevelWise();
    printTree(root);

    return 0;
}