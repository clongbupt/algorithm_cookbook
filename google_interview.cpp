// google SET


//第一面：
//给一个字符串，求用空格分隔出的段数


if (str == NULL || len <= 0)
    return 0;
if (*str == '\0')
    return 0;

// 如果没有连续空格
int count = 1;
while(*str != '\0'){
    if(*str == ' ')
        count ++;
    str++;
}

// 如果有连续空格  ??
char *pre = NULL;
char *cur = str;
int count = 0;
while(*cur != '\0'){
    if(pre != NULL && *cur == ' ' && *pre != ' ')
        count ++;

    pre = cur;
    cur++;
}

return count;


围棋棋盘上，放好了一些黑棋，求被黑棋围起来的点的数目，被棋盘边缘包围的不算

// 第二面
// pow(x,y)，递归、非递归，给出测试用例

double pow(int x, int y){
    if (x==0)
        return 0;
    if(y==0)
        return 1;

    bool negative = false;
    if(y<0)
        negative = true;

    if(negative)
        y = -y;

    double result = 1;
    while(y){
        if(y&1)
            result += x;
        y >> 1;
        x *= x;
    }

    if (negative) result = 1/result;
    return result;
}

// 跳表的概念
// A skip list is a data structure for storing a sorted list of items 
// using a hierarchy of linked lists that connect increasingly sparse subsequences of the items. 
// These auxiliary lists allow item lookup with efficiency comparable to balanced binary search trees 
// (that is, with number of probes proportional to log n instead of n).

// 第三面

// 从公交车刷卡记录求出A、B两站的平均时间（之前面经里有，但没动手写过，于是悲剧的只写了这一道题，血淋淋的教训啊）

//第四面

// 怎么测试一个计时器类
include "ctime"
include "limits"

class Timer
{
private:
    std::clock_t m_startTime;
    std::clock_t m_restartTime;
    std::clock_t m_elapsedTime;

public:
    Timer();

    void restart();  // 重启定时器

    void pause();    // 暂停定时器

    void resume();   // 恢复计时

    bool isPaused() const;  // 判断定时器是否处于暂停状态

    double elapsed() const;  // 计时器的流逝值

    double elapsedMax() const;   // 计时器的最大流逝值

    double elapsedMin() const;    // 计时器的最小流逝值
};

Timer::Timer()
{
    restart();
    m_startTime = m_restartTime;
}

void Timer::restart(){
    m_bPaused = false;
    m_restartTime=std::clock();
    m_elapsedTime=0;
}

void Timer::pause(){
    m_bPaused = true;
    m_elapsedTime+=std::clock() - m_restartTime;
}

bool Timer::isPaused() const{
    return m_bPaused;
}

double Timer::elapsed() const{
    if (!isPaused())
    {
        return double(m_elapsedTime+std::clock()-m_brestartTime)/double(CLOCKS_PER_SEC);
    }else
    {
        return double(m_elapsedTime)/double(CLOCKS_PER_SEC);
    }
}

double Timer::elapsedMax() const{
    return (double((std::numeric_limits<std::clock_t>::max)() - double(m_startTime) ) / double(CLOCKS_PER_SEC);
}

double Timer::elapsedMin() const{
    return double(1)/double(CLOCKS_PER_SEC);
}

/*
主要包含功能测试，性能测试

功能测试  各个功能是否运行正常   测试用例

性能测试  整体性能如何   CPU占用率  内存占用情况
 */


// 一个用char[]存放的二进制流，里面有两种编码，以0开头的8位ascii，以1开头的16位unicode，现在给一个char* p指向一个合法的字符的开头，求上一个字符的位置

bool inValidInput = true;
char * get_prevous_position (char str[], int len, char *p){
    if(str == NULL || len <= 0)
        return NULL;

    if(p <= str){
        inValidInput = true;
        return str;
    }

    if( (p-1)>=str && *(p-1)&0x80 == 0 )
        return (p-1);
    else if( (p-2)>=str && *(p-1)&0x80 == 1 )
        return (p-2);
    else{
        inValidInput = true;
        return str;
    }
}

// 电面

/*
1. 算法题
   已知一棵树的前序遍历和中序遍历，恢复整个树。要求写代码（Google Document 上）。
   然后分析最优最坏以及平均复杂度，并分别构造一个 test case。
*/

struct BinaryTreeNode{
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    int value;
};

BinaryTreeNode * recover_tree(int pre_order[], int in_order[], int len){
    
    int start = 0;

    return compute(pre_order, in_order, len, start);

}

BinaryTreeNode * compute(int pre_order[], int in_order[], int len, int start){

    int root_in_order;

    for(int i=0; i<len; i++)
        if(in_order[i] == pre_order[start]){
            root_in_order = i;
            break;
        }

    BinaryTreeNode *root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));

    root->left = compute(pre_order, in_order, len, start+1);
    root->right = compute(pre_order, in_order, len, start+root_in_order+1);

}


