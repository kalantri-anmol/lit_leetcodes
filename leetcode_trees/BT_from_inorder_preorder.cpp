//105. Contruct a binary tree from given Inorder and PreOrder

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
	root->right = build(preorder,inorder, preStart+(k-inStart)+1,preEnd, k+1, inEnd);
												 // ---------	
												// 		^
												// stuff on the left in inIndex;
	return root;
}

//driver function
 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
 	if(preorder.size() <= 0)
            return NULL;

    return build(preorder,inorder, 0, preorder.size()-1,0, inorder.size()); 
 }

//For those getting TLE in interviewBit problem: Try passing in the vectors by reference in helper function, it works
//Hashing solution
unordered_map<int,int> umap;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if(inorder.size() == 0)return NULL;
	for(int i=0;i<inorder.size();i++){
		umap[inorder[i]] == i;
	}
	return helper(preorder, inorder, 0, inorder.size()-1,0,inorder.size()-1);
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd){
	if(inStart > inEnd || preStart > preEnd) return NULL;
	TreeNode *root = new TreeNode(preorder[preStart]);
	int inIndex = umap[preorder[preStart]];
	root->left = helper(preorder,inorder,preStart+1,preStart+(inIndex-inStart),inStart,inIndex-1);
	root->right = helper(preorder,inorder,preStart+(inIndex-inStart)+1, preEnd,inIndex+1,inEnd);
	return root;
}