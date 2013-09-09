BinaryTreeNode{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

bool is_subtree(BinaryTreeNode *rootA, BinaryTreeNode *rootB){

	if (rootA == NULL)
		return false;
	else if(rootB == NULL)
		return true;

	bool flag =  true;

	flag = has_subtree(rootA, rootB);

	if(!flag)
		flag = is_subtree(rootA->left, rootB);
	if(!flag)
		flag = is_subtree(rootB->left, rootB);

	return flag;
}

bool has_subtree(BinaryTreeNode *rootA, BinaryTreeNode *rootB){
	if(rootB == NULL)
		return true;

	if(rootA == NULL)
		return false;


	if(rootA->value != rootB->value)
		return false;

	return has_subtree(rootA->left, rootB->left) && has_subtree(rootA->left, rootB->left);
}