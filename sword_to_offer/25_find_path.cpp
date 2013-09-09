include "vector"

using namespace std;

struct BinaryTreeNode{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


/**
 * [find_path 寻找和为目标值的路径]
 * @param root   [description]
 * @param target [description]
 *
 * 思路：  深搜   成功的条件 在叶子节点时，路径的和为目标值， 打印出该路径
 *
 * vector的使用    vector<int>::iterator iter = path.begin();   for(;iter!=path.end(); ++iter)   *iter;
 *
 * 传引用的方式
 *
 * 深搜的退出条件，如果题意修改为只打印合适的一组即可    可以通过返回值来判断  如果已经打印完，返回true
 * 
 * 
 */
void find_path(BinaryTreeNode *root, int target){

	if(root == NULL || target <= 0)
		return;

	vector<int> path;
	int curr = 0;

	compute(root,path,0,target);

}

void compute(BinaryTreeNode *root, vector<int> & path, int curr, int target){

	int curr = curr + root->value;
	path.push_back(root->value);

	if( target == curr && root->left == NULL && root->right == NULL ){
		// while(path.size() > 1){
		// 	printf("%d ", path.front());
		// 	path.pop();
		// }
		// printf("%d\n", path.front());
		// path.pop();
		
		vector<int>::iterator iter = path.begin();
		for(;iter!=path.end();++iter)
			printf("%d ", *iter);
		printf("\n");

		
	}

	if(root->left != NULL)
		compute(root->left, path, curr, target);

	if(root->right != NULL)
		compute(root->right, path, curr,target);

	path.pop_back(root->value);

}