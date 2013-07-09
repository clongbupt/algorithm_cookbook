void compute_next(const char pattern, int m, int *next){
	int i;
	int j = -1;
	next[0] = j;

	for(i=1; i<m; i++){
		while(j>-1 && pattern[j+1] != pattern[i])
			j = next[j];

		if (pattern[j+1] == pattern[i])
			j ++;

		next[i] = j;
	}
}

/**
  * param  char[]  src  原字符串
  * param  int     n    src数组的长度
  * param  char[]  pattern  模式字符串
  * param  int     m    模式数组的长度
  *
  */
int kmp_search(const char src[], int n, const char pattern[], int m){
	int i;
	int j = -1;

	int *next = (int *)malloc(sizeof(int) * m);

	// 计算next数组
	compute_next(pattern, m, next);

	for (i=0; i<n; i++){
		while(j > -1 && pattern[j+1] != src[i])    // 如果先前有匹配成功而当前匹配不成功, 通过next向前回溯
			j = next[j];

		if(pattern[j+1] == src[i])    // 当前匹配成功
			j++;

		if(j == m-1){    // 模式串走到头   完成匹配
			free(next);
			return i - j;
		}

	}

	free(next);
	return -1;
}

/*
一些解释

两个状态   先前匹配是否成功     当前匹配是否成功

先前匹配是否有成功   可以观察 j 是否大于 -1
当前匹配是否成功   可观察   src[i] 是否等于 pattern[j+1]

组合起来有四种情况

先前匹配不成功且当前匹配不成功    j == -1 && src[i] != pattern[j+1]   i++ 即原串向右移动
先前匹配不成功但当前匹配成功      j == -1 && src[i] == pattern[j+1]   i++ && j++
先前匹配成功但当前匹配不成功      j > -1 && src[i] != pattern[j+1]    j = next[j]   因为先前有成功的, 通过next数组回溯
先前匹配成功且当前匹配成功        j > -1 && src[i] == pattern[j+1]    i++ && j++

不过所有都必须判断j是否到头, 如果到头则完成寻找

总上伪码为：

for (i=0; i< n; i++){
	while(j>-1 && src[i] != pattern[j+1]) j = next[j];

	if (src[i] == pattern[j+1]) j++;

	if (j == m-1){
		return i -j;
	}
}


*/