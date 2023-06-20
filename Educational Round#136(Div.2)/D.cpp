// https://codeforces.com/contest/1739/problem/D
#include <iostream>
#include <vector>
using namespace std;
int dfs(vector<vector<int>>& edges, int now, int nowDeep, int deep, int& count)
{
	int finalDeep = 0;
	for (const int& next : edges[now])
	{
		finalDeep = max(finalDeep, dfs(edges, next, nowDeep + 1, deep, count) + 1);
	}
	// 子树深度为deep - 1 则需要干掉，但如果刚好是连根，或者刚好就是根，则不用干掉
	if (finalDeep == deep - 1 && now != 1 && nowDeep != 1)
	{
		++count;
		finalDeep = -1;
	}
	return finalDeep;
}
bool check(vector<vector<int>>& edges, int deep, int k)
{
	int count = 0;
	dfs(edges, 1, 0, deep, count);
	return count <= k;
}
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> edges(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		int parent;
		cin >> parent;
		edges[parent].push_back(i);
	}
	int left = 1;
	int right = n - 1;
	int ans = n;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (check(edges, mid, k))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans << endl;
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
