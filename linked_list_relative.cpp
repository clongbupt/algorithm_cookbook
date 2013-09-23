//linked list 


//remove nth node from end of list

// 思路: 两个指针， 一个先走n步，然后一起走   注意长度小于n的链表判断
// 删除时需要注意是否删除head本身

void delete_nth_node (link_node * head, int n){
	if ( !head ) return;

	int len = 0;
	link_node * tmp = head;
	while(tmp){ len++; tmp=tmp->next; }

	if (len < n ) return;

	link_node * prev = head;
	link_node * cur = head;
	link_node * fast = head;

	while(n){
		fast = fast->next;
		n --;
	}

	while(fast){
		prev = cur;
		cur = cur->next;
		fast = fast->next;
	}

	prev->next = cur->next;
	delte cur;

}


//remove duplicates

// 思路: 注意判断空链表和一个节点的链表   还有对链表节点的删除
// 
// 将不重复的节点放到前面， 然后将后面的删除

link_node * remove_duplicates(link_node * head){
	if ( !head || !head->next ) return head;

	link_node * p1 = head->next;
	link_Node * p0 = head;

	while(p1){
		if (p1->value != p0->value){
			p0 = p0->next;
			p0->val = p1->val;
		}
		p1 = p1->next;
	}

	link_node * toberemoved = p0->next;
	po->next = NULL;
	while(toberemoved){
		link_node * t = toberemoved;
		toberemoved = toberemoved->next;
		delete t;
	}
	return head;
}

//merge two sorted lists

// 思路: 三个循环   尽量少用额外空间

link_node * merge_two_sorted_lists(link_node * l1, link_node * l2){
	link_node * dummy = (link_node * )malloc(sizeof(link_node) );

	link_node * current = dummy;

	while(l1 && l2){

		if ( l1->val <= l2->val ){
			current->next = l1;
			current = current->next;
			l1 = l1->next;
		}else{
			current->next = l2;
			current = current->next;
			l2 = l2->next;
		}
	}

	while(l1){
		current->next = l1;
	}

	while(l2){
		current->next = l2;
	}

	return dummy->next;


}

//reverse nodes in k-group


// 完整的链表反转
link_node * reverse(link_node * head){
	if ( !head ) return NULL;

	if ( !head->next ) return head;

	link_node * dummy = (link_node * )malloc(sizeof(link_node));
	dummy->next = head;

	link_node * prev = dummy;
	link_node * last = head;
	link_node * cur = head->next;

	while(cur){
		last->next = cur->next;
		cur->next = prev->next;
		prev->next = cur;
		cur = last->next;
	}

	return dummy->next;
}

//Rotate list

// 将链表环起来   然后根据k确定新的head位置

link_node * rotate_list(link_node * head, int k){
	if ( k <=0 ) return head;

	int len = 0;
	link_node * tmp = head;
	link_node * tail;
	while(tmp) { 
		if ( !tmp->next )
			tail = tmp;
		tmp=tmp->next; 
		len++; 
	}

	k = k % len;

	tail->next = head;

	for(int i=1; i<k; i++)
		head = head->next;
	tail = head;
	tail->next = NULL;
	head = head->next;

	return head;


}

//Partition List

// 快排中的partition的链表实现   用两个头指针，将小于pivot的指向pre_left, 将大于pivot的指向pre_right
// 然后将两个链表合并

link_node * partition ( link_node * head, int x ){
	if ( !head ) return NULL;

	link_node * dummy_left = (link_node *)malloc(sizeof(link_node));
	link_node * dummy_right = (link_node *)malloc(sizeof(link_node));

	link_node * pre_left = dummy_left;
	link_ndoe * pre_right = dummy_right;

	link_node * cur = head;

	while(cur){
		if (cur->val >= x){
			pre_right->next = cur;
			pre_right = pre_right->next;
		}else{
			pre_left->next = cur;
			pre_left = pre_left->next;
		}
		cur = cur->next;
	}

	pre_left->next = dummy_right->next;	
	pre_right->next = NULL;

	return dummy_left;

}

//Reverse List

// 旋转链表中n-m的部分

