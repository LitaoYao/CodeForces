#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
bool isValid(vector<vector<int>>& grid, int n, int x, int y)
{
	bool possible = true;
	for (int i = 1; i <= n; ++i)
	{
		swap(grid[i][x], grid[i][y]);
		possible &= (grid[i][x] >= grid[i][x - 1]);
		possible &= (grid[i][x] <= grid[i][x + 1]);
		possible &= (grid[i][y] >= grid[i][y - 1]);
		possible &= (grid[i][y] <= grid[i][y + 1]);
		swap(grid[i][x], grid[i][y]);
		if (!possible)
		{
			break;
		}
	}
	return possible;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n + 1, vector<int>(m + 2, 0));
	vector<vector<int>> goodGrid(n + 1, vector<int>(m + 2, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> grid[i][j];
			goodGrid[i][j] = grid[i][j];
		}
		grid[i][m + 1] = INT_MAX;
		goodGrid[i][m + 1] = INT_MAX;
	}
	set<int> errorColumns;
	for (int i = 1; i <= n; ++i)
	{
		sort(goodGrid[i].begin(), goodGrid[i].end());
		for (int j = 1; j <= m; ++j)
		{
			if (goodGrid[i][j] != grid[i][j])
			{
				errorColumns.insert(j);
			}
		}
	}
	vector<int> allColumns;
	for (int column : errorColumns)
	{
		allColumns.push_back(column);
	}
	int columnSize = allColumns.size();
	if (columnSize == 0)
	{
		cout << 1 << " " << 1 << endl;
	}
	else if (columnSize == 1)
	{
		int x = allColumns[0];
		bool possible = false;
		for (int y = 1; y <= m; ++y)
		{
			if (isValid(grid, n, x, y))
			{
				possible = true;
				cout << x << " " << y << endl;
				break;
			}
		}
		if (!possible)
		{
			cout << -1 << endl;
		}
	}
	else if (columnSize == 2)
	{
		int x = allColumns[0];
		int y = allColumns[1];
		if (isValid(grid, n, x, y))
		{
			cout << x << " " << y << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	else if (columnSize > 2)
	{
		cout << -1 << endl;
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
