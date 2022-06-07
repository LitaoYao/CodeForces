#include <iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int a = n / 3;
	int left = n % 3;
	if (left == 0)
	{
		cout << a << " " << a + 1 << " " << a - 1 << endl;
	}
	else if (left == 1)
	{
		cout << a << " " << a + 2 << " " << a - 1 << endl;
	}
	else
	{
		cout << a + 1 << " " << a + 2 << " " << a - 1 << endl;
	}

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
