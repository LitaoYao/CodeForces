#include <iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	cout << n << " \n"[n == 1];
	for (int i = 1; i < n; ++i)
	{
		cout << i << " \n"[i == n - 1];
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
