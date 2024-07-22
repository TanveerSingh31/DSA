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
	
	
	TreeNode<int>* root = takeInputLevelWise();
	print(root);

}
