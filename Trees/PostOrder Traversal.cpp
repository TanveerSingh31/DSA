
// Children get printed first, Root gets printed afterwards.

void postOrder(TreeNode<int> *root){
    
    if(root == NULL) return;
    
    for(int i=0; i<root->children.size(); i++){
        postOrder(root->children[i]);
    }
    
    cout<<root->data<<endl;
    
}