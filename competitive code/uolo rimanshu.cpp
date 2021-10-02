//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int getscore(string s)
{
    int n = s.size(), i;
    map<char, int> freq;
    for (i = 0; i < n; i++)
    {
        freq[s[i]]++;
    }
    int mxfreq = 0;
    for (auto it : freq)
    {
        mxfreq = max(it.second, mxfreq);
    }
    return mxfreq;
}

string LetterCount(string s)
{
    int n = s.size(), i, j, k;

    vector<string> words;
    string temp = "";
    s += " ";
    for (i = 0; i < n; i++)
    {
        if (s[i] == ' ' && temp.size() > 0)
        {
            words.push_back(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }

    string ans = "-1";
    int score = 0;

    for (i = 0; i < words.size(); i++)
    {
        int val = getscore(words[i]);
        if (val == 1)
            continue;
        if (val > score)
        {
            score = val;
            ans = words[i];
        }
    }
    cout << ans;
    return ans;
}

void solve()
{
    int i, j, k;

    string s = "No words";
    // string s = "Today, is the greatest day ever!";
    LetterCount(s);

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif