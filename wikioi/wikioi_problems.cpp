//wikioi problems

// 1098 均分纸牌

/*
有 N 堆纸牌，编号分别为 1，2，…, N。每堆上有若干张，但纸牌总数必为 N 的倍数。可以在任一堆上取若于张纸牌，然后移动。
　　移牌规则为：在编号为 1 堆上取的纸牌，只能移到编号为 2 的堆上；在编号为 N 的堆上取的纸牌，只能移到编号为 N-1 的堆上；其他堆上取的纸牌，可以移到相邻左边或右边的堆上。
　　现在要求找出一种移动方法，用最少的移动次数使每堆上纸牌数都一样多。

　　例如 N=4，4 堆纸牌数分别为：
　　①　9　②　8　③　17　④　6
　　移动3次可达到目的：
　　从 ③ 取 4 张牌放到 ④ （9 8 13 10） -> 从 ③ 取 3 张牌放到 ②（9 11 10 10）-> 从 ② 取 1 张牌放到①（10 10 10 10）
 
INPUT:
第一行N（N 堆纸牌，1 <= N <= 100）
第二行A1 A2 … An （N 堆纸牌，每堆纸牌初始数，l<= Ai <=10000）

OUTPUT:
输出至屏幕。格式为：
所有堆均达到相等时的最少移动次数。‘
 */

int arrange_cards(vector<int> cards){

	int sum = 0, avg;
	int n = cards.size();
	for(int i=0; i<n; i++){
		sum += cards[i];
	}

	avg = sum / n;

	int res = 0;
	for(int i=0; i<n-1; i++){
		if(cards[i] != avg){
			count ++;
			if( cards[i] < avg ){
				cards[i+1] -= avg-cards[i];
			}else{
				cards[i+1] += cards[i]-avg;
			}
		}
	}

	return count;
}

// 1214  线段覆盖

/*
给定x轴上的N（0<N<100）条线段，每个线段由它的二个端点a_I和b_I确定，I=1,2,……N.这些坐标都是区间（－999，999）的整数。有些线段之间会相互交叠或覆盖。请你编写一个程序，从给出的线段中去掉尽量少的线段，使得剩下的线段两两之间没有内部公共点。所谓的内部公共点是指一个点同时属于两条线段且至少在其中一条线段的内部（即除去端点的部分）。

input:
3
6  3
1  3
2  5

Output
2
 */

struct segment{
	int x;
	int y;
};

bool cmp(const segment a, const segment b){
	return a.y < b.y;
}

int remove_minimal_segment(vector<segment> a){
	int n = a.size();

	for(int i=0; i<n; i++)
		if(a[i].x > a[i].y){
			int tmp = a[i].x;
			a[i].x = a[i].y;
			a[i].y = tmp;
 		}

	sort(a.begin(), a.end(), cmp);

	bool flag[n];
	memset(flag, 0, memset(flag));
	
	int ans = 0;
	for(int i=0; i<n-1; i++){
		if (!flag[i]){
			ans ++;
			for(int j=i+1; j<n; j++){
				if(a[i].b > a[j].a){
					flag[j] = true;
				}
			}
		}
	}

	return a.size() - ans;
}

// 3115 3116 3117   高精度  减法 / 加法 / 乘法


// 背包型动态规划

// 1014 装箱问题

/*
有一个箱子容量为V（正整数，0＜＝V＜＝20000），同时有n个物品（0＜n＜＝30），每个物品有一个体积（正整数）。
要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。

一个整数v，表示箱子容量
一个整数n，表示有n个物品
接下来n个整数，分别表示这n 个物品的各自体积

一个整数，表示箱子剩余空间。

Input:
24
6
8
3
12
7
9
7
 */

int Max(int a, int b){
	return a > b ? a : b;
}

int get_minimal_area(vector<int> a, int v){
	int dp[v+1];
	memset(dp, 0, sizeof(dp));

	for(int i=0; i<a.size(); i++)
		for(int j=v; j>=a[i]; j--)
			dp[j] = Max(dp[j], dp[j-a[i]] + a[i]);

	return v-dp[v]; 
}

// 1068 乌龟棋

/*
小明过生日的时候，爸爸送给他一副乌龟棋当作礼物。 乌龟棋的棋盘是一行N个格子，每个格子上一个分数（非负整数）。棋盘第1格是唯一的起点，第N格是终点，游戏要求玩家控制一个乌龟棋子从起点出发走到终点。…… 1 2 3 4 5 ……N 乌龟棋中M张爬行卡片，分成4种不同的类型（M张卡片中不一定包含所有4种类型的卡片，见样例），每种类型的卡片上分别标有1、2、3、4四个数字之一，表示使用这种卡 片后，乌龟棋子将向前爬行相应的格子数。游戏中，玩家每次需要从所有的爬行卡片中选择一张之前没有使用过的爬行卡片，控制乌龟棋子前进相应的格子数，每张卡片只能使用一次。游戏中，乌龟棋子自动获得起点格子的分数，并且在后续的爬行中每到达一个格子，就得到 该格子相应的分数。玩家最终游戏得分就是乌龟棋子从起点到终点过程中到过的所有格子的分数总和。很明显，用不同的爬行卡片使用顺序会使得最终游戏的得分不同，小明想要找到一种卡片使用顺序使得最终游戏得分最多。现在，告诉你棋盘上每个格子的分数和所有的爬行卡片，你能告诉小明，他最多能得到 多少分吗？

Input:
输入的每行中两个数之间用一个空格隔开。第1行2个正整数N和M，分别表示棋盘格子数和爬行卡片数。第2行N个非负整数，a1a2……aN
，其中ai表示棋盘第i个格子上的分数。第3行M个整数，b1b2……bM，表示M张爬行卡片上的数字。输入数据保证到达终点时刚好用光M张爬行卡片，即N - 1=∑(1->M) bi
 
Output:
最后的得分

Sample Input
13 8
4 96 10 64 55 13 94 53 5 24 89 8 30
1 1 1 1 1 2 4 1

Sample Output
455
 */

