#include <iostream>
#include <cmath>
using namespace std;
#define int long long
int nesq(int n)
{
    double r;
    int l, m;
    r = sqrt(n);
    //cout << 1e+006 << " ";
    if (r - floor(r) == 0)
    {
        l = (r - 1) * (r - 1);
        m = (r + 1) * (r + 1);
    }
    else
    {
        l = floor(r) * floor(r);
        m = ceil(r) * ceil(r);
    }
    if ((n-l) < (m - n))
        return l;
    if ((n - l) == (m - n))
        return m;

    return m;
}
void test(int t)
{
    int i, k;
    int n;
    for (i = 0; i < t; i++)
    {
        cin >> n;
        k = nesq(n);
        cout << k << endl;
    }
}
signed main()
{
    int t;
    cin >> t;
    test(t);
    return 0;
}