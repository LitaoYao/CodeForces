// https://codeforces.com/contest/1840/problem/A
#include <iostream>
#include <string>
using namespace std;

void solve()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	string ans = "";
	int i = 0;
	while (s[i] != '\0')
	{
		char ch = s[i];
		int j = i + 1;
		while(s[j] != ch && s[j] != '\0')
		{
			++j;
		}
		i = j + 1;
		ans += ch;
	}
	cout << ans << endl;
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