int get_maximal_score( vector<int> a, vector<int> b ){

	int c[4];
	memset(c, 0, sizeof(c));

	for(int i=0; i<b.size(); i++)
		c[b[i]] ++;

	int dp[c[0]][c[1]][c[2]][c[3]];
	memset(dp, 0, sizeof(dp));

	dp[0][0][0][0] = a[0];
	for(int i=0; i<=c[0]; i++)
		for(int j=0 j<=c[1]; j++)
			for(int k=0; k<=c[2]; k++)
				for(int l=0; l<=c[3]; l++)
				{
					int now=i+2*j+3*k+4*l;
					if(i>=1)
						d[i][j][k][l]=max(d[i][j][k][l],d[i-1][j][k][l]+r[now]);
					if(j>=1)
						d[i][j][k][l]=max(d[i][j][k][l],d[i][j-1][k][l]+r[now]);
					if(k>=1)
						d[i][j][k][l]=max(d[i][j][k][l],d[i][j][k-1][l]+r[now]);
					if(l>=1)
						d[i][j][k][l]=max(d[i][j][k][l],d[i][j][k][l-1]+r[now]);
				}

}

// 序列型动态规划


// 1044 拦截导弹

/*
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数）
输出这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

Sample Input:
389 207 155 300 299 170 158 65 

Sample Output:
6
2
 */

// 最多能拦截多少导弹
int longest_desc_sequence(vector<int> a){

	int n = a.size();

	int dp[n];
	memset(dp, 1, sizeof(dp));

	for(int i=1; i<n; i++)
		for(int j=0; j<i; j++)
			if (a[j] >= a[i] && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
			}

	int res = 0x80000000;
	for(int i=0; i<n; i++)
		if( res < dp[i])
			res = dp[i];

	return res;
}

int longest_asc_sequence(vector<int> a){
	int n = a.size();

	int dp[n];
	memset(dp, 1, sizeof(dp));

	for(int i=1; i<n; i++)
		for(int j=0; j<i; j++)
			if(a[j] < a[i] && dp[i] < dp[j]+1)
				dp[i] = d[j] + 1;

	int res = 0x80000000;
	for(int i=0; i<n; i++)
		res = res > a[i] ? res : a[i];

	return res;
}

// 1576 最长严格上升子序列

/*
非常经典的问题，拿来给大家练手了。序列 { 1,2,...,n } 的一个子序列是指序列 { i1, i2, ……, ik },其中 1<=i1 < i2 < …… < ik<=n, 序列 { a1, a2, ……, an } 的一个子序列是指序列 { ai1, ai2, ……, aik },其中 { i1, i2, ……, ik } 是 { 1, 2, ……, n } 的一个子序列.同时,称 k 为此子序列的长度. 如果 { ai1, ai2, ……, aik } 满足 ai1 ≤ ai2 ≤ …… ≤ aik,则称之为上升子序列.如果不等号都是严格成立的,则称之为严格上升子序列.同理,如果前面不等关系全部取相反方向, 则称之为下降子序列和严格下降子序列. 长度最长的上升子序列称为最长上升子序列.本问题对于给定的整数序列,请求出其最长严格上升子序列的长度

Sample Input :
9 3 6 2 7
Sample Output:
3

 */

int longest_strict_asc_sequence(vector<int> a){
	int n = a.size();

	int dp[n];
	memset(dp, 1, sizeof(dp));

	for(int i=1; i<n; i++)
		for(int j=0; j<i; j++)
			if(a[j] < a[i] && dp[i] < dp[j]+1)
				dp[i] = dp[j] + 1;

	int res = 0x80000000;
	for(int i=0; i<n; i++)
		res = res > a[i] ? res : a[i];

	return res;
}


// 3027 线段覆盖

/*
数轴上有n条线段，线段的两端都是整数坐标，坐标范围在0~1000000，每条线段有一个价值，请从n条线段中挑出若干条线段，使得这些线段两两不覆盖（端点可以重合）且线段价值之和最大。
n<=1000
第一行一个整数n，表示有多少条线段。
接下来n行每行三个整数, ai bi ci，分别代表第i条线段的左端点ai，右端点bi（保证左端点<右端点）和价值ci。
输出能够获得的最大价值

Sample Input:
3
1 2 1
2 3 2
1 3 4

Sample Output:
4
 */

struct segment{
	int x;
	int y;
	int value;
};

bool cmp(segment a, segment b){
	return a.y < a.y;
}

int get_maximal_value_and_no_segement_together(vector<segment> a ){
	int n = a.size();

	sort(a.begin(), a.end(), cmp);

	int dp[n];
	for(int i=0; i<n; i++)
		dp[i] = a[i].value;


	for(int i=1;i<n;i++)
		for(int j=0; j<i; j++)
			if(a[i].x >= a[j].y && dp[i] < dp[j]+a[i].value)
				dp[i] = dp[j] + a[i].value;

	int res = 0x80000000;
	for(int i=0; i<n; i++)
		res = res > a[i] ? res : a[i];

	return res;
}

// 区间型动态规划    

// 1048   石子归并

/*
有n堆石子排成一列，每堆石子有一个重量w[i], 每次合并可以合并相邻的两堆石子，一次合并的代价为两堆石子的重量和w[i]+w[i+1]。问安排怎样的合并顺序，能够使得总合并代价达到最小。

第一行一个整数n（n<=100）
第二行n个整数w1,w2...wn  (wi <= 100)

一个整数表示最小合并代价

Sample Input:
4
4 1 1 4

Sample Output:
18
 */

