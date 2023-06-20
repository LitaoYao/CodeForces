// https://codeforces.com/contest/1709/problem/B
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<long long> heights(n);
	vector<long long> diff(n, 0);
	vector<long long> sum1(n, 0);
	vector<long long> sum2(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> heights[i];
		if (i > 0)
		{
			diff[i] = heights[i - 1] - heights[i];
		}
	}
	for (int i = 1; i < n; ++i)
	{
		sum1[i] = sum1[i - 1] + (diff[i] > 0 ? diff[i] : 0);
	}
	for (int i = n - 2; i >= 0; --i)
	{
		sum2[i] = sum2[i + 1] + (diff[i + 1] < 0 ? -diff[i + 1] : 0);
	}
	int s, t;
	for (int j = 0; j < m; ++j)
	{
		cin >> s >> t;
		--s;
		--t;
		if (s < t)
		{
			cout << sum1[t] - sum1[s] << endl;
		}
		else
		{
			cout << sum2[t] - sum2[s] << endl;
		}
	}
	return;
}
int main()
{
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}
