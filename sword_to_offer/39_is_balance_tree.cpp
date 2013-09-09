struct BinaryTreeNode{
	int value;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
};

/**
 * [is_balanced_tree 判断当前的树是否为平衡二叉树]
 * @param  root   [description]
 * @param  deepth [description]
 * @return        [description]
 *
 * 主要是在递归时记录当前节点的深度，然后返回是否为平衡二叉树
 *
 * 测试用例： 树只有一个节点，无节点，然后平衡二叉树等
 * 
 */
bool is_balanced_tree(BinaryTreeNode * root, int * deepth){
	if (root == NULL){
		*deepth = 0;
		return true;
	}

	int left,right,diff;
	if(is_balanced_tree(root->left, &left) && is_balanced_tree(root->right, &right)){
		diff = left - right;
		if(diff <= 1 && diff >= -1){
			*deepth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;
}