int get_min_sum(vector<int> a){
	int n = a.size();

	int sum[n];
	sum[0] = a[0];
	for(int i=1; i<n; i++)
		sum[i] = sum[i-1]+a[i];

	int dp[n][n];
	memset(dp, 0, sizeof(dp));

	for(int len=2; len<=n; len++)
		for(int i=0; i<n-len+1; i++)
		{
			int j = i + len - 1;
			dp[i][j] = 0x7fffffff;
			for(int k=i; k<j; k++)
				if( i>0 && dp[i][j] > dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1] )
					dp[i][j] = dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1];
				else if( i==0 && dp[i][j] > dp[i][k] + dp[k+1][j] + sum[j])
					dp[i][j] = dp[i][k] + dp[k+1][j] + sum[j];
		}	

	return dp[0][n-1];
}

// 1154 能量项链

/*
在Mars星球上，每个Mars人都随身佩带着一串能量项链。在项链上有N颗能量珠。能量珠是一颗有头标记与尾标记的珠子，这些标记对应着某个正整数。并且，对于相邻的两颗珠子，前一颗珠子的尾标记一定等于后一颗珠子的头标记。因为只有这样，通过吸盘（吸盘是Mars人吸收能量的一种器官）的作用，这两颗珠子才能聚合成一颗珠子，同时释放出可以被吸盘吸收的能量。如果前一颗能量珠的头标记为m，尾标记为r，后一颗能量珠的头标记为r，尾标记为n，则聚合后释放的能量为m*r*n（Mars单位），新产生的珠子的头标记为m，尾标记为n。

需要时，Mars人就用吸盘夹住相邻的两颗珠子，通过聚合得到能量，直到项链上只剩下一颗珠子为止。显然，不同的聚合顺序得到的总能量是不同的，请你设计一个聚合顺序，使一串项链释放出的总能量最大。

例如：设N=4，4颗珠子的头标记与尾标记依次为(2，3) (3，5) (5，10) (10，2)。我们用记号⊕表示两颗珠子的聚合操作，(j⊕k)表示第j，k两颗珠子聚合后所释放的能量。则第4、1两颗珠子聚合后释放的能量为：

(4⊕1)=10*2*3=60。

这一串项链可以得到最优值的一个聚合顺序所释放的总能量为

((4⊕1)⊕2)⊕3）=10*2*3+10*3*5+10*5*10=710。

第一行是一个正整数N（4≤N≤100），表示项链上珠子的个数。第二行是N个用空格隔开的正整数，所有的数均不超过1000。第i个数为第i颗珠子的头标记（1≤i≤N），当i<N< span>时，第i颗珠子的尾标记应该等于第i+1颗珠子的头标记。第N颗珠子的尾标记应该等于第1颗珠子的头标记。

至于珠子的顺序，你可以这样确定：将项链放到桌面上，不要出现交叉，随意指定第一颗珠子，然后按顺时针方向确定其他珠子的顺序。

只有一行，是一个正整数E（E≤2.1*109），为一个最优聚合顺序所释放的总能量。

Sample Input : 
4
2 3 5 10

Sample Output:
710

 */

int get_max_power(vector<int> a){
	int n = a.size();

	int dp[n][n];
	memset(dp, 0, sizeof(dp));

	for(int len=2; len<=n; len++)
		for(int i=0; i<n; i++){
			int j = i+len-1;
			dp[i][j] = 0x7fffffff;
			for(int k=i; k<j; k++){
				if(dp[i][j] < dp[i][k] + dp[k+1][j] + a[i]*a[k%n]*a[j%n])
					dp[i][j] = dp[i][k] + dp[k+1][j] + a[i]*a[k%n]*a[j%n];
			}
		}

	int res = 0x7fffffff;
	for(int i=0; i<n; i++)
		res = res > dp[i][i+n-1] ? res : dp[i][i+n-1];

	return res;
}


// 1166 矩阵取数游戏

/*
【问题描述】
帅帅经常跟同学玩一个矩阵取数游戏：对于一个给定的n*m 的矩阵，矩阵中的每个元素aij均
为非负整数。游戏规则如下：
1. 每次取数时须从每行各取走一个元素，共n个。m次后取完矩阵所有元素；
2. 每次取走的各个元素只能是该元素所在行的行首或行尾；
3. 每次取数都有一个得分值，为每行取数的得分之和，每行取数的得分= 被取走的元素值*2i，
其中i 表示第i 次取数（从1 开始编号）；
4. 游戏结束总得分为m次取数得分之和。
帅帅想请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大得分。

第1行为两个用空格隔开的整数n和m。
第2~n+1 行为n*m矩阵，其中每行有m个用单个空格隔开的非负整数。

输出 仅包含1 行，为一个整数，即输入矩阵取数后的最大得分。

Sample Input:
2 3
1 2 3
3 4 2

样例解释
第 1 次：第1 行取行首元素，第2 行取行尾元素，本次得分为1*2+2*2=6
第2 次：两行均取行首元素，本次得分为2*2*2+3*2*2=20
第3 次：得分为3*2*3+4*2*3=56。总得分为6+20+56=82

Sample Output:
82
 */



// 棋盘型动态规划

// 1010   过河卒

/*
A 点有一个过河卒，需要走到目标 B 点。卒行走规则：可以向下、或者向右。同时在棋盘上的任一点有一个对方的马（如上图的C点），该马所在的点和所有跳跃一步可达的点称为对方马的控制点。例如上图 C 点上的马可以控制 9 个点（图中的P1，P2 … P8 和 C）。卒不能通过对方马的控制点。

　　棋盘用坐标表示，A 点（0，0）、B 点（n,m）(n,m 为不超过 20 的整数，并由键盘输入)，同样马的位置坐标是需要给出的（约定: C不等于A，同时C不等于B）。现在要求你计算出卒从 A 点能够到达 B 点的路径的条数。
1<=n,m<=15

键盘输入
　　　B点的坐标（n,m）以及对方马的坐标（X,Y）{不用判错}

屏幕输出
　　　　一个整数（路径的条数）。

Sample Input : 
6 6 3 2

Sample Output:
17
 */

