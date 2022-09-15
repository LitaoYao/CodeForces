// https://codeforces.com/contest/1695/problem/A
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	int maxNum = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
			maxNum = max(maxNum, grid[i][j]);
		}
	}
	int x, y;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == maxNum)
			{
				x = i;
				y = j;
			}
		}
	}
	cout << max(x + 1, n - x) * max(y + 1, m - y) << endl;
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
