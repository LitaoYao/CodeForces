#include <iostream>
using namespace std;
void solve()
{
	int a, b, c;
	cin >> a >> b >> c;
	long long z = c;
	long long y = b + c;
	long long x = a + b + c;
	cout << x << " " << y << " " << z << endl;
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