int get_path_sum(int n, int m, int x, int y){

	int vis[n+1][m+1];
	memset(vis, 0, sizeof(vis));

	int px = {2, 1, -1, -2, -2, -1, 1, 1};
	int py = {1, 2, 2, 1, -1, -2, -2, -1};

	int nx, ny;
	for(int i=0; i<8; i++){
		nx = x + px[i];
		ny = y + py[i];
		if ( nx>=0 && nx<=n && ny>=0 && ny<=m )
			vis[nx][ny] = 1;
	}

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for(int i=0; i<=n; i++)
		if( !vis[i][0] )
			dp[i][0] = 1;
		else
			break;

	for(int j=0; j<=m; j++)
		if( !vis[0][j] )
			dp[0][j] = 1;
		else
			break;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if( !vis[i][j] )
				if( dp[i-1][j] > dp[i][j-1] )
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = dp[i][j-1];

	return dp[n][m];
}

// 1169  传纸条

/*
小渊和小轩是好朋友也是同班同学，他们在一起总有谈不完的话题。一次素质拓展活动中，班上同学安排做成一个m行n列的矩阵，而小渊和小轩被安排在矩阵对角线的两端，因此，他们就无法直接交谈了。幸运的是，他们可以通过传纸条来进行交流。纸条要经由许多同学传到对方手里，小渊坐在矩阵的左上角，坐标(1,1)，小轩坐在矩阵的右下角，坐标(m,n)。从小渊传到小轩的纸条只可以向下或者向右传递，从小轩传给小渊的纸条只可以向上或者向左传递。
在活动进行中，小渊希望给小轩传递一张纸条，同时希望小轩给他回复。班里每个同学都可以帮他们传递，但只会帮他们一次，也就是说如果此人在小渊递给小轩纸条的时候帮忙，那么在小轩递给小渊的时候就不会再帮忙。反之亦然。
还有一件事情需要注意，全班每个同学愿意帮忙的好感度有高有低（注意：小渊和小轩的好心程度没有定义，输入时用0表示），可以用一个0-100的自然数来表示，数越大表示越好心。小渊和小轩希望尽可能找好心程度高的同学来帮忙传纸条，即找到来回两条传递路径，使得这两条路径上同学的好心程度只和最大。现在，请你帮助小渊和小轩找到这样的两条路径。

输入的第一行有2个用空格隔开的整数m和n，表示班里有m行n列（1<=m,n<=50）。
接下来的m行是一个m*n的矩阵，矩阵中第i行j列的整数表示坐在第i行j列的学生的好心程度。每行的n个整数之间用空格隔开。

输出共一行，包含一个整数，表示来回两条路上参与传递纸条的学生的好心程度之和的最大值。

Sample Input:
3 3
0 3 9
2 8 5
5 7 0

Sample Output:
34
 */

int pass_message(vector<vector<int>> map){

	int n = map.size();
	int m = map[0].size();

	int dp[n+1][m+1][n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			for(int k=1; k<=n; k++)
				for(int l=1; l<=m; l++)
				{
					if(i>1 && k>1 && (i!=k || j!=l))
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i-1][j][k-1][l] + map[i][j] + map[k][l]);
					if(i>1 && l>1 && (i-1!=k || j!=l-1))
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i-1][j][k][l-1] + map[i][j] + map[k][l]);
					if(j>1 && k>1 && (j-1!=l || i!=k-1))
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j-1][k-1][l] + map[i][j] + map[k][l]);
					if(j>1 && l>1 && (j!=l || i!=k))
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j-1][k][l-1] + map[i][j] + map[k][l]);
				}

	return dp[n][m][n][m];
}

// 此题可以进行多维状态压缩   i+j = k+l


// 1219  骑士游历

/*
设有一个n*m的棋盘（2≤n≤50，2≤m≤50），如下图，在棋盘上有一个中国象棋马。
规定：
1)马只能走日字
2)马只能向右跳
问给定起点x1,y1和终点x2,y2，求出马从x1,y1出发到x2,y2的合法路径条数。

第一行2个整数n和m
第二行4个整数x1,y1,x2,y2

输出方案数

Sample Input:
30 30
1 15 3 15

Sample Output:
2

 */

int get_knight_path_sum(int n, int m, int x1, int y1, int x2, int y2){

	int px[4] = {-2, -1, 1, 2};
	int py[4] = {1, 2, 2, 1};

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	dp[x1][y1] = 1;
	for(int i=x1; i<=x2; i++)
		for(int j=1; j<=m; j++)
			dp[i][j] = dp[i+2][j-1] + dp[i+1][j-2] + dp[i-1][j-2] + dp[i-2][j-1];

	return dp[x2][y2];

}


// 1220 数字三角形

/*
如图所示的数字三角形，从顶部出发，在每一结点可以选择向左走或得向右走，一直走到底层，要求找出一条路径，使路径上的值最大。

第一行是数塔层数N(1<=N<=100)。
第二行起，按数塔图形，有一个或多个的整数，表示该层节点的值，共有N行。

输出最大值。

Sample Input:
5
13
11 8
12 7 26
6 14 15 8
12 7 13 24 11

Sample Output:
86
 */

int get_minimal_sum( vector<vector<int>> map ){

	int n = map.size();

	int dp[n+1][n+1];
	mmeset(dp, 0, sizeof(dp));

	for(int i=0; i<n; i++)
		dp[n-1][i] = map[n-1][i];

	for(int i=n-2; i>=0; i--)
		for(int j=0; j<n; j++)
			if(dp[i+1][j] > dp[i+1][j+1])
				dp[i][j] = dp[i+1][j] + map[i][j];
			else
				dp[i][j] = dp[i+1][j+1] + map[i][j];

	return dp[0][0];
}

