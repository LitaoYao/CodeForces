#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dfs(vector<vector<int>>& children, vector<int>& colors, int node, vector<int>& res)
{
	res[node] = colors[node];
	for (int child : children[node])
	{
		res[node] += dfs(children, colors, child, res);
	}
	return res[node];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<vector<int>> children(n, vector<int>());
		for (int i = 1; i < n; ++i)
		{
			int parent;
			cin >> parent;
			children[parent - 1].push_back(i);
		}
		vector<int> colors(n);
		string colorString;
		cin >> colorString;
		for (int i = 0; i < n; ++i)
		{
			if (colorString[i] == 'W')
			{
				colors[i] = 1;
			}
			else
			{
				colors[i] = -1;
			}
		}
		vector<int> res(n);
		dfs(children, colors, 0, res);
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if (res[i] == 0)
			{
				++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
