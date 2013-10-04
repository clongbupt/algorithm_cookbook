// Leetcode 题集

//Balanced Binary Tree    Given a binary tree, determine whether it is height-balanced

// 思路: 是否需要考虑return false 时返回height高度
// 
bool is_balanced_binary_tree(treeNode * root){

	return check(root,0);
}

bool check(treeNode * root, int & height){
	if(root == NULL)
	{
		height = 0;
		return true;
	}

	int l_height, r_height;
	if( get_height(root->left, l_height) && get_height(root->right,r_height) ){
		if( abs(l_height-r_height) < 1 ){
			height = (l_height > r_height ? l_height : r_height) + 1;
			return true;
		}
	}

	return false;
}

// Binary Tree Inorder Traversal     
// Given a binary tree, return the inorder traversal of its nodes' values

vector<int> inorder (treeNode * root){
	if( !root){
		vector<int> res;

		if(root->left)
			inorder(root->left);
		res.push_back(root->value);
		if(root->right)
			inorder(root->right);
	}
}

vector<int> inorder_no_recursive(treeNode * root){
	
	if( !root ){

		vector<int> res;
		stack<treeNode *> s;

		treeNode * q = root;
		while( !q || !s.empty() ){
			if(!q){
				s.push(q);
				q = q->left;
			}else{
				q = s.top();
				s.pop();

				res.push_back(q->value);

				q=q->right;
			}
		}		
	}
	
	return NULL;

}



// Binary Tree Level Order Traversal    广度优先遍历

vector<int> level_order_travel( treeNode * root){
	if( !root ) return;

	vector<int> res;

	queue<treeNode *> q;
	q.push(root);

	treeNode * tmp;
	while( !q.empty() ){
		tmp = q.top();
		q.pop();

		res.push_back(tmp->value);

		if(tmp->left)
			q.push(tmp->left);
		if(tmp->right)
			q.push(tmp->right);
	}

}

// Binary Tree Maximum Path Sum   
// Given a binary tree, find the maximum path sum   
// The path may start and end at any node in the tree

vector<int> get_maximum_sum_path(treeNode * root){
	vector<int> res;


}


// Binary Tree Zigzag Level Order Traversal    
// return the Zigzag(锯齿) level order traversal of its nodes' values

vector<vector<int>> zigzag_level_order_travel(treeNode * root){
	if( !root ) return NULL;

	vector<vector<int>> res;
	dqueue<int> level_res;

	queue<treeNode *> q;
	q.push(root);

	treeNode * tmp;
	int flag = 1;
	while( !q.empty() ){
		leve_res.clear();
		for(int i = q.size(); i > 0; i --){
			tmp = q.front();
			q.pop();
			
			if(flag)
				level_res.push_back(tmp->value);
			else
				leve_res.insert(tmp->value);

			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
		}
		res.push_back(level_res);
		flag = 1 - flag;
	}

	return res;

}

// Construct Binary Tree from Inorder and Postorder Traversal 

treeNode * construct_binary_tree (vector<int> inorder, vector<int> postorder){

	return build(inorder, postorder, 0, 0, inorder.size());
}

treeNode * build (vector<int> inorder, vector<int> postorder, int in_start, int post_start, int len){

	int left_len;
	for(int i=in_start; i<in_start+len; i++)
		if(inorder[i] == postorder[post_start+len-1])
			left_len = i;

	treeNode * root = (treeNode *)malloc(sizeof(treeNode));

	root->value = postorder[post_start+len-1];

	root->left = build(inorder, postorder, in_start, post_start, left_len);
	root->right = build(inorder, postorder, in_start+left_len+1, post_start+left_len, inorder.size()-left_len-1);

	return root;
}

// Construct Binary Tree from Preorder and Inorder Traversal

treeNode * construct_binary_tree(vector<int> preorder, vector<int> inorder){
	return build(preorder, inorder, 0, 0, inorder.size());
}

treeNode * build (vector<int> preorder, vector<int> inorder, int pre_start, int in_start, int len){

	int left_len;
	for(int i=in_start; i<in_start+len; i++)
		if(inorder[i] == preorder[pre_start])
			left_len = i;

	treeNode * root = (treeNode *)malloc(sizeof(treeNode));

	root->value = preorder[pre_start];

	root->left = build(preorder, inorder, pre_start+1, in_start, left_len);
	root->right = build(preorder, inorder, pre_start+left_len+1, in_start+left_len+1, inorder.size()-left_len-1);

	return root;
}

