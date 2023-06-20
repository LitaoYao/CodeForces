// https://codeforces.com/contest/1843/problem/D
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dfs(vector<vector<int>>& edges, vector<int>& reachEndCount, vector<int>& visit, int x)
{
	bool isEnd = true;
	for (int y : edges[x])
	{
		if (visit[y])
		{
			continue;
		}
		isEnd = false;
		visit[y] = 1;
		reachEndCount[x] += dfs(edges, reachEndCount, visit, y);
	}
	if (isEnd)
	{
		reachEndCount[x] = 1;
	}
	return reachEndCount[x];
}
void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> edges(n + 1);
	vector<int> reachEndCount(n + 1);
	vector<int> visit(n + 1);
	int u, v;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	visit[1] = 1;
	dfs(edges, reachEndCount, visit, 1);
	int q, x, y;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> x >> y;
		cout << (long long)reachEndCount[x] * (long long)reachEndCount[y] << endl;
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
