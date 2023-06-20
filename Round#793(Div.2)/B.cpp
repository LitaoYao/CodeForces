// https://codeforces.com/contest/1682/problem/B
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	int ans = -1;
	for (int i = 0; i < n; ++i)
	{
		if (nums[i] != i)
		{
			if (ans == -1)
			{
				ans = nums[i];
			}
			else
			{
				ans &= nums[i];
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
