#include <iostream>
using namespace std;
void solve()
{
	int x;
	cin >> x;
	int open[4] = {0, 0, 0, 0};
	int keys[4] = {0, 0, 0, 0};
	for (int i = 1; i <= 3; ++i)
	{
		cin >> keys[i];
	}
	while (x != 0)
	{
		open[x] = 1;
		x = keys[x];
	}
	int count = 0;
	for (int i = 1; i <= 3; ++i)
	{
		count += open[i];
	}
	cout << (count == 3 ? "YES" : "NO") << endl;
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