// 划分型动态规划    

// 1017  乘积最大

/*
设有一个长度为N的数字串，要求选手使用K个乘号将它分成K+1个部分，找出一种分法，使得这K+1个部分的乘积能够为最大。
 
同时，为了帮助选手能够正确理解题意，主持人还举了如下的一个例子：
 
有一个数字串：312， 当N=3，K=1时会有以下两种分法：
 
1)  3*12=36
2)  31*2=62
  
   这时，符合题目要求的结果是：31*2=62
 
   现在，请你帮助你的好朋友XZ设计一个程序，求得正确的答案。

程序的输入共有两行：
  第一行共有2个自然数N，K（6≤N≤40，1≤K≤6） 
  第二行是一个长度为N的数字串。

结果显示在屏幕上，相对于输入，应输出所求得的最大乘积（一个自然数）。

Sample Input:
4 2
1231

Sample Output:
62

 */


int get_maximal_multiply(vector<int> a, int k){
	int n = a.size();

	int g[n][n];
	memset(g, 0, sizeof(g));

	for(int i=0; i<n; i++)
		g[i][i] = a[i];

	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			g[i][j] = g[i][j-1]*10 + a[j];

	int f[n][n];
	memset(f, 0, sizeof(f));

	for(int i=1; i<=n; i++)
		f[i][0] = a[i];

	for(int i=1; i<=n; i++)
		for(int j=1; j<=i-1 && j<=k; j++)
			for(int l=0; l<=i-1; l++)
				f[i][j] = max(f[i][j], f[l][j-1]*g[l][i-1]);


	return f[n][k];
}


// 1039  数的划分

/*
将整数n分成k份，且每份不能为空，任意两种划分方案不能相同(不考虑顺序)。
例如：n=7，k=3，下面三种划分方案被认为是相同的。
1 1 5
1 5 1
5 1 1
问有多少种不同的分法。

输入：n，k (6<n<=200，2<=k<=6)

输出：一个整数，即不同的分法。

Sample Input:
7 3

Sample Output:
4

 */

// 深搜

int get_divide_sum( int n, int k){

	vector<int> tmp;
	int count = 0;
	dfs(n, k, 0, count, tmp);

	return count;
}

void dfs(int gap, int num, int start, int & count, vector<int> & tmp){
	if ( start > num )
		return;
	if( gap < 0 )
		return;

	if(gap == 0 && start == num){
		count ++;
	}

	int j = start == 0 ? 1 : tmp[start-1];    // tmp结果集中时刻保持递增的状态
	for(int i=j; i<=gap; i++){
		tmp[start] = i;
		dfs(gap-i,num,start+1,count,tmp);
	}
}

// 划分型动态规划

// Hint : f[i,j] = f[i-j, j] + f[i-1, j-1]

int get_divide_sum2(int n, int k){

	int f[n+1][k+1];
	memset(f, 0, sizeof(f));

	f[0][0] = 1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=k; j++)
			if( i>= j )
				f[i][j] = f[i-j][j] + f[i-1][j-1];

	return f[n][k];
}

// 1040  统计单词个数

/*
给出一个长度不超过200的由小写英文字母组成的字母串(约定;该字串以每行20个字母的方式输入，且保证每行一定为20个)。要求将此字母串分成k份(1<k<=40)，且每份中包含的单词个数加起来总数最大(每份中包含的单词可以部分重叠。当选用一个单词之后，其第一个字母不能再用。例如字符串this中可包含this和is，选用this之后就不能包含th)（管理员注：这里的不能再用指的是位置，不是字母本身。比如thisis可以算做包含2个is）。
单词在给出的一个不超过6个单词的字典中。
要求输出最大的个数。

第一行为一个正整数(0<n<=5)表示有n组测试数据
每组的第一行有二个正整数(p，k)
p表示字串的行数;
k表示分为k个部分。
接下来的p行，每行均有20个字符。
再接下来有一个正整数s，表示字典中单词个数。(1<=s<=6)
接下来的s行，每行均有一个单词。

每行一个整数，分别对应每组测试数据的相应结果。

Sample Input:
1
1 3
thisisabookyouareaoh
4
is
a
ok
sab

Sample Output:
7
 */

int get_maximal_words(string str, vector<string> dict, int k){

	int len = str.size();

	vector<vector<int>> words(len, vector<int>(len,0));

	for(int t=1; t<=len; t++)
		for(int i=0; i<t-k+1; i++)
		{
			int j = i + t - 1;
			bool yes = false;
			for(int idx = 0; idx < dict.size(); idx++)
				if(str.substr(i,j-i+1) == dict[idx]){
					yes = true;
					break;
				}

			if(yes) 
				word[i][j] = word[i][j-1] + 1;
			else 
				word[i][j] = word[i][j-1];
		}

	for( int st=1; st<=k; st++ )
		for( int i=0; i<len-st+1; i++)
			for( int j=i+st-1; j<len; j++)
			{
				if(st == 1){
					dp[i][j][st] = word[i][j];
					continue;
				}

				for(int l=i+st-2; l<j; l++){
					if (dp[i][j][st] < dp[i][l][st-1] + word[l+1][j])
						dp[i][j][st] = dp[i][l][st-1] + word[l+1][j];
				}
			}

	return dp[0][len-1][k];
}


// 1004 四子连棋

/*
在一个4*4的棋盘上摆放了14颗棋子，其中有7颗白色棋子，7颗黑色棋子，有两个空白地带，任何一颗黑白棋子都可以向上下左右四个方向移动到相邻的空格，这叫行棋一步，黑白双方交替走棋，任意一方可以先走，如果某个时刻使得任意一种颜色的棋子形成四个一线（包括斜线），这样的状态为目标棋局。

从文件中读入一个4*4的初始棋局，黑棋子用B表示，白棋子用W表示，空格地带用O表示。

用最少的步数移动到目标棋局的步数。

Sample Input:
BWBO
WBWB
BWBW
WBWO

Sample Output:
5

 */

