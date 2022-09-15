// https://codeforces.com/contest/1680/problem/B
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	int minTop = INT_MAX;
	int minLeft = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'R')
			{
				minTop = min(minTop, i);
				minLeft = min(minLeft, j);
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == 'R')
			{
				if (i <= minTop && j <= minLeft)
				{
					cout << "YES" << endl;
					return;
				}
			}
		}
	}
	cout << "NO" << endl;
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