// Convert Sorted Array to Binary Search Tree      
// Array is Ascending Order, Convert it into height balanced Tree

treeNode * convert_array_to_binary_search_tree(vector<int> a){
	if ( !a || a.empty() ) return NULL;
	
	return build(a, 0, a.size()-1);
}

treeNode * build(vector<int> a, int left, int right){
	int mid;

	if(left <= right){
		mid = left + (right-left)>>1;

		treeNode * root = (treeNode *)malloc(sizeof(treeNode));

		root->value = mid;
		root->left = build(a, left, mid-1);
		root->right = build(a, mid+1, right);

		return root;
	}
}


// Convert Sorted List to Binary Search Tree      

treeNode * convert_list_to_bst(listNode * head){
	if ( !head ) return NULL;
	
	int n = 0;
	listNode * tmp = head;
	while(tmp){
		n++;
		tmp = tmp->next;
	}

	return build(head, 0, n-1);
}

treeNode * build(listNode * head, int left, int right){
	
	int mid;
	if (left <= right){
		mid = left + (right - left) >> 1;

		treeNode * root = (treeNode *)malloc(sizeof(treeNode));
		root->left = build(head,left, mid-1);

		root->value = head->value;
		head = head->next;
		
		root->right = build(head,mid+1,right);

	}


}

// Decode Ways  A message from A-Z is being encoded to numbers using the following mappings : 
// A -> 1 B -> 2 ... Z -> 26   ,    '12'  may be 'AB' or 'L'   
// Compute the total num of ways to decode it     

// Hint : dp  dp[i] = dp[i-1] + dp[i-2]

int decode_ways(vector<int> a){
	int len = a.size();

	int dp[len+1];
	dp[0] = 1;
	dp[1] = 1;
	int num = 0;
	for(int i = 2; i<=len; i++)
		if(a[i-2]<2 || (a[i-2]==2 &&a[i-1]<=6) )
			dp[i] = dp[i-1] + dp[i-2];
		else
			dp[i] = dp[i-1];

	return dp[len];
}

// Distinct Subsequences    
// Given a String S and a String T, count the number of distinct subsequence of T in S
// A subsequence of a String is a new string which is formed from the original string 
// by deleting some(can be none) of the characters 
// without disturbing the relative positions of the remaining characters.

// Hint : dp   dp[i][j]   T中i个字符出现在S中前j个字符中的个数

