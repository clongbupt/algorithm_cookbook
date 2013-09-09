#include "cstdio"
#include "vector"

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target){
	int len = numbers.size();

	vector<int> result;

	for(int i=0; i<len-1; i++)
		for(int j=i+1; j<len; j++)
			if(numbers[i] + numbers[j] == target)
			{
				result.clear();
				result.push_back(i+1);
				result.push_back(j+1);
				return result;
			}
}


int main(int argc, char const *argv[])
{
	vector<int> number;
	number.push_back(0);
	number.push_back(1);
	number.push_back(3);
	number.push_back(7);
	int target = 8;

	vector<int> res = twoSum(number,target);

	for(int i=0; i<res.size(); i++){
		printf("%d\n", res[i]);
	}
	
	return 0;
}