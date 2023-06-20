// https://codeforces.com/contest/1716/problem/A
#include <iostream>
using namespace std;
void solve()
{
	long long n;
	cin >> n;
	long long ans;
	if (n == 1)
	{
		ans = 2;
	}
	else
	{
		ans = n / 3;
		if (n % 3 != 0)
		{
			++ans;
		}
	}
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
