// https://codeforces.com/contest/1682/problem/A
#include <iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 1;
	int mid = n / 2;
	int mid1 = mid + 1;
	while (mid1 < n && s[mid1] == s[mid])
	{
		++mid1;
		++ans;
	}
	ans *= 2;
	if (n % 2 != 0)
	{
		ans -= 1;
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
