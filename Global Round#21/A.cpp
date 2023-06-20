// https://codeforces.com/contest/1696/problem/A
#include <iostream>
using namespace std;
void solve()
{
	long long n, z;
	cin >> n >> z;
	long long x;
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		ans = max(ans, x | z);
	}
	cout << ans << endl;
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
