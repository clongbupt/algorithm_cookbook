typedef struct _binary_tree_node_t{
	binary_tree_node_t *left;
	binary_tree_node_t *right;
	int value;
}bt_node;

// 递归方法
void pre_order_r(const bt_node *root, vector<int> path){
	if(root != NULL){
		path.push_back(root->value);
		pre_order_r(root->left, path);
		pre_order_r(root->right, path);
	}
}

void in_order_r(const bt_node * root, vector<int> path){
	if(root != NULL){
		in_order_r(root->left, path);
		path.push_back(root->value);
		in_order_r(root->right, path);
	}
}

void post_order_r(const bt_node * root, vector<int> path){
	if(root != NULL){
		post_order_r(root->left, path);
		post_order_r(root->right, path);
		path.push_back(root->value);
	}
}

// 先序遍历的非递归版   重点是用栈来存储节点， 先访问根节点 再一次将右左子树压入栈中
void pre_order(const bt_node * root, vector<int> path){
	if(root == NULL)
		return;

	const bt_node *p;

	stack<bt_node *> s;

	s.push(root);

	while( !s.empty() ){
		p = s.top();
		s.pop();

		path.push_back(p->value);

		if(p->right)
			s.push(p->right, path);

		if(p->left)
			s.push(p->left, path);
	}
}

// 栈  先遍历到最左端, 然后判断p是否为空, 是空，则弹出访问当前节点，并指向右子树
void in_order(const bt_node * root, vector<int> path){

	if(root == NULL)
		return;

	const bt_node * p;

	stack<bt_node *> s;

	p = root;

	while ( !s.empty() || p != NULL ){
		if ( p != NULL ){
			s.push(p);
			p = p->left;
		}else{
			p = s.top();
			s.pop();

			path.push_back(p->value);

			p = p->right;
		}

	}
}

void post_order(const bt_node * root, vector<int> path){

	if (root == NULL)
		return;

	const bt_node * p;

	stack<bt_node *> s;

	p = root; 

	do {
		while(p != NULL) { /* 往左下走 */
			s.push(p);
		    p = p->lchild;
		}
		
		q = NULL;
		while(!s.empty()) {
			p = s.top();
			s.pop();
			/* 右孩子不存在或已被访问,则访问当前节点 */ 
			if(p->rchild == q) {
		        path.push_back(p->value);
		        q = p; 
				/* 保存刚访问过的结点 */ 
			} else {
				/* 当前结点不能访问,需第二次进栈 */ 
				s.push(p);
				/* 先处理右子树 */
				p = p->rchild;
		￼		break; 
			}
		}
    
    }while(!s.empty());
}

// 按层遍历

#include "queue"
void level_order(const bt_node * root, vector<int> path){
	if(root != NULL)
		return;

	const bt_node * p;

	queue<bt_node *> q;

	q.push(root);

	while( !q.empty() ){
		p = q.front();
		q.pop();

		path.push_back(p->value);

		if( p->left )
			q.push(p->left);

		if( p->right )
			q.push(p->right);
	}
}

// 二叉树重建

// 给定前序和中序序列, 输出后序序列

void build_post(const char * pre, const char * in, const int n, char *post){

	if(n <= 0) return;

	int left_len = strchr(in, pre[0]) - in;   // strchr(in,pre[0]) 取得当前根节点在中序中的位置
	// 然后求的左子树的长度

	build_post(pre+1, in, left_len, post);
	build_post(pre+left_len+1, in+left_len+1, n-left_len-1, post+left_len);

	post[n-1] = pre[0];
}

typedef struct _binary_tree_node_t{
	_binary_tree_node_t * left;
	_binary_tree_node_t * right;
	int value;
}bt_node;


// 树的重建
void rebuild(const char * pre, const char * in, const int n, bt_node **root){

	if (n <= 0 || pre == NULL || in == NULL)
		return;

	*root = (bt_node*)malloc(sizeof(bt_node));

	(*root)->value = pre[0];
	(*root)->left = (*root)->right = NULL;

	int left_len = strchr(in, pre[0]) - in;

	rebuild(pre+1, in, left_len, &((*root)->left));
	rebuild(pre+left_len+1, in+left_len+1, n-left_len-1, &(*(root)->right));

}

// Lowest common accestor of a binary tree

// Lowest common accestor of a binary tree

bt_node * LCA (bt_node * root, bt_node * p, bt_node * q){
	if (!root) return NULL;

	if ( root == p || root == q ) return root;

	bt_node * L = LCA(root->left, p, q);
	bt_node * R = LCA(root->right, p, q);

	if (L && R) return root;
	return L ? L : R; 
}

bt_node * get_common_accestor (bt_node * root, bt_node * p, bt_node * q){
	vector<bt_node *> path1;
	get_path(root, p, path1);

	vector<bt_node *> path2;
	get_path(root, q, path2);

	return get_common_node(path1, path2);
}

bool get_path (bt_node * root, bt_node * target, vector<bt_node *> &path){

	if (root == target) 
		return true;

	bool found = false;

	path.push_back(root);

	if (root->left)
		found = get_path(root->left, target, path);

	if (!found && root->right )
		found = get_path(root->right, target, path);

	if(!found){
		path.pop_back(root);
		return false;
	}

	return true;

}

