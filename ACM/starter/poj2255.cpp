#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define MAX 27

//n为树的长度，s1是先序遍历，s2是中序遍历
void build(int n, char *s1, char *s2, char *s)
{
	if (n <= 0)	return;
	int p = strchr(s2, s1[0]) - s2;     //找到根节点在中序遍历中的位置
	
	//printf("n:%d p:%d\n", n, p);
	
	build(p, s1 + 1, s2, s);     //递归构造左子树的后续遍历   (0 到 p-1) 为左子树  (p + 1 到 n)为右子树
	// 左子树对于s1(先序)来说为除去位于0的点(根),后面p个点都在左子树上
	// 左子树对于s2(中序)来说为前p个点
	build(n - p - 1, s1 + p + 1, s2 + p + 1, s + p);
	// 右子树对于s1(先序)来说为跳过根(0点)和后面紧跟的左子树(p个)，剩下的点都在右子树上
	// 右子树对于s2(中序)来说为根后面的点(p点的位置为根所在的位置)
	// 同理右子树对于s(后序)来说,需要移动p个位置，以保证左子树的节点有地方存入
	s[n - 1] = s1[0];   //n为树的长度
}

int main()
{
	char s1[MAX], s2[MAX], ans[MAX];
	while (scanf("%s%s", s1, s2)!=EOF)
	{
		int n = strlen(s1);
		build(n, s1, s2, ans);
		ans[n] = '\0';
		printf("%s\n", ans);
	}

	return 0;
}