struct Status{
	int step;
	int hash;
	int last;
	vector<vector<int>> map;
	Status(): step(0), hash(0), last(1) {}
};

int get_hash(Status a){
	int res = 0;
	int n = a.map.size();
	int m = a.map[0].size();

	int k = 1;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			res += a.map[i][j] * k;
			k *= 3;
		}

	return res;
}

bool check(Status a){
	for(int i=0; i<a.map.size(); i++)
		if(a.map[i][0] == a.map[i][1] )
			if(a.map[i][1] == a.map[i][2])
				if(a.map[i][2] == a.map[i][3])
					return true;

	for(int j=0; j<a.map[0].size(); j++)
		if(a.map[0][j] == a.map[1][j])
			if(a.map[1][j] == a.map[2][j])
				if(a.map[2][j] == a.map[3][j])
					return true;

	if(a.map[0][0] == a.map[1][1])
		if(a.map[1][1] == a.map[2][2])
			if(a.map[2][2] == a.map[3][3])
				return true;

	if(a.map[0][3] == a.map[1][2])
		if(a.map[1][2] == a.map[2][1])
			if(a.map[2][1] == a.map[3][0])
				return true;

	return false;
}

int get_minimal_step ( vector<string> mat ){
	int n = mat.size();
	int m = mat[0].size();

	vector<vector<int>> new_mat(n,vector<int>(m,0));

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(mat[i][j] == 'W')
				new_mat[i][j] = 1;
			else if (mat[i][j] == 'B')
				new_mat[i][j] = 2;
			else if (mat[i][j] == 'O')
				new_mat[i][j] = 0;

	queue<Status> q;

	Status first = new Status();

	first.map = new_mat;
	first.hash = get_hash(first);
	q.push(first);

	first.last = 2;
	q.push(first);

	while( !q.empty() ){
		Status a = q.front();
		q.pop();

		int start[2][2];
		memset(start,-1,sizeof(start));
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(a.map[i][j] == 0){
					if( start[0][0]==-1 && start[0][1]==-1 ){
						start[0][0] = i;
						start[0][1] = j;
					}else{
						start[1][0] = i;
						start[1][1] = j;
					}
				}

		int dx[4] = {-1, 0, 1, 0};
		int dy[4] = {0, 1, 0, -1};
		for(int i=0; i<2; i++)
			for(int k=0; k<4; k++){

				int nx = start[i][0] + dx[k];
				int ny = start[i][1] + dy[k];

				if( nx<0 || nx>=a.map.size() || ny<0 || ny>=a.map[0].size() )
					continue;
				if (a.map[nx][ny] != a.last)
					continue;

				Status new_a = new Status();
				new_a = a;

				new_a.last = 3 - a.last;
				new_a.step ++;

				int tmp = new_a.map[x][y];
				new_a.map[x][y] = new_a.map[nx][ny];
				new_a.map[nx][ny] = tmp;

				new_a.hash = get_hash(new_a);

				if(check(new_a))
					return new_a.step;

				q.push(new_a);
			}
	}

}


// 1026  逃跑的拉尔夫

/*
年轻的拉尔夫开玩笑地从一个小镇上偷走了一辆车，但他没想到的是那辆车属于警察局，并且车上装有用于发射车子移动路线的装置。
那个装置太旧了，以至于只能发射关于那辆车的移动路线的方向信息。
编写程序，通过使用一张小镇的地图帮助警察局找到那辆车。程序必须能表示出该车最终所有可能的位置。
小镇的地图是矩形的，上面的符号用来标明哪儿可以行车哪儿不行。“.”表示小镇上那块地方是可以行车的，而符号“X”表示此处不能行车。拉尔夫所开小车的初始位置用字符的“*”表示，且汽车能从初始位置通过。
汽车能向四个方向移动：向北(向上)，向南(向下)，向西(向左)，向东(向右)。
拉尔夫所开小车的行动路线是通过一组给定的方向来描述的。在每个给定的方向，拉尔夫驾驶小车通过小镇上一个或更多的可行车地点。

输入文件的第一行包含两个用空格隔开的自然数R和C，1≤R≤50，1≤C≤50，分别表示小镇地图中的行数和列数。
以下的R行中每行都包含一组C个符号(“.”或“X”或“*”)用来描述地图上相应的部位。
接下来的第R+2行包含一个自然数N，1≤N≤1000，表示一组方向的长度。
接下来的N行幅行包含下述单词中的任一个：NORTH(北)、SOUTH(南)、WEST(西)和EAST(东)，表示汽车移动的方向，任何两个连续的方向都不相同。

输出文件应包含用R行表示的小镇的地图(象输入文件中一样)，字符“*”应该仅用来表示汽车最终可能出现的位置。

Sample Input:
4 5
.....
.X...
...*X
X.X..
3
NORTH
WEST
SOUTH

Sample Output:
.....
*X*..
*.*.X
X.X..

 */

struct Node{
	int x;
	int y;
	Node(int _x, int _y): x(_x), y(_y) {}
};

vector<string> find_final_position(vector<string> map, vector<string> command){
	int row = map.size();
	int col = map[0].size();
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			if(map[i][j] == '*')
				bfs(map, i, j, command);
}