bt_node * get_common_node (vector<bt_node * > path1, vector<bt_node * > path2 ){

	vector<bt_node *>::iterator it1;
	it1 = path1.begin();

	vector<bt_node *>::iterator it2;
	it2 = path2.begin();

	while(*it1 != it1.end() && *it2 != it2.end() && *it1 == *it2){
		it1 ++;
		it2 ++;
	}

	if (*it1 == it1.end() )
		return *it1;
	if (*it2 == it2.end() )
		return *it2;
	if (*it1 != *it2){
		it1--;
		return *it1;
	}
}


// Two sum in a binary tree

// Minimum depth of a binary tree

// Symmetric tree

// 包含两种  判断和生成

bool is_symmetric_tree(bt_node * root){
	if ( !root ) return true;

	return compute(root->left, root->right);

}

bool compute(bt_node * l_node, bt_node * r_node){
	if (l_node == NULL && r_node == NULL) return true;
	if (l_node == NULL || r_node == NULL) return false;

	if (l_node->value != r_node->value) return false;
	
	return compute(l_node->right,r_node->left) && compute(l_node->left, r_node->right);
}


// TODO
bt_node * generate_symmetric_tree(bt_node * root){
	if (root == NULL) return NULL;

	return compute(root->left, root->right);

}

bt_node * compute (bt_node * l_node, bt_node * r_node){
	


	bt_node * root;


}

// Find closest value of a BST

bt_node * closest_bst ( bt_node * root, int val ){
	if ( root == NULL ) return NULL;

	if ( root->val ) return root;

	if ( val < root->value ){
		if ( !root->left ) return root;
		p = closest_bst(root->left, val);
		return ( abs(p->value) > abs(root->value) ? root->value : p->value );
	} else {
		if ( !root->right ) return root;
		p = closest_bst(root->right, val);
		return ( abs(p->value) > abs(root->value) ? root->value : p->value );
	}
}

// Find k nearest neightbours in BST

// Validate BST

const int INT_MIN 0x7fffffff;
const int INT_MIN 0x80000000;

bool check_bst(bt_node * root){
	return check(root, INT_MIN, INT_MAX);
}

bool check(bt_node * root, int min, int max){
	if ( !root ) return true;

	if ( root->value <= min || root->value >= max ) return false;

	if( check(root->left,min, root->value) && check(root->right, root->value, max) )
		return true;

	return false;
}

// Recover BST  有两个节点有问题， 找出来并还原



// Convert Sorted array or linked list to BST

// 思路: 取中间值，递归构造

bt_node * sorted_array_to_bst ( vector<int> & num){
	return build(num, 0, len-1);
}

bt_node * build( vector<int> & num, int beg, int end){
	int mid;
	if(beg <= end){
		mid = beg + (end - beg) >> 1;

		bt_node * root = new bt_node();
		root->value = num[mid];
		root->left = build(num, beg, mid-1);
		root->right = build(num, mid+1, end);
		return root;
	}
}

//思路: 仿照中序遍历的思路来做  原因是链表不能随机访问

bt_node * sorted_list_to_bst( list_node * head){
	int n = 0;
	list_node * tmp = head;
	while(tmp){
		n++;
		tmp = tmp->next;
	}

	return build(head, 0, n-1);
}

bt_node * build(list_node * list, int beg, int end){
	int mid;
	if (beg <= end){
		mid = beg + (end - beg) >> 1;

		bt_node * root = (bt_node *)malloc(sizeof(bt_node));
		root->left = build(list, beg, mid-1);
		root->value = list->value;

		list = list->next;
		root->right = build(list, mid+1, end);
		return root;
	}
}

// Flatten binary tree to linked list


// binary tree maximum path sum

// Serialization / Deserialization of a binary tree

// 思路: 先序遍历的变形

// subtree

bool subtree(bt_node * t1, bt_node * t2){
	if ( t2 == NULL ) return true;
	if ( t1 == NULL ) return false;

	if ( t1->value == t2-> value)
		return check(t1->left, t2->left) && check(t1->right, t2->right);
	else
		return subtree(t1->left,t2) || subtree(t1->right, t2);
}

bool check(bt_node * t1, bt_node * t2){
	if ( t1 == NULL && t2 == NULL) return true;
	if ( t1 == NULL || t2 == NULL) return false;

	if (t1->value != t2->value) return false;

	return check(t1->left, t2->left) && check(t1->right,t2->right);
}

// path sum

vector<vector<int> > get_path(bt_node * root, int sum){
	vector<vector<int> > res;
	vector<int> temp;
	compute(root, sum, temp, res);
	return res;
}

void compute (bt_node * root, int sum, vector<int> &temp, vector<vector<int> > &res){
	if (gap == 0){
		res.push_back(temp);
		return;
	}

	if (gap < 0)
		return;

	bool found = false;

	temp.push_back(root);

	if (root->left)
		compute(root->left,sum-root->value,temp,res);

	if (root->right)
		compute(root->right, sum-root->value, temp, res);

	temp.pop_back(root);

}

// balanced binary tree

bool is_balanced_binary_tree(bt_node * root){

	return check(root,0);
}

bool check(bt_node * root, int &height){

	if( !root ){
		height = 0;
		return true;
	}
	int l_height = 0, r_height = 0;
	if ( check(root->left, l_height) && check(root->right, r_height) ){
		int temp = l_height - r_height;
		if (temp >= -1 && temp <= 1){
			height = l_height - r_height;
			return true;
		}
	}

	return false;
}
// build double linked list from BST