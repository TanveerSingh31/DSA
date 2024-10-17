#include<iostream>
using namespace std;
#include<queue>
#include "BinaryTreeClass.h"

// BST Class will internally maintain a BinaryTree that is a BST

class BST {
    private:
    BinaryTreeNode<int> *root;

    public:
    BST() {
        this->root = NULL;
    }

    ~ BST() {
        delete root;
    }

    // Helper fn. hasData
    private: 
    bool hasData(int el, BinaryTreeNode<int>* node) {
        if(node == NULL) return false;

        if(node->data == el) return true;

        return hasData(el, node->left) || hasData(el, node->right);
    }

    // Checks if BST has a particular element
    public:
    bool hasData(int element) {
        return hasData(element, this->root);
    }



    // Helper fn. insertData
    private:
    void insertData(int data, BinaryTreeNode<int>* node){
        if(node == NULL){
            this->root = new BinaryTreeNode<int>(data);
            return;
        } 

        if(data < node->data) {
            if(node->left == NULL) node->left = new BinaryTreeNode<int>(data);
            else insertData(data, root->left);
        }
        else{
            if(node->right == NULL) node->right = new BinaryTreeNode<int>(data);
            else insertData(data, node->right);
        }
    }

    // Insert data to BST
    public:
    void insertData(int data) {
        insertData(data, root);
    }


    private:
    BinaryTreeNode<int>* deleteData(int el, BinaryTreeNode<int>* node){
        if(node == NULL) return NULL;

        if(node->data == el) {
            if(node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            else if(node->left == NULL && node->right != NULL) {
                BinaryTreeNode<int>* ans = node->right;
                node->right = NULL;
                delete node;
                return ans;
            } 
            else if(node->left != NULL && node->right == NULL) {
                BinaryTreeNode<int>* ans = node->left;
                node->left = NULL;
                delete node;
                return ans;
            }
            else {
                BinaryTreeNode<int>* temp = node->right;

                // find the smallest Node in right subtree and replace with root
                while(temp->left != NULL) {
                    temp = temp->left;
                }

                int tempData = temp->data;
                node->data = temp->data;
                node->right = deleteData(tempData, node->right);

                return root;
            }
        } 
        else if(el < node->data) {
            node->left = deleteData(el, node->left);
            return node;
        }
        else {
            node->right = deleteData(el, node->right);
            return node;
        }
    }

    public: 
    void deleteData(int element) {
        this->root = deleteData(element, this->root);
    }




    public: 
    void printBSTLevelWise(){

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

};