int get_distinct_subsequence_num(string S, string T){
	int lens = S.length();
	int lent = S.length();

	int dp[lens+1][lent+1];

	for(int i=0; i<lent; i++)
		for(int j=0; j<lens; j++)
			if(T[i] == S[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;

			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}

	return dp[lens][lent];
}

// Flatten Binary Tree to Linked List     Just Like Preorder

listNode * flatten_binary_tree(treeNode * root){

	if ( !root ) return NULL;

	listNode * dummy = (listNode *)malloc(sizeof(listNode));

	build ( &dummy, root);

	return dummy->next;
}

void build(listNode ** head, treeNode * root){

	if(root->left)
		build(head, root->left);

	(*head)->next = root;
	(*head) = (*head)->next;

	if(root->right)
		build(head, root->right);

}

// Gray Code   Gray code is a binary numeral system where two successive values differ in only one bits
//Print the sequence of gray code

vector<vector<int>> generate_gray_code(int n ){
	vector<vector<int>> res;
	vector<int> tmp(n,0);
	build (n,0,tmp,res);
}

void build(int n, int i, vector<int> tmp, vector<vector<int>> res){
	if(i == n){
		res.push_back(tmp);
		return;
	}

	build(n,i+1,tmp,res);

	tmp[i] = tmp[i] == 0 ? 1 : 0;

	build(n,i+1,tmp,res);
}

// Interleaving String   
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2
// Hint : DP   determine whether s1[i] and s2[j] can form s3 or not  
// s1的前i个字符和s2的前j个字符是否能组成s3

bool interleaving_string(string s1, string s2, string s3){

	int len1 = s1.size();
	int len2 = s2.size();

	bool dp[len1+1][len2+1];
	memset(dp, false, sizeof(dp));

	for(int i=0; i<len1; i++)
		if(s1[i] == s3[i])
			dp[0][i+1] = dp[i];

	for(int i=0; i<len2; i++)
		if(s2[i] == s3[i])
			dp[i+1][0] = dp[i][0];

	dp[0][0] = true;
	for(int i=1; i<=len1; i++)
		for(int j=1; j<=len2; j++){
			if (s1[i] == s3[i])
				dp[i][j] = dp[i][j-1] || dp[i][j];
			if (s2[j] == s3[j])
				dp[i][j] == dp[i-1][j] || dp[i][j];
		}

	return dp[len1][len2];

}


// Largest Rectangle in Histogram    
// Given n itegers representing the histogram(直方图) bar height where the width of each bar is 1, 
// find the area of largest rectangle in the histogram

// Input : 2 1 5 6 2 3    Output : 10

int largest_rectangle_in_histogram(vector<int> h){

	int res = 0;

	stack<int> s;

	h.push_back(0);

	for(int i=0; i<h.size(); i++){
		if(s.empty() || h[i] > h[s.top()])
			s.push(i);
		else{
			int tmp = s.top();
			s.pop();
			int area = h[tmp] * ( s.empty() ? i : i-s.top()-1);
			res = res > area ? res : area;
		}
	}

	return res;

}

// Longest Common Prefix   Using Trie data structure

string longest_common_prefix(vector<string> &strs){

	string res;

	int row = strs.size();

	int minLen = 0x7fffffff;
	for(int i=0; i<row; i++)
		minLen = minLen < strs[i].size() ? minLen : strs[i].size();

	bool flag = true;
	for(int j=0; j<minLen; j++){
		char ch = strs[0][j];
		int i=0;
		for(; i<row && flag; i++){
			if(strs[i][j] != ch){
				flag = false;
				break;
			}
		}
		if(i==row && flag ){
			res += ch;
		}
	}

	return res;

}

// Longest Consecutive Sequence  
// Given an unsorted array of integers, find the length of the longest consecutive(连续的) elements sequence    
// the Time Complexity should be O(n)

int longest_consecutive_sequence(vector<int> a){

	sort(a.begin(), a.end());

	int left = right = 0;
	int max = ox80000000;

	for(int i=1; i<a.size(); i++)
	{
		if( a[i] == a[right]+1 )
			right++;
		else{
			max = max > (right-left+1) ? max : (right-left+1);
			left = i;
			right = left;
		}
	}

	return max;
}

// Maximal Rectangle   Given an 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all 1's in this area 

int get_maximal_rectangle(vector<vector<int>> matrix){

	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<int>> height(n,vector<int>(m+1,0));

	for(int i=0; i<matrix.size(); i++)
		for(int j=0; j<matrix[i].size(); j++)
			if(matrix[i][j] == '0')
				height[i][j] = 0;
			else{
				height[i][j] = i == 0 ? 1 : height[i-1][j];
			}

	int max_area = 0;
	int area;
	for(int i=0; i<matrix.size(); i++){
		area = compute(height[i]);
		if (max_area < area)
			max_area = area;
	}

	return max_area;
}

int compute(vector<int> h){

	stack<int> s;
	int max_area;
	for(int i=0; i<h.size(); i++){
		if(s.empty() || h[i] > h[s.top()])
			s.push(i);
		else{
			int tmp = s.top();
			s.pop();
			int area = h[tmp] * (s.empty() ? i : i-s.top()-1);
			max_area = max_area > area ? max_area : area;
		}
	}

	return area;
}

// Merge Two Sorted Arrays     A has enough spaces for merging B

vector<int> merge_two_sorted_arrays(vector<int> a, vector<int> b, int usedLena){

	int lena = a.size();
	int lenb = b.size();

	int idx = lenb + usedLena -1;
	int i = usedLena - 1;
	int j = lenb -1;
	while( i >= 0 && j >= 0 ){
		if(a[i] > a[j]){
			a[idx--] = a[i--];
		}else
			a[idx--] = b[j--];
	}

	while( j>= 0 ){
		a[idx--] = b[j--];
	}

	return a;

}

// Minimum Depth of Binary Tree   Given a binary tree, find its minimum depth
// The minimum depth is the number of nodes along the shortest path 
// from the root node down to the nearest leaf node

int minimum_depth(treeNode * root){
	if( !root ) return 0;
	if ( !root->left || !root->right ) return 1;

	return min( compute(root->left) +1, compute(root->right)+1 );
}

// Partition List      Part of the Quick Sort

//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.

int partition(listNode * head, int x){
	
	listNode * dummy = (listNode *)malloc(sizeof(listNode));

	dummy->next = head;

	ListNode * prev_left = dummy;
	ListNode * left = prev->next;

	while( !left && left->value < x ){
		prev_left = left;
		left = left->next;
	}

	ListNode * prev_right = left;
	ListNode * right = left->next;

	while( !right){
		if ( right->value < x ){
			ListNode * tmp = right->next;

			right->next = prev_left->next;
			prev_left->next = prev_left->next;
			prev_right->next = left;
			left->next = tmp;

			right = tmp;
		}else{
			prev_right = right;
			right = right->next;
		}
	}

}

// Pascals Triangle   Given numRows, generate the first numRows of Pascal's triangle   

vector<int> generate_pascal_triangle(int n){
	vector<int> res(n, 0);

	res[0] = 1;

	for(int i=1; i<=n; i++){
		for(int j=i; j>0; j--){
			if (j==i) res[j] = 1;
			else
				res[j] = res[j-1] + res[j];
		}
	}

	return res;

}

// Path Sum1   Given a binary tree, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given one    Hint : dfs

int path_sum(treeNode * root){
	if ( !root ) return 0;

	return compute(root, 0);
}

int compute(treeNode * root, int val){
	if ( !treeNode->left && !treeNode->right )
		return 10*val + root->value;

	return compute(root->left,10*val+root->value) + compute(root->right, 10*val+root->value);
}


// Computing Next Right Pointers in Each Node     按层遍历
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

struct listTreeNode{
	listTreeNode * left;
	listTreeNode * right;
	listTreeNode * next;
	int value;
};

listTreeNode * compute_next_right_pointer(listTreeNode * root){
	queue<listTreeNode *> q;
	q.push(root);

	while( !q.empty() ){
		int len = q.size();
		for(int i=0; i<len; i++){
			ListTreeNode * node = q.front();
			q.pop();

			if( i== num-1 )
				node->next = NULL;
			else
				node->next = q.front();

			if( node->left )
				q.push( node->left );
			if( node->right )
				q.push( node->right );
		}
	}

	return root;
}

// Recover the Binary Search Tree   
// Two elements of a binary search tree are swapped by mistake    
// O(n) is ok   But there is a solution that only cost contant spaces

// Hint : 主要是不会

treeNode * recover_bianry_search_tree(treeNode * root){
	if ( !root ) return;
	vector<int> nums;
	vector<treeNode *> nodes;

	compute(root, nums, nodes);

	sort(nums.begin(), nums.end());

	for(int i=0; i<nums.size(); i++)
		nodes[i]->value = nums[i];

	return root;
}

void compute(treeNode * root, vector<int> & nums, vector<treeNode *> & nodes){
	if ( node == 0 ) return;

	compute(root->left, nums, nodes);
	nums.push_back(root->value);
	nodes.push_back(root);
	compute(root->right, nums, nodes);
}

// Restore IP addresses   
// Given a string containing only digits, restore it by returning all possible valid IP addresses combinations.

vector<string> restore_ip_address(string str){
	vector<string> res;
	string tmp;
	dfs(str,0,0,tmp,res);
}

void dfs(string str, int start, int step, string & tmp, vector<string> res){
	if (step == 4 &7 start == str.size()){
		tmp.resize(tmp.size()-1);   // 去掉后面的点
		res.push_back(tmp);
	}

	if(str.size()-start > (4-step)*3) return;
	if(str.size()-start < 4-step) return;

	int num = 0;
	for(int i=start; i<start+3; i++){
		num = num*10 + str[i]-'0';
		tmp += str[i];
		if(num<256)
			dfs(str,i+1,step+1,tmp+'.', res);
		
		// 后面为零则不必计算
		if(num == 0)
			break;
	}
}

// Reverse Linked List    注意头部为空的判断

listNode * reverse_list(listNode * head){
	if( !head || !head->next ) return NULL;

	listNode * dummy = (listNode *)malloc(sizeof(listNode));
	dummy->next = head;

	listNode * prev = head;
	listNode * cur = head->next;

	while( !cur ){
		prev->next = cur->next;
		cur->next = dummy->next;
		dummy->next = cur;
		cur = prev->next;
	}

	return dummy->next;
}

// Same Tree    Determine whether two binary trees are the same or not?

bool is_same_tree(treeNode * r1, treeNode * r2){
	if ( !r1 && !r2 ) return true;
	if ( !r1 || !r2 ) return false;

	return is_same_tree(r1->left, r2->left) && is_same_tree(r1->right, r2->right);
}

// 1.1 Subsets      
// Given a collection of integers that might contain duplicates, return all possible subsets

vector<vector<int>> generate_subset_may_contain_duplicates(vector<int> a){

	vector<vector<int>> res;
	vector<int> tmp;

	dfs(a, 0, tmp, res);

	return res;
}

void dfs(vector<int> a, int start, vector<int> & tmp, vector<vector<int>> & res){

	res.push_back(tmp);

	for(int i=start; i<a.size(); i++){
		int ok = 1;
		int c1 = c2 = 0;
		for(int j=0; j<a.size(); j++) if(a[j] == a[i]) c1++;
		for(int j=0; j<i; j++){
			if(a[i] == a[j]){
				c2++;
				if(c2 > c1){
					ok = 0;
					break;
				}
			}
		}

		if(ok){
			tmp[start] = a[i];
			dfs(a, start+1, tmp, res);
		}
	}
}

// 1.2 Given a set of distinct integers, return all possible subsets

vector<vector<int>> generate_subset_may_contain_duplicates(vector<int> a){

	vector<vector<int>> res;
	vector<int> tmp;

	dfs(a, 0, tmp, res);

	return res;
}

void dfs(vector<int> a, int start, vector<int> & tmp, vector<vector<int>> & res){

	res.push_back(tmp);

	for(int i=start; i<a.size(); i++){
		int ok = 1;
		for(int j=0; j<i; j++){
			if(a[i] == a[j]){
				ok = 0;
				break;
			}
		}

		if(ok){
			tmp[start] = a[i];
			dfs(a, start+1, tmp, res);
		}
	}
}

// Surrounded Regions  
// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'. 
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

vector<vector<int>> surrounded_regions(vector<vector<int>> m){
	int row = m.size();
	int col = m[0].size();

	for(int j=0; j<col; j++)
		if(m[0][j] == 'O')
			compute(m,0,j);

	for(int j=0; j<col; j++)
		if(m[row-1][j] == 'O')
			compute(m,row-1,j);

	for(int i=0; i<row; i++)
		if(m[i][0] == 'O')
			compute(m, i, 0);

	for(int i=0; i<row; i++)
		if(m[i][col-1] == 'O')
			compute(m, i, col-1);

	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			if(m[i][j] == 'O')
				m[i][j] = 'X';

	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			if(m[i][j] == '#')
				m[i][j] = 'O';

	return m;

}

void compute(vector<vector<int>> m, int x, int y){
	if (x < 0 || x >= row || y < 0 || y <= col)
		return;

	if (m[x][y] == 'O')
		m[x][y] = '#';

	compute(m, x-1, y);
	compute(m, x+1, y);
	compute(m, x, y-1);
	compute(m, x, y+1);
}



// Symmetric Tree  Given a binary tree, check whether it is a mirror of itself

bool is_symmetric_tree(treeNode * t1, treeNode * t2){
	if( !t1 && !t2 ) return true;
	if( !t1 || !t2 ) return false;

	return is_symmetric_tree(t1->left, t2->right) && is_symmetric_tree(t1->right, t2->left);
}



// triangle   Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

int minimum_path_sum_triangle(vector<vector<int>> a){
	int n = a.size();

	int dp[n][n];
	memset(dp, 0, sizeof(dp));

	for(int i=0; i<n; i++)
		dp[n-1][i] = a[i][j]

	for(int i=n-2; i>=0; i--){
		for(int j=0; j<i; j++)
			dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + a[i][j];
	}

	return dp[0][0];
}



// Unique binary search tree   Given n, how many structurally unique BST's that store values 1 ... n   Hint:c[n] = c[n-1]*c[0] + c[n-2]*c[1] ... + c[1]*c[n-2] + c[0][n-1];

int unique_binary_search_tree(int n){
	int sum;

	int dp[n+1];
	memset(dp,1,sizeof(dp));

	int j;
	for(int i=2; i<=n; i++){
		for(int j=i-1; j>=0; j--)
			dp[i] += dp[j]*dp[i-j-1];
	}


	return dp[n];
}


// Unique binary search tree    Given n, print all the unique binary search trees



// Valid Palindrome    
// Given a string, determine whether it is a palindrome, considering only alphanumeric characters and ingoring cases    
// Hint : Palindrome a pointer from left, another pointer from right

bool is_valid_palindrome(string s){
	if( !s || s.empty() ) return true;

	int left = 0;
	int right = s.size()-1;

	while(left < right){
		if(s[left] != s[right])
			return false;
		left++;
		right--;
	}

	return true;
}

// validate binary search tree     
// Hint : recursion, two args min and max to distinguish that whether the value of root is less than the max and more than the min

bool validate_binary_search_tree(treeNode * root){
	return check(root, 0x80000000, 0x7fffffff);
}

bool check(treeNode * root, int min, int max){
	if ( !root ) return true;

	return check(root->left, min, root->value) && check(root->right, root->value, max);
}

// Best Time Buy and Sell   
// Given an array for which the ith element is the price of a given stock on day i. 
// If you were permitted to complete at most one trasaction(buy one and sell one), design an algorithm to find the maximum profit

// 没有交易限制
int best_time_buy_and_sell1(vector<int> stocks){
	
	int sum = 0;

	for(int i=0; i<stocks.size()-1; i++)
		if(stocks[i] < stocks[i+1])
			sum += stocks[i+1] - stocks[i];

	return sum;
}	

// 只能做一次交易
int best_time_buy_and_sell2(vector<int> stocks){

	int len = stocks.size();
	int max_sell = stocks[len-1];

	int profits = 0;
	for(int i=len-2; i>=0; i--){
		if(stocks[i] > max_sell){
			max_sell = stocks[i];
		}
		if ( profits < max_sell - stocks[i])
			profits = max_sell - stocks[i];
	}

	return profits;
}

// 交易两次
int best_time_buy_and_sell3(vector<int> stocks){

	int n = stocks.size();

	int left[n], right[n];

	memset(left, 0, sizeof(left));
	memset(right, 0, sizeof(right));

	int min_buy = stocks[0];
	for(int i=1; i<n; i++){
		if(min_buy > stocks[i])
			min_buy = stocks[i];

		int tmp = stocks[i] - min_buy;
		if( left[i] < tmp)
			left[i] = tmp;
	}

	int max_sell = stocks[n-1];
	for(int i=n-2; i>=0; i++){
		if(max_sell < stocks[i])
			max_sell = stocks[i];
		int tmp = max_sell - stock[i];
		if( right[i] < tmp )
			right[i] = tmp;
	}

	int res = right[0];
	for(int i=1; i<n-1; i++){
		int tmp = left[i] + right[i+1];
		if ( res < tmp )
			res = tmp;
	}

	if ( res < left[n-1] )
		res = left[n-1];

	return res;
}

// palindrome Partition   
// Given a string s, partition s such that every substring of the partition is a palindrome. 
// return all possible palindrome partitioning of s

vector<vector<string>> palindrome_partition(string s){

	vector<vector<string>> res;
	vector<string> tmp; 

	dfs(s, 0, tmp, res);

	return res;
}

void dfs(string s, int start, vector<string> tmp, vector<vector<int>> res){
	if(start == s.size()-1){
		res.push_back(tmp);
	}

	for(int i=start; i<s.size()-1; i++){
		if(is_palindrome(s,start,i)){
			tmp.push_back(s.substr(start,i-start+1));
			dfs(s,i+1,tmp,res);
		}
	}
}

bool is_palindrome (string s, int start, int end){
	while(start < end){
		if( s[start] != s[end] )
			return false;
		start++;
		end--;
	}
	return true;
}



// Palindrom Partition   
// Given a string s, partition s such that every substring of the partition is a palindrom. 
// Return the minimum cuts needed for a palindrome partition.
// Hint : dp[i] 表示从i~n的最小cut数

int min_cut_of_palindrome_partition(string s){

	int n = s.size();

	int dp[n+1];
	memset(dp, 0, sizeof(dp));

	bool p[n][n];
	memset(p, false, sizeof(p));

	for(int i=0; i<n; i++)
		dp[i] = n-i;

	for(int i=0; i<n; i++)
		p[i][i] = true;

	for(int i=n-1; i>=0; i--){
		for(int j=i; j<n; j++)
			if( s[i] == s[j] && (j-i<2 || p[i+1][j-1]) ){
				p[i][j] = true;
				dp[i] = dp[i] < dp[j+1] + 1 ? dp[i] : dp[j] + 1;
			}
	}

	return dp[0]-1;
}

// Scramble String       
// Given a string s1, we may represent is has a binary tree by partitioning it to two non-empty Substring recursively.  
// Given two strings s1 and s2, determine if s2 is a scramble string of s1.  
// Hint : 用递归的方式分别计算左右子树

bool scramble_string (string s1, string s2){
	if (s1.size() != s2.size() ) return false;

	int ch[256];

	for(int i=0; i<s1.size(); i++)
		ch[s1[i]] ++;

	for(int i=0; i<s2.size(); i++)
		ch[s2[i]] --;

	for(int i=0; i<256; i++)
		if(ch[i] != 0)
			return false;

	bool res;
	int n = s1.size();
	for(int i=1; i<n; i++){
		res = scramble_string(s1.substr(0,i),s2.substr(0,i)) && scramble_string(s1.substr(i,n-i), s2.substr(i,n-i));

		res = res && scramble_string(s1.substr(0,i),s2.substr(i,n-i)) && scramble_string(s1.substr(i,n-i), s2.substr(0,i));
	}

	return res;
}

// sumRootLeaf     
// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// find the total sum of all root-to-leaf numbers
// Hint: 深度遍历

int sub_root_leaf(treeNode * root){
	if ( !root ) return 0;

	return compute(root,0);
}

int compute(treeNode * root, int value){
	if( !root ) return 0;

	int value = value*10 + root->value;

	if ( !root->left && !root->right ) return value;

	return compute(root->left, value) + compute(root->right, value);
}

// wordLadderII    return all the valiable results
// Given two words(start and end), and a dictionary, find all shortest transformation sequence from start to end.       
// Hint: 海明距离

// wordLadder    return the total num     参考career cup



// Anagrams    Given an array of Strings, return all groups of strings that are anagrams

vector<string> anagrams(vector<string> &strs){
	map<string, int> m;
	vector<string> res;

	res.clear();

	for(int i=0; i<strs.size(); i++){
		string s = strs[i];
		sort( s.begin(), s.end() );

		if( m.find(s) == m.end() ){
			m[s] = i;
		}
		else{
			if( m[s] >= 0){
				int idx = m[s];
				res.push_back(strs[idx]);
				m[s] = -1;
			}
			res.push_back(strs[i]);
		}
	}

	return res;
}

// Climbing Stairs  爬楼梯  Hint : fibonnaci

// 递归方法
int fibonnaci(int n){
	if( n==0 || n==1 ) return 1;

	return fibonnaci(n-2) + fibonnaci(n-1);
}

// 循环方法
int fibonnaci2(int n){
	if( n==0 || n==1 ) return 1;

	int a = 1, b = 1, c;
	for(int i=2; i<=n; i++){
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

// Combination Sum 2     
// Given a set of candidate numbers C and a target number T , find all unique combinations in C where the candidate numbers sums to T.  
// The same repeated number may be chosen from C unlimited number of times    
// Hint: DFS

vector<vector<int>> combination_sum (vector<int> c, int t){

	vector<vector<int>> res;

	vector<int> tmp;

	dfs(c, t, 0, tmp, res);
}

void dfs(vector<int> c, int gap, int start, vector<int> &tmp, vector<vector<int>> res)
{
	if(gap == 0){
		res.push_back(tmp);
	}

	for(int i=start; i<c.size(); i++){
		if(gap > a[i]){
			tmp.push_back(a[i]);
			dfs(c,gap-a[i],i,tmp,res);
			tmp.pop_back(a[i]);
		}
	}
}

// Combination Sum 1 
// Another would be the same number can not be chosen unlimited times

vector<vector<int>> combination_sum2 (vector<int> c, int t){
	vector<vector<int>> res;

	vector<int> tmp;

	dfs(c, t, 0, tmp, res);
}

void dfs(vector<int> c, int gap, int start, vector<int> &tmp, vector<vector<int>> &res){
	if(gap == 0){
		res.push_back(tmp);
	}

	for(int i=start; i<c.size(); i++){
		if(gap > a[i]){
			tmp.push_back(a[i]);
			dfs(c,gap-a[i],i+1,tmp,res);
			tmp.pop_back();
		}
	}
}

// count and say     
// The count-and-say sequence  1 => 11 (one 1)   11 => 21 (two 1)  21 => 1211(one 2 two 1)    Given an integer n and generate the nth sequence

vector<int> count_and_say( int n){

	string seq = "1";

	int idx = 1;
	while(idx < n){

		stringstream new_seq;
		char last = seq[0];
		int count = 0;

		for(int i=0; i<seq.size(); i++){
			if (last == seq[i]){
				count ++;
				continue;
			}else{
				new_seq << count << last;
				last = seq[i];
				count = 1;
			}
		}
		seq = new_seq.str();
		idx++;
	}

	return seq;

}

// first missing positive    
// Given an unsorted array, find the first missing positive integer  
// O(n) and constant space

int first_missing_positive(vector<int> a){
	int n = a.size();

	bool map[n+1];
	memset(map, false, sizeof(map));

	for(int i=1; i<=n; i++){
		if( 1<=i<=n && !map[i] )
			map[i] = true;
	}

	int res;
	for(int i=1; i<=n; i++)
		if( !map[i] )
			res = i;

	return i;
}

// Longest Valid Parenttheses   
// Given a string containing just the characters '(' and ')', find the length of the longest valid (well formed) parentheses substring.      
// 摩根士丹利的面试题    面试题更难一些，需要返回子序列，而此题不用

int get_longest_valid_parentheses(string s){
	stack<int> q;
	int max_len;
	int len = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '(')
			q.push(i);
		else if( s[i] == ')' && !q.empty() )
		{
			int start = q.top();
			q.pop();
			len += i - start + 1;
			max_len = max_len > len ? max_len : len;
		}else{
			len = 0;
		}
	}
	return max_len;
}

// 考虑这样的case :  (()))()()()
// 最长应该为6
string get_longest_valid_parentheses(string s){
	stack<int> q;
	int max_len;
	string res;
	int len = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '('){
			q.push(i);
		}else if( s[i] == ')' && !q.empty() )
		{
			int start = q.top();
			q.pop();
				len += i - start + 1;
			if (max_len < len){
				max_len = len;
				start = i - len + 1;
				res = substr(start, len);
			}
		}
		else{
			len = 0;
		}
	}

	return res;
}

