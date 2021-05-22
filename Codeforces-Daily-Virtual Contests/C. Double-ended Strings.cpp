#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod 1000000007
#define int long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL)
#define PI 3.14159265358979323846
#define endl "\n"

void solve()
{
    string a, b;
    cin >> a >> b;
    int m = strlen(a);
    int n = strlen(b);
    int LCS_table[m + 1][n + 1];
    int LCSlength = 0;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCS_table[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
            {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
                LCSlength = max(LCSlength, LCS_table[i][j]);
            }
            else
                LCS_table[i][j] = 0;
        }
    }
    cout << LCSlength << endl;
}
int main()
{
    fast;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}