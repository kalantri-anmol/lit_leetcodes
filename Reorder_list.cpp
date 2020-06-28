void reorder_list(ListNode* head){
	if(head == NULL || head->next == NULL) return;
	ListNode* temp1,*temp2;
	temp1 = head;
	temp2 = head;
	//calculate the middle element of the list which will be
	//eventually stored in temp1-the slower ptr
	while(temp2!=NULL && temp2->next!=NULL){
		temp1 = temp1->next;
		temp2 = temp2->next->next;
	}
	temp2 = temp1->next;
	temp1->next = NULL;

	//REVERSE THE SECOND HALF OF THE LIST
	ListNode *current,*prev,*next;
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	temp1 = head;
	temp2 = prev;

	//merging the 2 lists
	ListNode *next1,*next2;
	while(temp1!=NULL && temp2!=NULL){
		next1 = temp1->next;
		next2 = temp2->next;

		temp1->next = temp2;
		temp2->next = next1;

		temp1 = next1;
		temp2 = next2;
	}
}