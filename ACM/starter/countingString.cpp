#include<iostream>

using namespace std;

struct abc{
	int num;
	char str[21];
} que[200010];

int cmp(const void *a, const void *b)
{
	abc *f1 = (abc *)a;
	abc *f2 = (abc *)b;
	return strcmp(f1->str, f2->str);
}

int main ()
{
	vector < string > array;
	int count[100010];
	int cases = 0;
	int number;
	while (cin >> number)
	{
		array.resize(number);
		for (int i = 0; i < number; i ++)
			cin >> array[i];
		
		qsort(array, number, sizeof(array), cmp);
	}
}

int main()
{
	int count[200010];
	int cases = 0;
	int number;
	while (cin >> number)
	{
		for (int i = 0; i < number; i ++)
		{
			cin >> que[i].str;
			que[i].num = 0;
			count[i] = 0;
		}
		//所有字符串按字典排序
		qsort(que, number, sizeof(que[0]), cmp);
		
		int i = 1, j = 1;
		while (i < number)
		{
			if (strcmp(que[i].str, que[i - 1].str) == 0)   //比较相邻的两个字符串
			{
				j ++;    //相同字符串的个数增加
				i ++;    //向下移动
				continue;
			}
			count[j] ++;    //相同几个字符串的位置加一
			j = 1;          //重新开始
			i ++;           //向下移动
		}
		
		count[j] ++;
		cout << "Case " << ++cases << endl;
		
		for (int i = 0; i < number; i ++)
		{
			if (count[i] > 0)
				cout << i << " " << count[i] << endl;
		}
	}
	
	return 0;
}