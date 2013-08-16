/**
 * 假定 n 不超过100
 */
define MAXN 10000

void get_probability(int n){
	int a[MAXN];
	memset(a,0,sizeof(a));

	a[0] = 1;
	for(int i=1; i<=n; i++)    // 骰子个数
		for(int j=6*i; j>= i; j--)   // 在当前骰子个数下可能组成的值之间   反过来循环保证动态数组不会被刷新
			for(int k=j-1; k>=0; k--){   // 当前值是由前面的6个值组成, 注意不能越出边界
				if(j-k<=6)      // 前六个值组成当前的值
					a[j] += a[k];
				else            // 其他值归零
					a[k] = 0;
			}
	for(int i=n; i<6*n; i++)
		printf("%d ", a[i]/n*n);
	printf("%d\n", a[6*n]/n*n);
}