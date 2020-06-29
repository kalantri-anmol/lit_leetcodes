//Recursive method is trivial,easy. So lets finish that first

void postOrder(TreeNode *root, vector<int> &v){
	if(root==NULL) return;
	postOrder(root->left,v);
	postOrder(root->right,v);
	v.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> amd;
	postOrder(root,amd);
	return amd;
}
// ----------------------------------------------------

//Iterative solution

vector<int> postorderTraversal(TreeNode* root){
	stack<TreeNode*> ipstk;
        ipstk.push(root);
        std::vector<int> v;
        if(root==NULL) return v;
        stack<int> op;
        while(!ipstk.empty()){
	        TreeNode *current = ipstk.top();
	        ipstk.pop();

	        op.push(current->val);

	        if(current->left!=NULL)
		    ipstk.push(current->left);

	        if(current->right!=NULL)
		    ipstk.push(current->right);
        }

//printing the elements
        while(!op.empty()){
	        v.push_back(op.top());
	        op.pop();	
        }
        return v;
}