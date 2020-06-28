ListNode* rotateRight(ListNode* head, int k){
	if(head == NULL) return NULL;

	if(head->next == NULL) return head;

	if(k == 0) return head;

	ListNode* fast = head;
	ListNode* slow = NULL;

	//calculate the length of list
	int len = 0;
	while(fast!=NULL){
		len++;
		fast = fast->next;
	}
	//variable len now contains the length of the list

	if(k%len == 0){
		return head;//if k is multiple of len, we get the same list after k rotations
	}

	fast = head;//reset the fast ptr to initial position
	int i=0;
	while(fast!=NULL){
		if(i==k){
			if(slow == NULL){
				slow = head;
			}
		}

		if(slow!=NULL){
			slow = slow->next;
		}

		fast = fast->next;
		i++;
	}

	ListNode* new_head = slow;
	fast = head;

	while(fast->next != slow){
		fast = fast->next;
	}

	fast->next = NULL;
	fast = slow;

	while(fast->next! = NULL){
		fast = fast->next;
	}
	fast->next= head;
	return new_head;

}