// https://codeforces.com/contest/1681/problem/A
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> Alice(n);
	int AliceMax = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> Alice[i];
		AliceMax = max(AliceMax, Alice[i]);
	}
	int m;
	cin >> m;
	vector<int> Bob(m);
	int BobMax = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> Bob[i];
		BobMax = max(BobMax, Bob[i]);
	}
	if (AliceMax >= BobMax)
	{
		cout << "Alice" << endl;
	}
	else
	{
		cout << "Bob" << endl;
	}
	if (AliceMax > BobMax)
	{
		cout << "Alice" << endl;
	}
	else
	{
		cout << "Bob" << endl;
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
