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

int height(BinaryTreeNode<int> *root) {

    if(root == NULL) return 0;

    return 1 + max(height(root->left), height(root->right));
}

int getDiameter(BinaryTreeNode<int> *root) {

    if(root == NULL) return 0;

    int ans1 = height(root->left) + height(root->right);
    int ans2 = getDiameter(root->left);
    int ans3 = getDiameter(root->right);

    return max(ans1, max(ans2, ans3));
}


// Treeinput - 100 50 60 40 30 20 10 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
int main() { 

    BinaryTreeNode<int>* root = takeInputLevelWise();

    int diameter = getDiameter(root);
    cout<<"diameter = "<<diameter<<endl;

    return 0;
}