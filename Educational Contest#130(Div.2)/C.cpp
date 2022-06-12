#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool canTransmitTarget(string& s, string& t, int n, char target, char transmit)
{
	int sPointer = n - 1;
	int tPointer = n - 1;
	int sCount = 0;
	int tCount = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == target)
		{
			++sCount;
		}
		if (t[i] == target)
		{
			++tCount;
		}
	}
	if (sCount != tCount)
	{
		return false;
	}
	bool valid = true;
	while (sPointer >= 0 && tPointer >= 0)
	{
		while (sPointer >= 0 && s[sPointer] != target)
		{
			--sPointer;
		}
		while (tPointer >= 0 && t[tPointer] != target)
		{
			--tPointer;
		}
		if (sPointer > tPointer)
		{
			valid = false;
			break;
		}
		bool canTransmit = true;
		for (int i = sPointer + 1; i <= tPointer; ++i)
		{
			if (s[i] != transmit)
			{
				canTransmit = false;
				break;
			}
		}
		if (!canTransmit)
		{
			valid = false;
			break;
		}
		swap(s[sPointer], s[tPointer]);
		--sPointer;
		--tPointer;
	}
	return valid;
}
void solve()
{
	int n;
	cin >> n;
	string s, t;
	cin >> s;
	cin >> t;
	if (!canTransmitTarget(s, t, n, 'a', 'b'))
	{
		cout << "NO" << endl;
		return;
	}
	if (!canTransmitTarget(s, t, n, 'b', 'c'))
	{
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
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
