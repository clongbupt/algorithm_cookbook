/**
 * 主要是考虑测试用例和链表基本操作
 *
 * 传入的参数为空，目标值太大等用例需要尽量多考虑
 *
 * 该题的思路：两个指针，一个指针先走K步，然后与另一个指针一起走，直到先走的指针碰到尾部，返回后走的指针
 *
 * 其他类似的题目：   
 * 
 * a. 求链表的中间节点   若链表中间节点总数为奇数，返回中间节点，若为偶数返回中间两个节点的任意节点
 *
 * b. 判断一个单向链表是否形成环形结构       
 *
 * 解答类似： 定义两个指针，一个快，每次走两步，一个慢，每次走一步
 *
 * a. 终止条件： 走的快的到尾部时， 返回走的慢的指针位置
 *
 * b. 中止条件： 两个指针相遇时， 链表存在环？ 走的快的到达链表末尾，则不存在环
 * 
 */

struct ListNode{
	int m_nValue;
	ListNode * m_pNext;
};

ListNode* get_last_k(ListNode *pListHead, unsigned int k){

	if(pListHead == NULL || k == 0)
		return NULL;

	ListNode *pAhead = pListHead;
	ListNode *pBhead = pListHead;

	for(int i=0; i<k; i++){
		if(pAhead->m_pNext != NULL)   // 每次都需要判断链表长度是否大于K
			pAhead = pAhead->m_pNext;
		else
			return NULL;
	}

	while(pAhead->m_pNext != NULL){
		pAhead = pAhead->m_pNext;
		pBhead = pBhead->m_pNext;
	}

	return pBhead;

}

/**
 * [is_loop_list 判断链表是否存在环]
 * @param  listHead [链表头部指针]
 * @return          [返回true/false]
 */
bool is_loop_list(LinkNode *listHead){
	if(listHead == NULL)
		return false;

	LinkNode *fast_node = listHead;
	LinkNode *slow_node = listHead;

	while(fast_node->m_pNext != NULL ){
		fast_node = fast_node->m_pNext;
		fast_node = fast_node->m_pNext;

		slow_Node = slow_node->m_pNext;

		if(fast_node == slow_node)
			return true;
	}

	return false;

}

LinkNode * get_middle_node(LinkNode * listHead){
	if(listHead == NULL)
		return NULL;

	LinkNode *fast_node = listHead;
	LinkNode *slow_node = listHead;

	while(fast_node->m_pNext != NULL ){
		fast_node = fast_node->m_pNext;
		fast_node = fast_node->m_pNext;

		slow_Node = slow_node->m_pNext;
	}

	return slow_node;

}

