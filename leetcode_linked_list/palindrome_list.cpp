int Solution::lPalin(ListNode* head){
	ListNode* temp1 = head;
	ListNode* temp2 = head;

	while(temp2!=NULL && temp2->next!=NULL){
		temp1 = temp1->next;
		temp2 = temp2->next->next;
	}

	if(temp2!=NULL){
		temp1 = temp1->next;//if the list has odd number of nodes, we dont care about the middle node
	}

	temp2 = head;

	ListNode* rev = NULL;
	ListNode* current = temp1;

	while(current !=NULL){
		temp1 = current->next;
		current->next = rev;
		rev = current;
		current = temp1;
	}

	//comparing nodes element wise in reverse list and original list 
	while(rev!=NULL){
		if(rev->val !=temp2->val) return 0;

		temp2 = temp2->next;
		rev = rev->next;
	}
}