// https://codeforces.com/contest/1694/problem/B
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	long long ans = n;
	for (int i = 1; i < n; ++i)
	{
		if (str[i] != str[i - 1])
		{
			ans += i;
		}
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
