//1. LCA in BST is easier. So we will calculate that first
// leetcode 235
TreeNode *LowestCommonAncestor(TreeNode *root, TreeNode *p,TreeNode *q) {
	if(root == NULL)return NULL;
	if(p->val > root->val && q->val > root->val){
		return LowestCommonAncestor(root->right, p, q);
	}
	if(p->val < root->val && q->val < root->val){
	return LowestCommonAncestor(root->left, p, q);
	}
	return root;
}

//leetcode 236
TreeNode *LowestCommonAncestor(TreeNode *root, TreeNode *p,TreeNode*q) {
	if(root ==NULL)return NULL;
	if(root->val = p->val || root->val == q->val)return root;

	TreeNode *SearchLeft = LowestCommonAncestor(root->left,p,q);
	TreeNode *SearchRight = LowestCommonAncestor(root->right,p,q);

	if(SearchRight == NULL)return SearchLeft;
	if(SearchLeft == NULL)return SearchRight;

	return root;
}

//InterviewBit LCA

//helper function 1:
TreeNode *findNode(TreeNode *root,int B, int C){
	if(root==NULL)return NULL;
	if(root->val == B || root->val ==C)return root;

	TreeNode *LeftSearch = lca(root->left, B,C);
	TreeNode *RightSearch = lca(root->right,B,C);

	if(LeftSearch == NULL)return RightSearch;
	if(RightSearch == NULL)return LeftSearch;

	return root;
}

//helper function 2: to find if A or B or both exist in tree
bool ispresent(TreeNode *root, val1){
	if(root==NULL)return false;
	if(root->val == val1) return true;
	return (ispresent(root->left, val1) || ispresent(root->right,val1));
}

//driver function
int lca(TreeNode *root, int val1, int val2) {
	if(!(ispresent(root->val,val1)) || !(ispresent(root->val,val2))) return -1;
	TreeNode *res = findNode(root,B, C);
	if(!res)return -1;
	return res->val;
}