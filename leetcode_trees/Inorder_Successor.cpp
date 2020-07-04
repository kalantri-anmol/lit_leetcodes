Node* Find(Node* root, int data){
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data > data) Find(root->left);
	else (root->data < data) Find(root->right);
}


Node* FindMin(Node* root){
	if(root == NULL) return NULL;
	while(root->left !=NULL){
		root = root->left;
	}
	return root;

}
Node* GetSuccessor(Node* root,int data){
	//Search the tree for the given node
	Node* current = Find(root,data);
	if(current == NULL) return NULL;
	//Case 1: We have a right subtree,
	if(current->right !=NULL){
		return FindMin(current->right);
	}
	else{
		//No right subtree
		Node* succesor = NULL;
		Node* ancestor = root;
		while(ancestor!=current){
			if(current->data < ancestor->data){
				succesor = ancestor;// so far this is the deepest node for which the given node is in left
				ancestor = ancestor->left;
			}
			else{
				ancestor = ancestor->right;
			}
		}
		return succesor;
	}
}