void bfs(vector<string> map, int i, int j, vector<string> command){

	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};

	vector<int> new_cmd;
	int len = command.size();
	for(int i=0; i<len; i++){
		if(command[i] == 'NORTH')
			new_cmd.push_back(0);
		else if (command[i] == 'SOUTH')
			new_cmd.push_back(2);
		else if (command[i] == 'WEST')
			new_cmd.push_back(3);
		else if (command[i] == 'EAST')
			new_cmd.push_back(1);
	}

	queue<node> q;
	Node nd = new Node(i,j);
	q.push(nd);

	map[i][j] = '.';

	int idx = 0;
	while( !q.empty() ){
		int num = q.size();
		for(int i=0; i<num; i++){
			Node old_nd = q.front();
			q.pop();

			int j=0;
			while( 1 ){

				int nx = old_nd.x + new_cmd[idx];
				int ny = old_nd.y + new_cmd[idx];
				if( nx>=0 && nx<map.size() && ny>=0 && ny<map[0].size() && map[nx][ny] != 'X'){
					Node new_nd = new Node(nx, ny);
					q.push(new_nd);
				}else{
					break;
				}
			}
		}
		idx++;
		if(idx == new_cmd.size()){
			break;
		}
	}

	while( !q.empty() ){
		Node nd = q.front();
		q.pop();

		map[nd.x][nd.y] = '*';
	}

	return map;
}


// 1099 字串变换

/*
已知有两个字串 A$, B$ 及一组字串变换的规则（至多6个规则）:
　　　　　A1$ -> B1$
　　　　　A2$ -> B2$
　　规则的含义为：在 A＄中的子串 A1$ 可以变换为 B1$、A2$ 可以变换为 B2$ …。
　　　　例如：A$＝'abcd'　B$＝'xyz'
　　变换规则为：
　　　　‘abc’->‘xu’　‘ud’->‘y’　‘y’->‘yz’

　　则此时，A$ 可以经过一系列的变换变为 B$，其变换的过程为：
　　　‘abcd’->‘xud’->‘xy’->‘xyz’

　　共进行了三次变换，使得 A$ 变换为B$。

输入格式如下：
　　　A$ B$
　　　A1$ B1$ \
　　　A2$ B2$  |-> 变换规则
　　　... ... / 
　　所有字符串长度的上限为 20。

若在 10 步（包含 10步）以内能将 A$ 变换为 B$ ，则输出最少的变换步数；否则输出"NO ANSWER!"

Sample Input:
abcd xyz
abc xu
ud y
y yz

Sample Output:
3

 */

int minimal_convert_steps(vector<string> left, vector<string> right, string a, string b){
	int step = 0;
	bfs(left, right, a, b, step);
	return step;
}

void bfs(vector<string> left, vector<string> right, string a, string b, int & step){
	int n = left.size();

	vector<string> q1,q2;   // 后面需要遍历队列， 故此处用vector来模拟queue   
	//但erase()时增加额外的时间复杂度

	q1.push_back(a);
	q2.push_back(b);

	while( !q1.empty() && !q2.empty() ){

		step++;
		if(step > 10){
			printf("No answer\n");
			return;
		}

		int num1 = q1.size();
		for(int i=0; i<num1; i++){
			string str = q1.front();
			q1.erase(0);
			for(int j=0; j<n; j++){
				int idx = str.find(left[j], 0);
				if(idx){
					string tmp = "";
					tmp += str.substr(0,idx+1);
					tmp += right[j];
					tmp += str.substr(idx+1, str.length()-idx-1);
					for(int k=0; k<q2.size(); k++)
						if(tmp == q2[k]){
							return;
						}
					q1.push(tmp);
				}
			}
		}

		int num2 = q2.size();
		for(int i=0; i<num2; i++){
			string str = q2.front();
			q2.erase(0);
			for(int j=0; j<n; j++){
				int idx = str.find(right[j], 0);
				if(idx){
					string tmp = "";
					tmp += str.substr(0,idx+1);
					tmp += left[j];
					tmp += str.substr(idx+1, str.length()-idx-1);
					for(int k=0; k<q1.size(); k++)
						if(tmp == q1[k]){
							return;
						}
					q2.push(tmp);
				}
			}
		}
	}
}


// 通过set来加快查找     set使用红黑树存储   在查找时需要logn的复杂度
void bfs2(vector<string> left, vector<string> right, string a, string b, int & step){
	int n = left.size();

	queue<string> q1,q2;
	set<string> s1, s2;

	q1.push_back(a);
	s1.insert(a);
	q2.push_back(b);
	s2.insert(b);

	while( !q1.empty() && !q2.empty() ){

		step++;
		if(step > 10){
			printf("No answer\n");
			return;
		}

		int num1 = q1.size();
		for(int i=0; i<num1; i++){
			string str = q1.front();
			q1.pop();
			s1.erase(s1.find(str));
			for(int j=0; j<n; j++){
				int idx = str.find(left[j], 0);
				if(idx){
					string tmp = "";
					tmp += str.substr(0,idx+1);
					tmp += right[j];
					tmp += str.substr(idx+1, str.length()-idx-1);
					
					if( s1.find(str) != s1.end() )
						return;

					q1.push(tmp);
					s1.insert(tmp);
				}
			}
		}

		int num2 = q2.size();
		for(int i=0; i<num2; i++){
			string str = q2.front();
			q2.pop();
			s2.erase(s2.find(str));
			for(int j=0; j<n; j++){
				int idx = str.find(right[j], 0);
				if(idx){
					string tmp = "";
					tmp += str.substr(0,idx+1);
					tmp += left[j];
					tmp += str.substr(idx+1, str.length()-idx-1);
					
					fi( s2.find(str) != s2.end() )
						return;

					q2.push(tmp);
					s2.insert(tmp);
				}
			}
		}
	}
}

// 深度优先搜索


// 1018  单词接龙

