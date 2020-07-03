void flatten(TreeNode* root) {
	if(root == NULL)return;
	while(root!=NULL){
		if(root->left && root->right){
			TreeNode *t = root->left;
			while(t->right)
				t = t->right;
			t->right = root->right;
		}

		if(root->left){
			root->right = root->left;
		}
		root->left = NULL;
		root = root->right;
	}
}