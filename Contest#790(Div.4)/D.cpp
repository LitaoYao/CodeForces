// https://codeforces.com/contest/1676/problem/D
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		cin >> m;
		vector<vector<int>> grid(n, vector<int>(m));
		vector<vector<int>> leftTop(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> grid[i][j];
				if (i == 0 || j == 0)
				{
					leftTop[i][j] = grid[i][j];
				}
				else
				{
					leftTop[i][j] = leftTop[i - 1][j - 1] + grid[i][j];
				}
			}
		}
		vector<vector<int>> rightTop(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (i == 0 || j == m - 1)
				{
					rightTop[i][j] = grid[i][j];
				}
				else
				{
					rightTop[i][j] = rightTop[i - 1][j + 1] + grid[i][j];
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int leftTopDiff = min(n - i - 1, m - j - 1);
				int rightTopDiff = min(n - i - 1, j);
				int tmpAns = leftTop[i + leftTopDiff][j + leftTopDiff]
					+ rightTop[i + rightTopDiff][j - rightTopDiff]
					- grid[i][j];
				ans = max(ans, tmpAns);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
