/**
 * [reverse_link_list 反转链表]
 * @param  listHead [链表头指针]
 * @return          [返回反转后的链表头指针]
 *
 * 思路： 判断当前链表是否为空，当前链表的下一个为空，则反转链表的头位于当前链表处，如果还没到尾部，则将当前链表的下一个节点指向preNode，
 * 然后将preNode和currNode往下移动 
 * 
 * 
 */
LinkNode * reverse_link_list(LinkNode *listHead){

	LinkNode * newHead = NULL;
	LinkNode * currNode = listHead;
	LinkNode * preNode = NULL;
	LinkNode * nextNode;

	while(currNode != NULL){
		nextNode = currNode->m_pNext;

		if(nextNode == NULL)    // 判断是否链表尾部
			newHead = currNode;

		currNode->m_pNext = preNode;   // 置换关键点

		preNode = currNode;    // 向下移动
		currNode = nextNode;
	}

	return newHead;
}