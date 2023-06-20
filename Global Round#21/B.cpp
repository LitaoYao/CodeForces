// https://codeforces.com/contest/1696/problem/B
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<long long> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	int times = 0;
	for (int i = 0; i < n; ++i)
	{
		if (nums[i] != 0)
		{
			++times;
		}
		while (nums[i] != 0 && i < n)
		{
			++i;
		}
	}
	cout << min(times, 2) << endl;
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
