    bool isValidBST(TreeNode* root) {
        TreeNode *pre = NULL;
        stack<TreeNode*> s;
        TreeNode *current = root;
        while(!s.empty() || current!=NULL){
            while(current !=NULL){
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            if(pre && current->val<=pre->val)return false;
            pre = current;
            current = current->right;
        }
        return true;
    }

    //Remember, that we use inorder traversal, because of the nature of binary search->It's performed on a sorted array.
    //So while traversing the tree in inorder traversal, we verify that our tree is a binary search tree and we make sure
    // that the current element we are holding is greater than the previous one
