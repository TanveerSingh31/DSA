#include <bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{

    public:
    T data;
    vector<TreeNode<T>* > children;     // vector of pointers to store addresses of children nodes

    TreeNode(T data){
        this->data = data;
    }

};

// recursively print a tree
void print(TreeNode<int> *root){
    if(root == NULL) return;
    
     for(int i=0;i<root->children.size();i++){
        print(root->children[i]);
    }
    
    cout<<root->data<<": ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
}



int main() {
	// your code goes here
    
    TreeNode<int> *root = new TreeNode<int>(100);
    TreeNode<int> *node1 = new TreeNode<int>(200);
    TreeNode<int> *node2 = new TreeNode<int>(300);
    
    root->children.push_back(node1);
    root->children.push_back(node2);
    
    print(root);
    
}
