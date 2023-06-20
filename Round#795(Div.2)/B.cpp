// https://codeforces.com/contest/1691/problem/B
#include <iostream>
#include <vector>
#include <map>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> shoes(n);
	map<int, vector<int>> groups;
	for (int i = 0; i < n; ++i)
	{
		cin >> shoes[i];
		groups[shoes[i]].push_back(i);
	}
	bool valid = true;
	vector<int> p(n);
	for (auto group : groups)
	{
		if (group.second.size() < 2)
		{
			valid = false;
			break;
		}
		else
		{
			int groupSize = group.second.size();
			for (int i = 0; i < groupSize; ++i)
			{
				p[group.second[i]] = group.second[(i + 1) % groupSize];
			}
		}
	}
	if (valid)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << p[i] + 1 << " ";
		}
		cout << endl;
	}
	else
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
