//106. Construct a binary tree from inorder and postorder

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	pos = in = inorder.size()-1;
	return building(inorder, postorder, INT_MIN);
}

TreeNode *building(vector<int> inorder,vector<int> postorder, int stop){
	if(pos < 0) return NULL;
	if(inorder[i] == stop){
		in--;
		return NULL;
	}

	TreeNode *root = new TreeNode(postorder[pos]);
	pos--;

	root->right = building(inorder, postorder, root->val);
	root->left = building(inorder, postorder, stop);
	return root;

}

//Alternate solution but again O(n^2)

TreeNode *buildTree(vector<int> &inorder,vector<int> &postorder) {
	if(inorder.size()==0)return NULL;
	return mybuild(inorder,postorder,0, inorder.size()-1,inorder.size()-1);
}

TreeNode *mybuild(vector<int> inorder, vector<int> postorder, int start, int end, int rootIdx){
	if(start > end) return NULL;
	TreeNode *root = new TreeNode(postorder[rootIdx]);
	int pos = start;
	while(inorder[pos]!=postorder[rootIdx])
		pos++;

	root->left = mybuild(inorder, postorder,start,pos-1,rootIdx-end+pos+1);
	root->right = mybuild(inorder, postorder,pos+1, end, rootIdx-1);
	return root;
}

//For those getting TLE in interviewBit problem: Try passing in the vectors by reference in helper function it works