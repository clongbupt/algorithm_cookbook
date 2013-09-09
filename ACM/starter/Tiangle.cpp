#include<iostream>

using namespace std;

int main ()
{
	int num;
	
	while (cin >> num)
	{
		int stick[num];
		memset(stick, 0, sizeof(stick));    //初始化为0
		
		//根据题意已经排好序，无需sort
		for (int i = 0; i < num; i ++)
			cin >> stick[i];
		
		double area = -1;
		
		for (int i = 0; i < num - 2; i ++)
			for (int j = i + 1; j < num - 1; j ++)
				for (int k = j + 1; k < num; k ++)
					if (stick[i]*stick[i] + stick[j]*stick[j] == stick[k]*stick[k])
						if (0.5 * stick[i] * stick[j] > area)
							area = 0.5 * stick[i] * stick[j];
		if (area == -1)
			cout << "My God!" << endl;
		else       //保留三位小数输出
			printf("%.3lf", area);
	}
	
	return 0;
}