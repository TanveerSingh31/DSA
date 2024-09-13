#include <iostream>
using namespace std;

template<typename T>
class BinaryTreeNode {
    
    public: 
        T data;
        BinaryTreeNode<T>* left;
        BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

int main() {

    BinaryTreeNode<int> *root =  new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *leftChild =  new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *rightChild =  new BinaryTreeNode<int>(3);

    root->left = leftChild;
    root->right = rightChild;

    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;


    return 0;
}