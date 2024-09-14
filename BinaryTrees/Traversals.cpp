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

void PreOrderTraversal(BinaryTreeNode<int> *root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}


void PostOrderTraversal(BinaryTreeNode<int>* root){
    if(root == NULL) return;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);

    cout<<root->data<<" ";
}

void InorderTraversal(BinaryTreeNode<int>* root) {
    if(root == NULL) return;

    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);
}

// Treeinput - 100 50 60 40 30 20 10 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
int main() { 

    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout<<"preorder traversal - ";
    PreOrderTraversal(root);
    cout<<endl;

    cout<<"postorder traversal - ";
    PostOrderTraversal(root);
    cout<<endl;

    cout<<"Inorder traversal - ";
    InorderTraversal(root);
    cout<<endl;

    return 0;
}