// https://codeforces.com/contest/1719/problem/A
#include <iostream>
using namespace std;
void solve()
{
	long long n, m;
	cin >> n >> m;
	if (((n + m) & 1) == 1)
	{
		cout << "Burenka" << endl;
	}
	else
	{
		cout << "Tonya" << endl;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
