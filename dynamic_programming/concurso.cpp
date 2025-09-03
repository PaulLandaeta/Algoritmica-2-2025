#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        long long mini = 3*10^6+1, maxi = -1;
        for (int i = 0; i < n; ++i)
        {
            long long v;
            cin >> v;
            mini = min(mini, v);
            maxi = max(maxi, v);
        }
        long long total = (maxi - mini) * (maxi - mini);
        cout << total << endl ;
        return 0;
    }

    return 0;
}