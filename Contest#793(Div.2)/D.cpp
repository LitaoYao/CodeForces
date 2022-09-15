// https://codeforces.com/contest/1682/problem/D
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	string isOdd;
	cin >> isOdd;
	int oddSize = count(isOdd.begin(), isOdd.end(), '1');
	bool possible = (oddSize >= 2 && (oddSize & 1) == 0);
	if (!possible)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
		// choose the root p
		// if p is odd, the number of segment end with odd node is odd
		// if p is even, the number of segment end with odd node is even
		int p = 1;
		while (isOdd[p - 1] != '1')
		{
			++p;
		}
		// connect the segment and link them to root p
		int u = (p + 1) % n;
		while (u != p)
		{
			int v = u; // v start from the beginning of segment
			u = p; // u start from root p
			while (v != p)
			{
				cout << u + 1 << " " << v + 1 << endl;
				u = v;
				v = (v + 1) % n;
				if (isOdd[u] == '1')
				{
					// segment will end with odd node
					break;
				}
			}
			u = v; // u become the next beginning of segment
		}
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
