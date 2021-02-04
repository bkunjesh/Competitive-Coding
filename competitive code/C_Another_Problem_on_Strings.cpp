//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j, k;
    string s;

    cin >> k >> s;
    n = s.size();

    map<int, int> m;

    int sum = 0;
    f(i, n) sum += (s[i] - '0'), m[sum]++;
    
    int ans = 0;

    m[0]++;

    for (i = k; i <= n; i++)
    {
        if(k==0)
        {
            ans += (m[i] - 1) * m[i] / 2;
        }
        else
            ans += m[i - k] * m[i];
    }
    
    cout << ans << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// 2

// 10100100010000

// First, let's calculate prefix sums of 1's. We get the following values:

// 11222333344444

// Our C table looks like this:

// C[0] = 1

// C[1] = 2

// C[2] = 3

// C[3] = 4

// C[4] = 5

// Now we iterate over C table starting from i = 2 (which is our k) to 4 (which is maximum sum of 1's). Value C[i] is the count of positions which can be right end of our substring. Now we need to find the number of positions which can be left end of the substring. Number of such positions is C[i — k]. For example for i = 3 we get the following possible left and right end positions:

// 1 0 1 0 0 1 0 0 0 1 0 0 0 0

// So for any i we've got C[i — k] (left ends) * C[i] (right ends) possible substrings with k 1's. Answer is the sum of such values for all i.

// Special case is k = 0. If I have for example C[2] = 3 it means that I have one position with 1 and two positions with 0s. So what I need to do now is to count number of all substrings of these two 0's. If Let's say I have n 0s, then I will have:

// n substrings of length 1 n — 1 substrings of length 2 n — 2 substrings of length 3 ... 1 substring of length n

// so generally the number of substrings of string of length n is sum of numbers from 1 to n which is n*(n+1)/2.