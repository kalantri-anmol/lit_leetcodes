//leetcode 116 and 117 combined
// Populating the next right pointers

//InterviewBit Solution
// The first solution(below) is valid only for perfect binary trees and fails for other trees

void Solution::connect(TreeLinkNode* A) {
    if(A == NULL)return;
    // if(!A->left || !A->right)return;
    while(A->left){
        TreeLinkNode *p = A;
        while(p){
            p->left->next = p->right;
            if(p->next)
                p->right->next = p->next->left;
            p = p->next;
        }
        A = A->left;
    }
}

// Now let's write a complete generalised solution(Also the solution to Leetcode-117)
void connect(TreeLinkNode root){
	if(root==NULL)return;
	TreeLinkNode prev = NULL;		//leading node if the next layer;
	TreeLinkNode curr = root;		//traversing in the current layer;
	TreeLinkNode head = NULL;		//head of the next node

	while(current!=NULL){

		while(current!=NULL){		//traversing in the current node 
			//left child
			if(current->left!=NULL){
				if(prev!=NULL){
					prev->next = current->left;
				}
				else{
					head = current->left;
				}
				prev = current->left;
			}
			//right child
			if(current->right!=NULL){
				if(prev!=NULL){
					prev->next = current->right;
				}
				else{
					head = current->right;
				}
				prev = current->right;
			}
			//move to the next node in present layer;
			current = current->left;
		}

		//move to the next layer
		current = head;
		head= NULL;
		prev = NULL;
	}
}