// https://codeforces.com/contest/2112/problem/C
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void init()
{
	return;
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int maxA = a[n - 1];
	long long ans = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			int sum = a[i] + a[j];
			int minValue = maxA - sum + 1;
			int maxValue = sum;
			auto beginIt = a.begin() + j + 1;
			int leftIndex = lower_bound(beginIt, a.end(), minValue) - beginIt;
			int rightIndex = lower_bound(beginIt, a.end(), maxValue) - beginIt - 1;
			if (leftIndex <= rightIndex)
			{
				ans += rightIndex - leftIndex + 1;
			}
		}
	}
	cout << ans << endl;
	return;
}
void fastRead()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int main()
{
	fastRead();
	init();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
