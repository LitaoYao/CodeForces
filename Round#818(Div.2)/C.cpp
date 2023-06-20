// https://codeforces.com/contest/1717/problem/C
#include <iostream>
using namespace std;
const int N = 2 * 1e5;
int a[N + 10];
int b[N + 10];
int n;
void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	bool valid = true;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == b[i])
		{
			continue;
		}
		if (a[i] > b[i])
		{
			valid = false;
		}
		if (b[i] > b[(i + 1) % n] + 1)
		{
			valid = false;
		}
		if (!valid)
		{
			break;
		}
	}
	cout << (valid ? "YES" : "NO") << endl;
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
