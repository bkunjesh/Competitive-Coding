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
bool isvalid(int hr, int mn, int h, int m)
{
    string hour = to_string(hr), minute = to_string(mn);
    // cout << "isvalid:" << hour << " : " << minute << endl;
    for (auto it : hour)
    {
        if (it != '0' && it != '1' && it != '2' && it != '5' && it != '8')
        {
            return 0;
        }
    }
    for (auto it : minute)
    {
        if (it != '0' && it != '1' && it != '2' && it != '5' && it != '8')
        {
            return 0;
        }
    }

    if (hour.size() == 1)
    {
        hour = '0' + hour;
    }
    if (minute.size() == 1)
    {
        minute = '0' + minute;
    }
    // cout << hour << "-" << minute << " ";
    reverse(hour.begin(), hour.end());
    reverse(minute.begin(), minute.end());
    swap(minute, hour);

    for (int i = 0; i < hour.size(); i++)
    {
        if (hour[i] == '2')
            hour[i] = '5';
        else if (hour[i] == '5')
            hour[i] = '2';
    }
    for (int i = 0; i < minute.size(); i++)
    {
        if (minute[i] == '2')
            minute[i] = '5';
        else if (minute[i] == '5')
            minute[i] = '2';
    }
    int temph, tempm;
    {
        temph = (hour[0] - '0') * 10 + (hour[1] - '0');
    }
    {
        tempm = (minute[0] - '0') * 10 + (minute[1] - '0');
    }
    // cout << h << "-" << m << " " << temph << "~" << tempm << endl;
    ;
    if ( temph < h && tempm < m )
        return 1;

    return 0;
}

// bool isvalidtime()

string makevalid(int hr, int mn)
{
    string hour = to_string(hr);
    string minute = to_string(mn);
    if (hr < 10)
        hour = '0' + hour;
    if (mn < 10)
        minute = '0' + minute;

    return hour + ':' + minute;
}

void solve()
{
    int i, j, k;

    int h, m;
    string s, ans;
    cin >> h >> m >> s;

    int hr = (s[0] - '0') * 10 + (s[1] - '0');
    int mn = (s[3] - '0') * 10 + (s[4] - '0');
    i = mn;
    j = hr;

    int cnt1 = 0;
    while (1)
    {
        if (isvalid(j, i, h, m))
        {
            ans = makevalid(j, i);
            // cout << ans << " ";

            break;
        }
        else
        {
            i = (i + 1) % m;
            if (i == 0)
            {
                j = (j + 1) % h;
            }
        }
        cnt1++;
    }
    
    cout << ans << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif