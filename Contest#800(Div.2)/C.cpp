#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<long long> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	bool valid = true;
	bool reachZero = false;
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += nums[i];
		if (sum < 0)
		{
			valid = false;
			break;
		}
		else if (sum == 0)
		{
		    reachZero = true;
		}
		else if (reachZero)
		{
		    valid = false;
		    break;
		}
	}
	if (sum != 0)
	{
		valid = false;
	}
	if (valid)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
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

