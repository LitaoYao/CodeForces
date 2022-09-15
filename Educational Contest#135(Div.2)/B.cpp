// https://codeforces.com/contest/1728/problem/B
#include <iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	if ((n & 1) == 0)
	{
		for (int i = n - 2; i >= 1; --i)
		{
			cout << i << " ";
		}
		cout << n - 1 << " " << n << endl;
	}
	else
	{
		cout << n - 1 << " ";
		for (int i = n - 3; i >= 2; --i)
		{
			cout << i << " ";
		}
		cout << 1 << " " << n - 2 << " " << n << endl;
	}
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
