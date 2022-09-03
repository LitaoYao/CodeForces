#include <iostream>
using namespace std;
int n, k, r, c;
void solve()
{
	cin >> n >> k >> r >> c;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << ((i + j) % k == (r + c - 2) % k ? "X" : ".");
		}
		cout << endl;
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
