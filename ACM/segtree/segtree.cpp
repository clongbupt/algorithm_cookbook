/*
	maxn 题目给的最大区间，而节点数要开4倍，确切的说节点数要开大于maxn的最小2^x的两倍
	lson rson 分别表示节点的做儿子和右儿子，由于每次传参数的时候都固定是这几个变量，用define预定义
	PushUP(int rt) 把当前节点的信息更新到父节点
	PushDown(int rt)  把当前节点的信息更新到儿子节点
	rt 表示当前子树的根(root), 也就是当前所在的节点

*/


#include <cstdio>
 
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 55555;
int sum[maxn<<2];
void PushUP(int rt) {
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void build(int l,int r,int rt) {
	if (l == r) {
		scanf("%d",&sum[rt]);
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUP(rt);
}
void update(int p,int add,int l,int r,int rt) {
	if (l == r) {
		sum[rt] += add;
		return ;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p , add , lson);
	else update(p , add , rson);
	PushUP(rt);
}
int query(int L,int R,int l,int r,int rt) {
	if (L <= l && r <= R) {
		return sum[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret += query(L , R , lson);
	if (R > m) ret += query(L , R , rson);
	return ret;
}
int main() {
	int T , n;
	scanf("%d",&T);   //读取测试组数
	for (int cas = 1 ; cas <= T ; cas ++) {
		printf("Case %d:\n",cas);
		scanf("%d",&n);     //线段树长度
		build(1 , n , 1);   //建树
		char op[10];
		while (scanf("%s",op)) {
			if (op[0] == 'E') break;
			int a , b;
			scanf("%d%d",&a,&b);
			if (op[0] == 'Q') printf("%d\n",query(a , b , 1 , n , 1));
			else if (op[0] == 'S') update(a , -b , 1 , n , 1);
			else update(a , b , 1 , n , 1);
		}
	}
	return 0;
}