/*
2. 设计题
   设计一个用户访问控制系统，控制每个用户在一段时间内的访问频次。
   首先要求设计接口，写出代码。
   然后对不同情况设计算法：
   a) 每分钟不超过 10 次
   b) 每天不超过 10^6 次
 */


// 一面

/*
1. 算法题
   a) 已知一个数组 A，求满足 i<j 的 max{A[i]-A[j]}
   b) 已知一个字典和一个字母矩阵，求出字典中所有满足下述条件的单词：
      从矩阵的某一个字母开始，往它的八邻域行走，到另一个字母处结束，经过的路径刚好形成这个单词。
      路径不允许出现环。
      要求写代码。
 */
dx = {-1,  0,  1,  1, 1, 0, -1, -1};
dy = {-1, -1, -1, -1, 0, 1,  1, 0 };

vector<string> dfs (vector<string> list, char *G, int n, int m){

    dfs();
}

void dfs(){
    if(cur = )


    for(int i=0; i<list.size(); i++){
        string word = list[i];
        for(int j=0; j<word.size(); j++){
            for(int k=0; k<8; k++){
                nx = x + dx[i];
                ny = y + dy[i];
                if (!visited[nx][ny] && g[nx][ny] == word[j])
                    dfs();
            }
        }
    }
}

/*
2. 设计题

   有一个非常长的 Unicode (UTF-16) 字符串，统计其中出现次数的最多的字符。

   设计一个多节点的并行处理架构，要求尽可能减少节点和节点之间的信息交换量。
 */


/*
a) 生成 1 到 n 的全排列，并以字典序顺序生成。
 */

vector<string> generate_permutation(int n){

}

/*
b) 已知一颗多叉树的两个节点，求两者的最近公共祖先。
 */

// 思路: 先通过深搜或遍历拿到两个节点的路径  然后求两个路径的最后一个相同节点  返回该节点便是最近公共祖先

// 三面

/*
给定很多矩形，求这些矩形的并组成的形状的轮廓线，并用新的一系列不相交的矩形表示出这个形状。
      我说用线段树的算法以后面试官要求我分析线段树的插入和删除的复杂度。
      我简单的描述了一下，面试官不满意，他说他要的是严格的数学证明，只好吭哧吭哧给列式子算，这期间口语承受了巨大的压力……
 */


/*
从 1 到 n+1 这 n+1 个数中删除某一个，形成一个长度为 n 的数组，并以增序排列，设计算法找到缺失的那个数。
      要求写代码。
 */

// 思路 : O(n)算法


// 四面

/*
什么是读写锁？写代码实现一个读写锁。
 */


/*
已知数组 [a1,a2...am] [b1,b2...bn]，从小到大输出 ai+bj (1<=i<=m,1<=j<=n) 中前 K 大的数。
 */

// 微软面试题   思路: 构造最小堆然后求前K大的数


// 五面

/*
a) 已知一个很长的字符串，求一个最长子串使其满足：该子串中出现的字符种类不超过 2 种。
 */



/*
b) 把 2 种改成 k 种，给出算法，并问能否简单的修改上一题代码以满足要求。
 */