struct BinaryTreeNode{
	int value;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
};


/**
 * 转换时为了处理方便， 不将treeNode 转换成 listNode 直接用treeNode当作ListNode
 * 
 */

// struct LinkNode{
// 	int value;
// 	LinkNode *prev;
// 	LinkNode *next;
// };

/**
 * [binary_search_tree_convert_list 将二叉搜索树转换成有序的双向链表]
 * @param  root [description]
 * @return      [description]
 *
 * 思路：建立一个递归思路，中序遍历   当前节点，将当前节点的右指针指向链表最后一个节点，如果链表最后一个节点不为空的话，将其右指针指向当前的树节点，
 */
BinaryTreeNode * binary_search_tree_convert_list(BinaryTreeNode * root){

	BinaryTreeNode * lastNode = NULL;

	convert(root,&lastNode);

	BinaryTreeNode * head = lastNode;
	while(head != NULL && head->left != NULL){
		head = head->left;
	}
}

void convert (BinaryTreeNode *root, BinaryTreeNode ** lastNode){
	if(root == NULL)
		return ;

	if(root->left != NULL)
		convert(root->left, lastNode);

	root->left=*lastNode;

	if(*lastNode != NULL)
		(*lastNode)->right = root;

	*lastNode = root;

	if(root->right != NULL)
		convert(root->right, lastNode);
}