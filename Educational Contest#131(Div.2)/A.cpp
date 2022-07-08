#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	vector<vector<int>> grid(2, vector<int>(2));
	int count = 0;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 1)
			{
				++count;
			}
		}
	}
	if (count == 0)
	{
		cout << 0 << endl;
	}
	else if (count <= 3)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 2 << endl;
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