/*
单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次），在两个单词相连时，其重合部分合为一部分，例如beast和astonish，如果接成一条龙则变为beastonish，另外相邻的两部分不能存在包含关系，例如at和atide间不能相连。

输入的第一行为一个单独的整数n(n<=20)表示单词数，以下n行每行有一个单词，输入的最后一行为一个单个字符，表示“龙”开头的字母。你可以假定以此字母开头的“龙”一定存在.

只需输出以此字母开头的最长的“龙”的长度

Sample Input:
5
at
touch
cheat
choose
tact
a

Sample Output:
23

 */

int get_longest_sequence(vector<string> dict, char first){
	int n = dict.size();
	vector<vector<int>> f(n, vector<int>(n,-1));

	vector<int> use(n,0);

	int ans = 0;
	int res = 0x80000000;

	for(int i=0; i<n; i++)
		if(dict[i][0] == first){
			dfs(dict, i, f, first, ans+dict[i].size(), res);
		}
}

void dfs(vector<string> dict, int x, vector<vector<int>> & f, vector<int> & use, int & ans, int &res){

	use[x] ++;
	
	if(res < ans)
		res = ans;
	
	for(int y=0; y<dict.size(); y++){
		if(f[x][y]== -1 && check(dict,f,x,y) && use[y] < 2)
			dfs(dict,y,f,use,ans+len[y]-f[x][y], res);
	}

	use[x] -- ;
}

bool check(vector<string> dict, vector<vector<int>> f, int x, int y){
	int lenx = dict[x].size();
	int leny = dict[y].size();

	for(int i=lenx-1; i>0&&i>lenx - leny; i--){
		bool flag = true;
		for(int len=1,j=1; i+len<lenx && j<leny && flag; len++,j++)
			if(dict[x][i+len] != dict[y][j])
				flag = false;

		if(flag){
			f[x][y] = lenx - i + 1;
			return true;			
		}
	}
	f[x][y] = 0;
	return false;
}

// 1116 四色问题

/*
给定N（小于等于8）个点的地图，以及地图上各点的相邻关系，请输出用4种颜色将地图涂色的所有方案数（要求相邻两点不能涂成相同的颜色）
数据中0代表不相邻，1代表相邻

第一行一个整数n，代表地图上有n个点
接下来n行，每行n个整数，每个整数是0或者1。第i行第j列的值代表了第i个点和第j个点之间是相邻的还是不相邻，相邻就是1，不相邻就是0.
我们保证a[i][j] = a[j][i] （a[i,j] = a[j,i]）

染色的方案数

Sample Input:
8
0 0 0 1 0 0 1 0 
0 0 0 0 0 1 0 1 
0 0 0 0 0 0 1 0 
1 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
0 1 0 0 0 0 0 0 
1 0 1 0 0 0 0 0 
0 1 0 0 0 0 0 0

Sample Output:
15552
 */

int four_color (vector<vector<int>> map){

	int count = 0;
	vector<int> color(n,0);
	dfs(map, 0, count, color);
	return count;
}

void dfs(vector<vector<int>> map, int start, int & count, vector<int> & color){
	if ( start == map.size()){
		count ++;
	}

	for(int i=1; i<=4; i++){
		int ok = 1;
		for(int j=0; j<start; j++)
			if(map[start][j] && color[j] == i){
				ok = 0;
				break;
			}
		if(ok){
			color.push_back(i);
			dfs(map, start+1, count, color);
			color.pop_back();
		}
	}
}

// 1294  全排列

/*
给出一个n, 请输出n的所有全排列

读入仅一个整数n   (1<=n<=10)

一共n!行，每行n个用空格隔开的数，表示n的一个全排列。并且按全排列的字典序输出。

Sample Input : 
3

Sample Output:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

 */

vector<vector<int>> generate_permutation(vector<int> a){
	vector<vector<int>> res;

	vector<int> tmp;

	dfs(a, 0, tmp, res);
}

void dfs(vector<int> a, int start, vector<int> tmp, vector<vector<int>> res){

	if (start == a.size()){
		res.push_back(tmp);
	}

	for(int i=0; i<a.size(); i++){
		int ok = 1;
		for(int j=0; j<start; j++)
			if(tmp[j] == a[i]){
				ok = 0;
				break;
			}

		if(ok){
			tmp.push_back(a[i]);
			dfs(a,start+1,tmp,res);
			tmp.pop_back();
		}
	}
}

// 1295  N皇后问题

/*
在n×n格的棋盘上放置彼此不受攻击的n个皇后。按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。n后问题等价于再n×n的棋盘上放置n个皇后，任何2个皇后不妨在同一行或同一列或同一斜线上。

给定棋盘的大小n (n ≤ 13)

输出整数表示有多少种放置方法。

Sample Input:8

Sample Output:
92
 */

int n_queens(int n){
	int count = 0;

	vector<int> col(n,0);

	dfs(n, 0, count, col);
}

void dfs(int n, int start, int count, vector<int> & col){
	if(start == n){
		count ++;
	}

	for(int j = 0; j<n; j++){
		int ok = 1;
		for(int i=0; i<start; i++){
			if(col[i] == j || start+j == i+col[i] || start-j == i-col[i]){
				ok = 0;
				break;
			}
		}

		if(ok){
			col.push_back(j);
			dfs(n,start+1,count,col);
			col.pop_back(j);
		}
	}
}

// 通过vis数组降低时间复杂度

int n_queens2(int n){
	int count = 0;

	vector<vector<bool>> vis(3,vector<int>(n,false));

	dfs(n, 0, count, vis);
}

void dfs2(int n, int start, int count, vector<vector<int>> & vis){
	if(start == n){
		count ++;
	}

	for(int j=0; j<n; j++)
		if( !vis[0][j] && !vis[1][start+j] && !vis[2][start-j+n-1]){
			vis[0][j] = vis[1][start+j] = vis[2][start-j+n] = true;
			dfs(n, start+1, count, vis);
			vis[0][j] = vis[1][start+j] = vis[2][stat-j+n] = false;
		}
}