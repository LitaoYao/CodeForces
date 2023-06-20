// https://codeforces.com/contest/1717/problem/A
#include <iostream>
using namespace std;
void solve()
{
	long long n;
	cin >> n;
	long long ans = n / 3 * 2 + n / 2 * 2 + n;
	cout << ans << endl;
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
