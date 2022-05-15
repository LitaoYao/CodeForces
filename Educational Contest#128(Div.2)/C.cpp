#include <iostream>
#include <vector>
#include <string>
using namespace std;
int findIndex(vector<int>& nums, int x, int left, int right)
{
	while (left < right)
	{
		int mid = (left + right) >> 1;
		if (x >= nums[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}
void solve()
{
	string str;
	cin >> str;
	int n = str.size();
	vector<int> zeroCount(n + 2, 0);
	vector<int> oneCount(n + 2, 0);
	for (int i = 1; i <= n; ++i)
	{
		int zero = 0;
		if (str[i - 1] == '0')
		{
			zero = 1;
		}
		zeroCount[i] = zeroCount[i - 1] + zero;
		oneCount[i] = oneCount[i - 1] + (1 - zero);
	}
	oneCount[n + 1] = oneCount[n];
	int ans = oneCount[n];
	for (int i = 1; i <= n; ++i)
	{
		int rightOne = oneCount[n + 1] - oneCount[i];
		int leftZero = zeroCount[i];
		if (leftZero <= rightOne)
		{
			ans = min(ans, rightOne);
		}
		else
		{
			int index = leftZero - rightOne;
			if (index <= i)
			{
				ans = min(ans, max(zeroCount[i] - zeroCount[index], rightOne + oneCount[index]));
			}
		}
	}
	cout << ans << endl;
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
