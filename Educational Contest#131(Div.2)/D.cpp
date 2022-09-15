// https://codeforces.com/contest/1701/D
#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{
	if (a[0] != b[0])
	{
		return a[0] < b[0];
	}
	else
	{
		return a[1] < b[1];
	}
}
void solve()
{
	int n;
	cin >> n;
	vector<int> b(n + 1);
	vector<vector<pair<int, int>>> a(n + 1, vector<pair<int, int>>());
	for (int i = 1; i <= n; ++i)
	{
		cin >> b[i];
		int L = i / (b[i] + 1) + 1;
		int R;
		if (b[i] == 0)
		{
			R = n;
		}
		else
		{
			R = i / b[i];
		}
		a[L].push_back({R, i});
	}
	vector<int> ans(n + 1);
	set<pair<int, int>> s;
	for (int i = 1; i <= n; ++i)
	{
		for (pair<int, int>& p : a[i])
		{
			s.insert(p);
		}
		ans[s.begin()->second] = i;
		s.erase(s.begin());
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
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
