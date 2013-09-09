#include<cstdio>

#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1

const int maxn = 50005;

int sum[maxn << 2];

void PushUP(int rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build (int l, int r, int rt)
{
	if ( l == r)
	{
		scanf("%d", &sum[rt]);
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUP(rt);
}

int query (int L, int R, int l, int r, int rt)
{
	if (L<=l && R>=r)
		return sum[rt];
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret += query(L,R,lson);
	if (R > m) ret += query(L,R,rson);
	return ret;
}

void update (int p, int add, int l, int r, int rt)
{
	if (l == r)
	{
		sum[rt] += add;
		return ;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p, add, lson);
	else update(p, add, rson);
	PushUP(rt);
}

int main(){
	int cases,num;
	scanf("%d", &cases);
	for (int i=0; i<cases; i++)
	{
		printf("Case %d:", i);
		scanf("%d", &num);
		build(1,num,1);
		char op[10];
		while (scanf ("%s", op) != EOF )
		{
			if (op[0] == 'E')
				break;
			int a, b;
			scanf ("%d %d", &a, &b);
			if (op[0] == 'Q')
				printf ("%d\n", query(a, b, 1, num, 1));
			else if (op[0] == 'A')
				update(a, b, 1, num, 1);
			else if (op[0] == 'S')
				update(a, -b, 1, num, 1);
		}
	}
}
