#include <iostream>
using namespace std;

const int N = 50;

long long query(long long a, long long b)
{
    long long x;
    cout << "? " << a << " " << b << endl;
    cout << flush;
    cin >> x;
    return x;
}

void answer(long long n)
{
    cout << "! " << n << endl;
    cout << flush;
}

void solve()
{
    long long ans = -1;
    long long dist1, dist2;
    for (int i = 0; i < N / 2; ++i)
    {
        dist1 = query(2 * i + 1, 2 * i + 2);
        if (dist1 == -1)
        {
            dist2 = query(1, 2 * i + 1);
            if (dist2 == -1)
            {
                ans = 2 * i;
            }
            else
            {
                ans = 2 * i + 1;
            }
            break;
        }
        else
        {
            dist2 = query(2 * i + 2, 2 * i + 1);
            ans = dist1 + dist2;
            if (dist1 != dist2)
            {
                break;
            }
        }
    }
    answer(ans);
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
