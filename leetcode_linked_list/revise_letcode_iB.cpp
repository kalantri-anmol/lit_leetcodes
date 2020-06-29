//Reorder List
void reorder_List(ListNode* head){
	ListNode *temp1, *temp2;
	if(head == NULL || head->next == NULL) return;

	temp1 = head;
	temp2 = head;
	//get the middle element of the list
	while(temp2!=NULL && temp2->next!=NULL){
		temp1 = temp1->next;
		temp2 = temp2->next->next;
	}
	temp2 = temp1->next;
	temp1->next = NULL;

	//reverse the list
	ListNode *current, *next, *prev = NULL;
	current = temp2;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current= next;
	}
	temp2 = prev;
	temp1 = head;

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
---------------------------------------------------------------------------------------------------------------------------------------------
//Problem: Remove node from Nth position from the end and return the head;
ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *temp= head;
	int len = 0;
	while(temp!=NULL){
		len++;
		temp = temp->next;
	}
	if(len-n==0){
		head = head->next;
		return head;
	}
	temp = head;
	ListNode* temp2;
	for(int i=0;i<len-n-1;i++){
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = temp2->next;
	delete(temp2);
	return head;


}
--------------------------------------------------------------------------------------------------------------
// Delete duplicates from sorted list such that the element appears only once
ListNode* Solution::deleteDuplicates(ListNode* head){
	ListNode* current = head;
	ListNode *next;
	while(current->next!=NULL){
		next = current->next;

		if(next->val == current->val) {
			current->next = next->next;
			delete(next);
		}

		else current = current->next;
	}
	return head;
} 
--------------------------------------------------------------------------------------------------------------
//Delete all nodes that have duplicates of them
      // E.g   1->1->1->2->3->NULL
      // returns	2->3->NULL

ListNode* Solution::deleteDuplicates(ListNode* head) {
	ListNode *fake_head = new ListNode();
	fake_head->next = head;
	ListNode *current = head;
	ListNode *prev = fake_head;

	while(current != NULL){
		while(current->next != NULL && current->val != current->next->val){
			current = current->val;
		} 
		if(prev->next == current){
			prev = prev->next;
		}
		else{
			prev->next = current->next;
		}
		current = current->next;
	}
	return fake_head->next;
}

--------------------------------------------------------------------------------------------------------------------
//merge two sorted lists - attempted on leetcode again
-------------------------------------------------------------------------------------------------------------------
//Rotate List
ListNode *temp1 = head;
//calculate the length of the list
if(head == NULL || head->next == NULL) return head;

int len = 0;
while(temp!=NULL){
	len++;
	temp = temp->next;
}

if(k>len){
	k = k%len;
}

if(k%len == 0){
	return head;
}
ListNode *slow;
temp = head;
int i=0;
while(temp!=NULL){
	if(i==k){
		if(slow == NULL){
			slow = head;
		}
	}

	if(slow!=NULL){
		slow = slow->next;
	}

	temp = temp->next;
	i++;
}

ListNode *new_head = slow;
temp = head;
while(temp->next!=slow){
	temp = temp->next;
}
temp->next = NULL;
temp = slow;
while(temp->next != NULL){
	temp = temp->next;
}
temp->next = head;
return new_head;

-----------------------------------------------------------------------------------------------------------------------
//Reorder List
ListNode* Solution::reorderList(ListNode* A) {
	//find the middle element
	ListNode *temp1,*temp2;
	temp1 = head;
	temp2 = head;
	while(temp2!=NULL && temp2->next!=NULL){
		temp1 = temp1->next;
		temp2 = temp2->next->next;
	}
	//temp1 has the middle element
	//Now we start reversing the second half of the list
	temp2 = temp1->next;
	temp1->next = NULL;

	ListNode *prev = NULL, *current, *next;
	current = temp2;
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	temp2 = prev;
	temp1 = head;
	//merging begins now
	ListNode *next1, *next2;
	while(temp1!=NULL && temp2!=NULL){
		next1 = temp1->next;
		next2 = temp2->next;

		temp1->next = temp2;
		temp2->next = next1;

		temp1 = next1;
		temp2 = next2;
	}


}
------------------------------------------------------------------------------------------------------------------------
//reverse linked list
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(A==NULL || A->next == NULL) return A;
    
    ListNode *new_head = new ListNode(0);
    ListNode *prev = new_head, *current = A, *next;
    new_head->next = A;
    int i=1;
    while(i<C){
        if(i<B){
            prev = prev->next;
            current = current->next;
        }
        else{
            next = current->next;
            current->next = current->next->next;
            next->next = prev->next;
            prev->next = next;
        }
        i++;
    }
    return new_head->next;
}
---------------------------------------------------------------------------------------------------------------------
problems remaining - 
1>partition list
https://leetcode.com/problems/partition-list/discuss/686843/cpp-solution-%3A-faster-than-100-submissions

2>K reverse lists