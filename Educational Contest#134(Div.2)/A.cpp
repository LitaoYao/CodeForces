#include <iostream>
#include <map>
using namespace std;
void solve()
{
	char x;
	map<char, int> counts;
	for (int i = 0; i < 4; ++i)
	{
		cin >> x;
		counts[x]++;
	}
	if (counts.size() == 1)
	{
		cout << 0 << endl;
	}
	else if (counts.size() == 2)
	{
		cout << 1 << endl;
	}
	else if (counts.size() == 3)
	{
		cout << 2 << endl;
	}
	else
	{
		cout << 3 << endl;
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
