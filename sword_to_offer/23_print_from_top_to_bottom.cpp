/**
 * 广度优先遍历  将每个节点都往deque里面存, 然后一个个按顺序去出来进行处理
 * 
 */

BinaryTreeNode{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

void print_from_top_to_bottom(BinaryTreeNode * root){

	if(root == NULL)
		return false;

	deque<BinaryTreeNode *> nodes;

	nodes.push_back(root);

	while(nodes.size()){
		BinaryTreeNode *node = nodes.front();
		nodes.pop_front();
		printf("%d ", node->value);

		if(root->left)
			nodes.push_back(root-left);

		if(root->right)
			nodes.push_back(root->right);
	}

}