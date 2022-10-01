// https://codeforces.com/contest/1739/problem/A
#include <iostream>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	if (n > 3 && m > 3)
	{
		cout << 1 << " " << 1 << endl;
	}
	else
	{
		cout << (n + 1) / 2 << " " << (m + 1) / 2 << endl;
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
