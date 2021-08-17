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

int n;

class Group
{
public:
    string s;
    int first;
    int second;

    Group(string str, int f, int sc)
    {
        s = str;
        first = f;
        second = sc;
    }
};
int sortparameter, sortorder;
bool mycomp(Group &p, Group &q)
{

    if (sortparameter == 0)
    {
        return (sortorder) ? (p.s > q.s) : (p.s < q.s);
    }
    else if (sortparameter == 1)
    {
        return (sortorder) ? (p.first > q.first) : (p.first < q.first);
    }
    else if (sortparameter == 2)
    {
        return (sortorder) ? (p.second > q.second) : (p.second < q.second);
    }

    return 1;
}

vector<string> fetchItemsToDisplay(int numOfItem, vector<Group> a, int sortParameter, int sortOrder, int itemsPerPage, int pageNumber)
{
    // vector<Group> a;
    //map<string, pairInt> items,
    
    //convert given formate to vector of Group

    sortparameter = sortParameter;
    sortorder = sortOrder;
    sort(a.begin(), a.end(), mycomp);

    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i].s << " " << a[i].first << " " << a[i].second << endl;
    // }

    vector<string> ans;

    int ind = itemsPerPage * pageNumber;

    for (int i = ind; i < ind + itemsPerPage && i < a.size(); i++)
    {
        ans.push_back(a[i].s);
        cout << a[i].s << " " << a[i].first << " " << a[i].second << endl;
    }
    return ans;
}

void solve()
{
    int i, j, k;
    vector<Group> vec;
    Group g1("kunjesh", 8, 5);
    Group g2("abc", 1, 4);
    Group g3("abc", 12, 13);
    Group g4("kunjesh", 9, 5);
    vec.push_back(g1);
    vec.push_back(g2);
    vec.push_back(g3);
    vec.push_back(g4);
    fetchItemsToDisplay(vec.size(), vec, 0, 0, 3, 1);

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