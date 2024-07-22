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



TreeNode<int>* takeInput(){
    
    int rootData;   
	cout<<"Enter Node data"<<endl;
	cin>>rootData;
	
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout<<"Enter No. Of Children"<<endl;
	cin>>n;
	
	for(int i=0;i<n;i++){
	    cout<<"Enter "<< i <<" Child of " << rootData <<endl;
	    TreeNode<int>* child = takeInput();
	    root->children.push_back(child);
	}
	
	return root;
}

int main() {
	// your code goes here
	
	TreeNode<int>* root = takeInput();
	print(root);
	
}
