//105. Contruct a binary tree from given Inorder and PostOrder

TreeNode *build(vector<int> preorder, vector<int>inorder, int preStart, int PreEnd, int inStart, int inEnd){
	if(preStart > preEnd || inStart > inEnd)
		return NULL;

	TreeNode* root= new TreeNode(preorder[preStart]);

	int k=0;
	for(int i=inStart; i<=inEnd; i++){
		if(inorder[i] == preorder[preStart]){
			k==i;
			break;
		}
	}

	root->left = build(preorder,inorder, preStart+1, preStart+(k-inStart), inStart, k-1);
	root->right = build(preorder,inorder, preStart+(k-inStart+1),preEnd, k+1, inEnd);
	return root;
}

//driver function
 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
 	if(preorder.size() <= 0)
            return NULL;

    return build(preorder,inorder, 0, preorder.size()-1,0, inorder.size()); 
 }