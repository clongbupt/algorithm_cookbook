#include "cstdio"  
#include "cstdlib"
#include "cstring"
#include "algorithm"
#include "ctime"
#include "queue"
#include "vector"
#include "utility"
#include "map" 
#include "iostream"


//#define DEBUG  

using namespace std;  


// Here to edit other function

typedef struct{
	int x; 
	int y;
} node;

vector<node> vec;
void qsort();


int main(void){

#ifdef DEBUG    
	freopen("J.in","r",stdin); 
    //freopen("test.out","w",stdout);   
#endif    
	
	int x, y, i, j, k,  v , w, lines;
	queue<node> q;
	char buf[10];
	char dir;
	node *np, n, m;
	while(scanf("%d", &x)==1)
	{
		vec.clear();
		scanf("%d", &y);
		scanf("%d", &lines);
		if(lines <= 0)
		{
			printf("%d %d\n", x, y);
			continue;
		}
		
		m.x = x;
		m.y = y;
		q.push(m);
		for(i=0; i<lines ; i++)
		{
			n = q.front();
			vec.push_back(n);
			q.pop();
			v = n.x;
			w = n.y;
			
			scanf("%s", buf);
			if(buf[0]=='#')
			{
				m.x=10000;
				m.y=10000;
				//q.push(m);
				continue;
			}
			for(j=0; j<10 && buf[j]!='#'; j++)
			{
				v = n.x;
				w = n.y;		
				
				switch(buf[j])
				{
					case 'N':
						w++;
						break;
					case 'S':
						w--;
						break;
					case 'W':
						v--;
						break;
					case 'E':
						v++;
						break;
				}
				
				m.x = v;
				m.y = w;
				q.push(m);
				
			}
		
			
			
		}//for
		
		while(!q.empty())
		{
			n = q.front();
			vec.push_back(n);
			q.pop();
		}
		qsort();
		
		
	}//while
	
#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
	system("pause");
#endif 

	return 0;  
}  

bool rule(const node&n1, const node&n2)
{
	if(n1.x<n2.x)
		return true;
	if(n1.x>n2.x)
		return false;
	if(n1.y>n2.y)
		return false;
	if(n1.y<n2.y)
		return true;
	
	return false;	
	
}

void qsort()
{
	//cout<<n.x<<" "<<n.y<<endl;
	sort(vec.begin(), vec.end(), rule);
	for(vector<node>::iterator it = vec.begin(); it!=vec.end(); it++)
		cout<<it->x<<" "<<it->y<<endl;
	
}