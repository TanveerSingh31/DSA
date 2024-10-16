#include<iostream>
using namespace std;
#include "BinaryTreeClass.h"

// BST Class will internally maintain a BinaryTree that is a BST

class BST {
    private:
    BinaryTreeNode<int> *root;

    public:
    BST() {
        this->root = NULL;
    }

    ~BST() {
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
        if(node == NULL) this->root = new BinaryTreeNode<int>(data);

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
    void deleteData(int el, BinaryTreeNode<int>* node){
        if(node == NULL) return;

        
    }

    public: 
    void deleteData(int element) {
        deleteData(element, this->root);
    }

};