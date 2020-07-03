//leetcode 102;
// 102. Binary Tree Level Order Traversal


    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)return {};
        vector<int> row;
        vector< vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        int count =1;
        while(!q.empty()){
            TreeNode *current = q.front();
            if(current->left)q.push(current->left);
            if(current->right)q.push(current->right);
            
            row.push_back(current->val);
            q.pop();
            if(--count == 0){
                result.push_back(row);
                row.clear();
                count = q.size();
            }
        }
        return result;
    }