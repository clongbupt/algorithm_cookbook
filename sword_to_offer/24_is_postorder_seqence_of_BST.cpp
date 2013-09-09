struct BinaryTreeNode{
	int value;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
};

bool is_postorder_sequence_of_BST(int seq[], int len){
	if(seq == NULL || len == 0)
		return false;

	int root = seq[len-1];

	int i;
	for(i=0; i<len-1; i++){
		if(seq[i] > root)
			break;
	}

	int j = i;
	for(;j<len-1;j++){
		if(seq[j] < root)
			return false;
	}

	bool left = true;
	if(i>0)
		left = is_postorder_sequence_of_BST(seq, i);

	bool right = true;
	if(i<length-1)
		right = is_postorder_sequence_of_BST(seq, len-1-i);

	return (left && right);
}