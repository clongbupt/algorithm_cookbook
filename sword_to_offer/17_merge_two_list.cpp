struct LinkNode{
	int m_nValue;
	LinkNode * m_pNext;
};

/**
 * [merge_two_list 有序链表归并]
 * @param  listHeadA [description]
 * @param  listHeadB [description]
 * @return           [description]
 *
 * 先单独判断，找到正确的头结点位置
 *
 * 然后利用循环依次往下归并，对于某个链表已经为空的情况， 直接将另外一个链表的剩余节点链接上即可
 *
 * 注意别链表的空判断其中一个为空也能正确合并
 * 
 */
LinkNode * merge_two_list(LinkNode * listHeadA, LinkNode * listHeadB){
	if(listHeadA == NULL ） 
		return listHeadB;
	else if (listHeadB == NULL)
		return listHeadA;

	LinkNode *newHead ;
	LinkNode *currNodeA = listHeadA;
	LinkNode *currNodeB = listHeadB;

	if(currNodeA->m_nValue > currNodeB->m_nValue){
		newHead = currNodeB;
		currNodeB = currNodeB->m_pNext;
	}else{
		newHead = currNodeA;
		currNodeA = currNodeA->m_pNext;
	}

	LinkNode *newNode = newHead;
	while(currNodeA != NULL && currNodeB != NULL){
		if(currNodeA->m_nValue > currNodeB->m_nValue){
			newNode->m_pNext = currNodeB;
			newNode = newNode->m_pNext;
			currNodeB = currNodeB->m_pNext;
		}else{
			newNode->m_pNext = currNodeA;
			newNode = newNode->m_pNext;
			currNodeA = currNodeA->m_pNext;
		}
	}

	while(currNodeA != NULL){
		newNode->m_pNext = currNodeA;
		newNode = newNode->m_pNext;
		currNodeA = currNodeA->m_pNext;
	}

	while(currNodeB != NULL){
		newNode->m_pNext = currNodeB;
		newNode = newNode->m_pNext;
		currNodeB = currNodeB->m_pNext;
	}

	return newHead;
}

/**
 *
 * 用链表存储大数  还是很麻烦的，结果值得放在新增的链表节点中
 *
 * 另外链表中的数据最好是从头到尾是数字的最低位到最高位， 进位更为方便，  如果不是先进行链表反转
 *
 * 大数中主要是进位问题和符号问题
 *
 * 创建新的链表节点为 LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode))
 * 
 */

LinkNode * add_two_number(LinkNode *listHeadA, LinkNode *listHeadB){
		if(listHeadA == NULL ） 
		return listHeadB;
	else if (listHeadB == NULL)
		return listHeadA;

	LinkNode *newHead ;
	LinkNode *currNodeA = listHeadA;
	LinkNode *currNodeB = listHeadB;

	int sum = currNodeA->m_nValue + currNodeB->m_nValue;

	newHead = (LinkNode *)malloc(sizeof(LinkNode));   // 创建一个空节点, 返回的是指针
	newHead->m_nValue = sum % 10;
	newHead->m_pNext = NULL;

	int carry = sum / 10;

	currNodeA = currNodeB->m_pNext;
	currNodeB = currNodeB->m_pNext;

	LinkNode *newNode = newHead;
	while(currNodeA != NULL && currNodeB != NULL){
		
		sum = currNodeA->m_nValue + currNodeB->m_nValue + carry;

		newNode->m_pNext = (LinkNode *)malloc(sizeof(LinkNode));   // 创建一个空节点, 返回的是指针
		newNode = newNode->m_pNext;
		newNode->m_nValue = sum % 10;
		newNode->m_pNext = NULL;

		carry = sum / 10; 

	}

	while(currNodeA != NULL){
		sum = currNodeA->m_nValue + carry;

		newNode->m_pNext = (LinkNode *)malloc(sizeof(LinkNode));   // 创建一个空节点, 返回的是指针
		newNode = newNode->m_pNext;
		newNode->m_nValue = sum % 10;
		newNode->m_pNext = NULL;

		carry = sum / 10; 
	}

	while(currNodeB != NULL){
		sum = currNodeB->m_nValue + carry;

		newNode->m_pNext = (LinkNode *)malloc(sizeof(LinkNode));   // 创建一个空节点, 返回的是指针
		newNode = newNode->m_pNext;
		newNode->m_nValue = sum % 10;
		newNode->m_pNext = NULL;

		carry = sum / 10; 
	}

	if( carry != 0 ){
		newNode->m_pNext = (LinkNode *)malloc(sizeof(LinkNode));
		newNode = newNode->m_pNext;
		newNode->m_nValue = carry;
		newNode_m_pNext = NULL;
	}

	return newHead;
}