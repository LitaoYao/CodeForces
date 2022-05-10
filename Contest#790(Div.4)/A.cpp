#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string ticket;
		cin >> ticket;
		if (ticket[0] + ticket[1] + ticket[2] == ticket[3] + ticket[4] + ticket[5])
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