// Next Permutation   

// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place, do not allocate extra memory.

vector<int> next_permutation(vector<int> a){
	int desc_idx;
	for(int i=a.size()-1; i>0; i--){
		if(a[i] > a[i-1])
			desc_idx = i-1;
	}

	int max_idx;
	for(int i=a.size()-1; i>desc_idx; i--)
		if(a[i] > a[desc_idx])
			max_idx = i;

	int tmp = a[desc_idx];
	a[desc_idx] = a[max_idx];
	a[max_idx] = tmp;

	int left = desc_idx+1;
	int right = a.size()-1;
	while(left <= right){
		tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left ++;
		right--;
	}

	return a;
}

// search Insert Position   
// given a sorted array and a target number, return the index if the target is found , 
// If not, return the index where is would be inserted in order

int search_insert_position(vector<int> a, int target)

// Search for a Range   
// Given a sorted array of integers, find the starting and the ending position of a given target value   
// Hint: 二分, 拓展 找到后继续向左右分别找

vector<int> binary_search_range(vector<int> a, int target){
	
	vector<int> range;

	int left = 0;
	int right = a.size()-1;

	int mid;
	int l_idx;
	while(left <= right){
		mid = left + (right-left)>>1;
		if (a[mid] >= target)
			right = mid-1;
		else
			left = mid+1;
	}
	l_idx = left;
	range.push_back(l_idx);

	int r_idx;
	while(left<=right){
		mid=left+(right-left)>>1;
		if(a[mid] <= target)
			left = mid+1;
		else
			right = mid-1;
	}
	r_idx = right;
	range.push_back(r_idx);

	return range;
}

