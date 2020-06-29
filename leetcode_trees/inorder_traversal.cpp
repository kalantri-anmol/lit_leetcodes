// The recursive solution

// We define a separate function in recursive solution
void inorder(TreeNode *root,vector<int> &v){
	if(root==NULL) return;
	inorder(root->left,v);
	v.push_back(root->val);
	inorder(root->right,v);
}
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ans;
	inorder(root,ans);
	return ans;
}

//The iterative solution

//We use stack for iterative solution
vector<int> inorderTraversal(TreeNode* root) {
	stack<TreeNode*> s;
	std::vector<TreeNode*> v;
	TreeNode *current = root;
	while(!s.empty() || current!=NULL){
		while(current!=NULL){
			s.push(current);
			current = current->left;
		}
		current = s.top();
		s.pop();
		v.push_back(current);
		current = current->left;
	}
	return v;
}