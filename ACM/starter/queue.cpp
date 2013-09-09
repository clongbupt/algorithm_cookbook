#include<iostream>
#include<queue>

using namespace std;

#define MAXSIZE 5000

// int main()
// {
	// int number;
	// int card[MAXSIZE];
	
	// while(cin >> number)         //测试组数
	// {
		// for (int i = 0; i < number; i ++)    //数组初始化为牌序列
			// card[i] = i + 1;
		// int front = 0, rear = number - 1;    //数组头尾
		// while (front <= rear)
		// {
			// cout << card[front] << " ";
			// front ++;
			// rear ++;
			// card[rear] = card[front];
			// front ++;
		// }
		// cout << endl;
	// }
	// return 0;
// }

int main ()
{
	queue < int > card;
	int number;
	
	while (cin >> number)
	{
		for (int i = 0; i < number; i ++)
			card.push(i + 1);
		while (!card.empty())
		{
			cout << card.front() << " ";
			card.pop();
			card.push(card.front());
			card.pop();
		}
		cout << endl;
	}
	return 0;
}