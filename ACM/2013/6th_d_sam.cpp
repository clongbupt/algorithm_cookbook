#define DEBUG

#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<stack>
using namespace std;
typedef long long llong;
const double EPS=1e-9;
const double Pi=acos(-1.0);
int Fa[2500],Cnt[2500];
int GetFa(int x)
{
    if (Fa[x]==x)
       return x;
    return Fa[x]=GetFa(Fa[x]);
}
void Merge(int x,int y)
{
     Fa[GetFa(x)]=Fa[GetFa(y)];
}
int GetDate(char s[])
{
    int x=(s[0]-'0')*10+s[1]-'0';
    int y=(s[3]-'0')*10+s[4]-'0';
    return x*60+y;
}
int main()
{

#ifdef  DEBUG
    freopen("6th_D_in.txt","r",stdin);
    freopen("6th_D_out.txt","w",stdout);
#endif

    int T,i,K,N;
    char st[10];
    scanf("%d",&T);
    while (T--)
    {
          for (i=0;i<2450;i++)
          {
              Fa[i]=i;
              Cnt[i]=0;
          }
          scanf("%d",&N);
          for (i=0;i<N;i++)
          {
              scanf("%d",&K);
              while (K--)
              {
                    scanf("%s",st);
                    Merge(i,GetDate(st)+1000);
              }
          }
          for (i=0;i<N;i++)
              Cnt[GetFa(i)]++;
          sort(Cnt,Cnt+2440);
          for (i=0;Cnt[i]==0;i++);
          printf("%d\n%d",2440-i,Cnt[i]);
          for (i++;i<2440;i++)
              printf(" %d",Cnt[i]);
          puts("");
    }
    return 0;
}
