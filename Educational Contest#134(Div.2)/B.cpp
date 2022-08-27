#include <iostream>
using namespace std;
void solve()
{
	int n, m, x, y, d;
	cin >> n >> m >> x >> y >> d;
	bool valid = true;
	if (x - d <= 1 && x + d >= n)
	{
		valid = false;
	}
	if (y - d <= 1 && y + d >= m)
	{
		valid = false;
	}
	if (x - d <= 1 && y - d <= 1)
	{
		valid = false;
	}
	if (x + d >= n && y + d >= m)
	{
		valid = false;
	}
	cout << (valid ? n + m - 2 : -1) << endl;
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
