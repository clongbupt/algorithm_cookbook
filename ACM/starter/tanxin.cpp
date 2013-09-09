#include<iostream>

using namespace std;

int main()
{
	int s, d;
	while (cin >> s >> d)
	{
		int i, ans;
		for (int i = 1; i <= 5; i ++)
			if (s * (5 - i) - d * i < 0)
				break;
		
		if (i == 4)
			ans = 3 * s - 9 * d;
		else
			ans = s * (12 - 2 * i) - d * 2 * i;
		if (i == 5 || ans < 0)
			cout << "Deficit" << endl;
		else
			cout << ans << endl;
	}
	
	return 0;
}