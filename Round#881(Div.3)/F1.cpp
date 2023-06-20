// https://codeforces.com/contest/1843/problem/F1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> maxSum(n + 2, 0);
	vector<int> maxToSum(n + 2, 0);
	vector<int> minSum(n + 2, 0);
	vector<int> minToSum(n + 2, 0);
	int num = 1;
	minSum[num] = 0;
	maxSum[num] = 1;
	maxToSum[num] = 1;
	minToSum[num] = 1;
	char op;
	int u, v, x;
	for (int i = 0; i < n; ++i)
	{
		cin >> op;
		if (op == '+')
		{
			cin >> u >> x;
			++num;
			if (x == 1)
			{
				maxToSum[num] = max(maxToSum[u] + 1, 1);
				minToSum[num] = min(minToSum[u] + 1, 0);
			}
			else
			{
				maxToSum[num] = max(maxToSum[u] - 1, 0);
				minToSum[num] = min(minToSum[u] - 1, -1);
			}
			maxSum[num] = max(maxToSum[num], maxSum[u]);
			minSum[num] = min(minToSum[num], minSum[u]);
		}
		else
		{
			cin >> u >> v >> x;
			if (minSum[v] <= x && maxSum[v] >= x)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
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
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
