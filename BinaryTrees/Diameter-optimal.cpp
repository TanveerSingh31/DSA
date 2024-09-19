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

// T = O(n) =>
// NOTE :  in Tree we will generally get multiple items from single func. call,
// instead of doing multiple func. calls to get different things, to avoid repetition
pair<int, int> getHeightDiameter(BinaryTreeNode<int> *root) {

    if(root == NULL) return make_pair(0, 0);

    pair<int, int> leftAns = getHeightDiameter(root->left);
    int leftHeight = leftAns.first;
    int leftDiameter = leftAns.second; 

    pair<int, int> rightAns = getHeightDiameter(root->right);
    int rightHeight = rightAns.first;
    int rightDiameter = rightAns.second;

    int currAns = leftHeight + rightHeight;

    int currHeight = 1+max(leftHeight, rightHeight);

    return make_pair(currHeight, max(currAns, max(leftDiameter, rightDiameter)));
}


// Treeinput -> 100 50 60 40 30 20 10 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
// Treeinput2 -> 100 -1 60 -1 40 -1 30 -1 20 -1 -1  = right sided tree (unbalanced)
// TreeInput3 -> 100 20 30 30 40 -1 -1 50 40 -1 50 -1 -1 -1 70 -1 60 -1 -1 70 -1 -1 -1 (diameter present on left side of tree)

int main() { 

    BinaryTreeNode<int>* root = takeInputLevelWise();

    pair<int, int> diameter = getHeightDiameter(root);
    cout<<"diameter = "<<diameter.second<<endl;

    return 0;
}