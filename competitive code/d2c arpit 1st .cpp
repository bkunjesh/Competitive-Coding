//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long


int n;

bool check_rotation(string s, string goal)
{
    if (s.size() != goal.size()) return false;
    queue<char> q1;
    for (int i = 0; i < s.size(); i++)
    {
        q1.push(s[i]);
    }
    queue<char> q2;
    for (int i = 0; i < goal.size(); i++)
    {
        q2.push(goal[i]);
    }
    int k = goal.size();
    while (k--)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}

void solve()
{
    int i, j, k;

    string s, t;
    cin >> s >> t;
    if (check_rotation(s, t))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return;
}

signed main()
{
    int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
