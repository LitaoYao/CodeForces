#include <iostream>
#include <string>
using namespace std;
void solve()
{
	string nums;
	cin >> nums;
	int n = nums.size();
	if (n == 2)
	{
		cout << nums[1] << endl;
	}
	else
	{
		char minNum = '9';
		for (int i = 0; i < n; ++i)
		{
			if (minNum >= nums[i])
			{
				minNum = nums[i];
			}
		}
		cout << minNum << endl;
	}
	return;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
