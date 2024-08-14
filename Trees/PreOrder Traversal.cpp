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



// Root gets printed first, children are printed afterwards.
void preOrder(TreeNode<int>* root){

    if(root == NULL) return;

    cout<<root->data<<endl;

    for(int i=0; i<root->children.size(); i++){
        preOrder(root->children[i]);
    }

}



TreeNode<int>* takeInputLevelWise(){
    
    int rootData;
    cout<<"Enter root data = "<<endl;
    cin>>rootData;
    
    queue<TreeNode<int>*> pendingNodes;   // This will store those Nodes whose children have not been taken/ connected
    TreeNode<int> *root = new TreeNode<int>(rootData);
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();   // Once children are taken , we will pop it from pending Nodes queue
        
        int noOfChildren;
        cout<<"Enter no. of children of " << front->data << endl;
        cin>>noOfChildren;
        
        for(int i=0; i<noOfChildren; i++){
            int childData;
            cout<<"Enter " << i << "th child of " << front->data <<endl;
            cin>>childData;
            
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            
            // For each child, 
            front->children.push_back(childNode); // 1. and add the child to "children array" of parent
            pendingNodes.push(childNode);  // 2. push the child to back of "queue", 
        }
    }
    
    return root;
    
}

int main() {
	// your code goes here
	
    // 	tree input => 10 2 20 30 2 40 50 2 80 90 0 2 60 70 0 0 0 0
	TreeNode<int>* root = takeInputLevelWise();
	preOrder(root);

}
