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

    vector<string> words;
    string s = "2S 6 du5d4e";
    // cin >> s;

    string word = "";
    for (auto x : s)
    {
        if (x == ' ')
        {
            //cout << word << endl;
            words.push_back(word);
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    words.push_back(word);
    string ans = "";
    // cout << words.size() << " ";

    for (i = 0; i < words.size(); i++)
    {
        string word = words[i];
        vector<int> intind;
        for (j = 0; j < word.size(); j++)
        {
            if (word[j] >= 'a' && word[j] <= 'z')
            {
                word[j] = word[j] - 32;
            }
            else if (word[j] >= 'A' && word[j] <= 'Z')
            {
                word[j] = word[j] + 32;
            }
            else if (word[j] >= '0' && word[j] <= '9')
            {
                if (intind.size() > 0)
                {
                    swap(word[intind.back()], word[j]);
                    intind[0] = j;
                }
                else
                    intind.push_back(j);
            }
        }
        if (i == 0)
            ans = ans + word;
        else
            ans = ans + " " + word;
    }
    cout << ans << endl;
    // return ans;

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