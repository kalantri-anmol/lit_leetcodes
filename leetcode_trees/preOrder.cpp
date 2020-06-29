//Recursive method

void preOrder(TreeNode *root,vector<int> &v){
        if(root == NULL) return;
        v.push_back(root->val);
        preOrder(root->left,v);
        preOrder(root->right,v);
    }

vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ms;
        preOrder(root,ms);
        return ms;
    }

//Iterative method

vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> stk;
        stk.push(root);
        if (root == NULL) return v;
        while(!stk.empty()){
            TreeNode *curr = stk.top();
            stk.pop();
            
            v.push_back(curr->val);
            
            //push in the right element first;
            if(curr->right!=NULL)
                stk.push(curr->right);
            //push in the left element
            if(curr->left!=NULL)
                stk.push(curr->left);
            
            //important note:- the right element is 
            // pushed in first, so that the left element can 
            // processed first
        }
        return v;
    }