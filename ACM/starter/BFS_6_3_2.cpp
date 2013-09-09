#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define MAXN 256
char s[MAXN + 10];
int failed;

typedef struct TNode
{
	int have_value;
	int v;
	struct TNode *left, *right;
} Node;

Node * root;

Node * newnode()
{
	Node * u = (Node *) malloc(sizeof(Node));     //申请动态内存
	
	if (u != NULL)                //若申请成功
	{
		u -> have_value = 0;     //malloc得到的内存并未清零，需要初始化为0
		u -> left = u -> right = NULL;      //初始化没有左右儿子
	}
	
	return u;
}

void addnode(int v, char *s)
{
	int n = strlen(s);
	Node * u = root;       //从根节点开始往下走
	
	for (int i = 0; i < n; i ++)
	{
		if (s[i] == 'L')
		{
			if (u -> left == NULL) u -> left = newnode();    //当节点不存在，建立新节点
			u = u -> left;           //往左走
		}
		else if(s[i] == 'R')
		{
			if (u -> right == NULL) u -> right = newnode();
			u = u -> right;
		}
		//忽略其他情况，包括最后那个多余的右括号
	}
	if (u -> have_value) failed = 1;    //已经赋过值，表明输入有误
	
	u -> have_value = 1;      //赋值标记
	u -> v = v;
}

void remove_tree (Node *u)
{
	if (u == NULL) return;
	remove_tree(u -> left);
	remove_tree(u -> right);
	free(u);
}


int read_input()
{
	failed = 0;
	remove_tree(root);
	root = newnode();       //创建根节点
	for (;;)
	{
		if (scanf("%s", s) != 1) return 0;    //整个输入结束
		if (!strcmp(s, "()")) break;          //读到结束标志，退出循环
		int v;
		sscanf(&s[1], "%d", &v);              //读入节点值
		addnode(v, strchr(s, ',') + 1);       //查找逗号，然后插入节点
	}
	
	return 1;
}
int n = 0, ans[MAXN];
int bfs ()
{
	int front = 0, rear = 1;
	Node *q[MAXN];
	q[0] = root;
	while (front < rear)
	{
		Node *u = q[front++];
		if (!u -> have_value) return 0;
		
		ans[n++] = u -> v;
		if (u -> left != NULL) q[rear ++] = u -> left;
		if (u -> right != NULL) q[rear ++] = u -> right;
	}
	return 1;
}

int main() {
  while(read_input()) {
    if(!bfs()) failed = 1;
    if(failed) printf("-1\n");
    else {
      for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);
      printf("\n");
    }
  }
  return 0;
}
