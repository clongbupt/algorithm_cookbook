#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN = 100 + 10;
int g[MAXN][MAXN];
int vis[MAXN][MAXN];

void dfs(int x, int y){

	// if(!vis[x][y] && g[x][y])
	// 	vis[x][y] = 1;
	if(!g[x][y] || vis[x][y]) return;

	vis[x][y] = 1;

	dfs(x-1,y-1);	dfs(x-1,y);		dfs(x-1,y+1);
	dfs(x,y-1);						dfs(x,y+1);
	dfs(x+1,y-1);	dfs(x+1,y);		dfs(x+1,y+1);

}

int main(int argc, char const *argv[])
{

	int m,n;
	while(scanf("%d %d", &m, &n) && m){
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));
		char temp[n];
		for(int i=0; i<m; i++){
			scanf("%s", temp);
			for(int j=0; j<n; j++)
			{
				if(temp[j] == '*')
					g[i+1][j+1] = 0;
				else
					g[i+1][j+1] = 1;
			}
		}

		int count = 0;
		for(int x=1; x<=m; x++)
			for(int y=1; y<=n; y++)
				if(!vis[x][y] && g[x][y])
				{
					count ++;
					dfs(x,y);
				}
		printf("%d\n", count);
	}

}