// 只旋转指定位置的值

link_node * rotate_list(link_node * head, int n, int m){

	if( !head || n<1 || m <1 ) return NULL;

	if ( !head->next ) return head;

	if ( n >= m ) return head;

	int len = 0;
	link_node * tmp = head; 
	while(tmp){ len++; tmp=tmp->next; }

	link_node * dummy = (link_node *)malloc(sizeof(link_node));

	dummy->next = head;

	link_node * prev = dummy;
	link_node * cur = head;

	int cnt = 1;
	while(cur && cnt < m){
		if( cnt < n ) prev = cur;
		cur = cur->next;
		cnt++;
	}

	link_node * end = cur->next;

	link_node * last = prev->next;
	cur = last->next;

	while(cur){

		last->next = cur->next;
		cur->next = prev->next;
		prev->next = cur;
		cur = last->next;

	}

	return dummy->next;


}

//Detecting Loop

// 循环检测  快慢指针

bool is_loop(link_node * head){
	
	if ( !head || !head->next) return false;

	link_node * slow = head->next;
	link_node * fast = head->next->next;

	while(fast && fast->next && fast != slow){
		fast = fast->next->next;
		slow = slow->next;
	}

	if ( fast == slow )
		return true;

	return false;

}

link_node * get_node( link_node * head ){
	if( !head || !head->next ) return NULL;

	link_node * slow = head->next;
	link_node * fast = head->next->next;

	while(fast && fast->next && fast != slow){
		fast = fast->next->next;
		slow = slow->next;
	}

	if( slow == fast )
		slow = head;
	else
		return NULL;

	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

// Find the middle node

// 快慢指针   快指针到末尾时， 慢指针到中间位置

link_node * is_loop(link_node * head){
	
	if ( !head || !head->next) return false;

	link_node * slow = head->next;
	link_node * fast = head->next->next;

	while(fast && fast->next && fast != slow){
		fast = fast->next->next;
		slow = slow->next;
	}

	if ( fast == slow )
		return slow;
	else
		return NULL;

}

// Reservior sampling

// TODO  从非常大的链表中 取出完全随机值 

// Clone the complex linked list

// 复制复杂链表    先对链表基本节点进行复制，然后复制复杂链表

link_node * clone_complex_node (link_node * head)
{
	if ( !head ) return NULL;

	link_node * cur = head;
	while (cur){
		link_node * node = (link_node * )malloc(sizeof(link_node));
		
		node->value = cur->value;
		node->sibling = NULL;

		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}

	cur = head;
	link_node * node;
	while(cur->next){
		node = cur->next;
		if (cur->sibling)
			node->sibling = cur->sibling->next;
		cur = cur->next;
	}

	link_node * head2 = (link_node * )malloc(sizeof(link_node));
	cur = head->next;
	cur2 = head2;
	while(cur->next){
		cur2->next = cur;
		cur2 = cur2->next;
		cur = cur->next->next;
	}

	return head2;

}

// Check if a singly linked list is palidrome

// TODO 判断链表是否为同位数  palidrome

// Get the intersection node of two linked list 

// 求两个链表的公共交点

link_node * get_intersection_node ( link_node * l1, link_node * l2){
	int len1 = 0;
	link_node * p1 = l1;
	while(p1){
		len1 ++;
		p1=p1->next;
	}

	int len2 = 0;
	link_node * p2 = l2;
	while(p2){
		len2++;
		p2=p2->next;
	}

	bool flag;  // 表示l1长
	int sub;
	if (len1 > len2){
		flag = true;
		sub = len1 - len2;
	}
	else{
		flag = false;
		sub = len2 - len1;
	}

	if(flag){
		p1 = l1;
		for(int i=0; i<sub; i++){
			p1 = p1->next;
		}
	}else{
		p2 = l2;
		for (int i=0; i<sub; i++)
			p2 = p2->next;
	}

	while(p1 && p2 && p1->value != p2->value){
		p1 = p1->next;
		p2 = p2->next;
	}

	if(p1->value == p2->value)
		return p1;


}

// Union and intersection of two linked list

// 求两个链表的交和并