// search in rotated sorted array   
// Suppose a sorted array is rotated at some pivot unknown to you beforehand. You are given a target to search    
// Hint: 剑指offer     如果left>right    a[mid] < target < a[right] left = mid     a[mid] < target < a[left]  right = mid      target < a[mid]    仔细看一下

int binary_search_in_rotated_array(vector<int> a, int target){
	int left = 0;
	int right = a.size()-1;

	int mid;
	while(left <= right){
		mid = left + (right - mid) >> 1;
		if (a[mid] == target)
			return mid;
		
		if (a[mid] < a[left]){
			if (a[mid] < target < a[right])
				left = mid+1;
			else
				right = mid-1;
		}else{
			if (a[left] < target < a[mid])
				right = mid-1;
			else
				left = mid+1;

		}
	}

	return -1;
}

// Substring with Concatenation of All Words    
// Given a string S and a list of words L, that are all the same length. 
// Find all starting indices of substring(s) in S that is a concatenation(连接) of each word in L exactly once and without any intervening characters      

vector<int> substring_with_concatenation (string str, vector<string> words){

	vector<int> res;

	int num = words.size();
	int len = words[0].size();

	map<string, int> expectcount;
	map<string, int> realcount;

	for(int i=0; i<num; i++)
		expectcount[words[i]] ++;

	for(int i=0; i<str.size()-num*len+1; i++){
		realcount.clear();
		int j=0;
		for(;j<num;j++){
			string s = str.substr(i+j*len, len);
			if( expectcount.find(s) != expectcount.end())
				realcount++;
			else
				break;
			if(realcount[s] > expectcount[s])
				break;
		}
		if(j==row){
			res.push_back(i);
		}
	}

	return res;

}