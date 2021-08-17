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
// #define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
// template<typename ...Args>
// void logger(string vars, Args&&... values) {
//     cout << vars << " = ";
//     string delim = "";
//     (..., (cout << delim << values, delim = ","));
//     cout << endl;
// }

// vector<int> sort_cyclic_shifts(string const &s)
// {
//     int n = s.size();
//     const int alphabet = 256;

//     vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
//     for (int i = 0; i < n; i++)
//         cnt[s[i]]++;
//     for (int i = 1; i < alphabet; i++)
//         cnt[i] += cnt[i - 1];
//     for (int i = 0; i < n; i++)
//         p[--cnt[s[i]]] = i;
//     c[p[0]] = 0;
//     int classes = 1;
//     for (int i = 1; i < n; i++)
//     {
//         if (s[p[i]] != s[p[i - 1]])
//             classes++;
//         c[p[i]] = classes - 1;
//     }

//     vector<int> pn(n), cn(n);
//     for (int h = 0; (1 << h) < n; ++h)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             pn[i] = p[i] - (1 << h);
//             if (pn[i] < 0)
//                 pn[i] += n;
//         }
//         fill(cnt.begin(), cnt.begin() + classes, 0);
//         for (int i = 0; i < n; i++)
//             cnt[c[pn[i]]]++;
//         for (int i = 1; i < classes; i++)
//             cnt[i] += cnt[i - 1];
//         for (int i = n - 1; i >= 0; i--)
//             p[--cnt[c[pn[i]]]] = pn[i];
//         cn[p[0]] = 0;
//         classes = 1;
//         for (int i = 1; i < n; i++)
//         {
//             pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
//             pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
//             if (cur != prev)
//                 ++classes;
//             cn[p[i]] = classes - 1;
//         }
//         c.swap(cn);
//     }
//     return p;
// }

// vector<int> suffix_array_construction(string s)
// {
//     s += "$";
//     vector<int> sorted_shifts = sort_cyclic_shifts(s);
//     sorted_shifts.erase(sorted_shifts.begin());
//     return sorted_shifts;
// }

// vector<int> lcp_construction(string const &s, vector<int> const &p)
// {

//     // LCP[i]=common prefix in i and i-1 suffix in sorted order.
//     int n = s.size();
//     vector<int> rank(n, 0);
//     for (int i = 0; i < n; i++)
//         rank[p[i]] = i;

//     int h = 0, k;

//     vector<int> lcp(n, 0);
//     for (int i = 0; i < n; i++)
//     {
//         if (rank[i] > 0)
//         {
//             k = p[rank[i] - 1];

//             while (s[i + h] == s[k + h])
//                 h++;

//             lcp[rank[i]] = h;

//             if (h > 0)
//                 h--;
//         }
//     }
//     return lcp;
// }

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->val = x;
        left = NULL;
        right = NULL;
    }
};
Node *lca(Node *root, int a, int b, int &v1, int &v2)
{
    if (!root)
    {
        return NULL;
    }
    if (root->val == a || root->val == b)
    {
        if (root->val == a)
            v1 = 1;
        if (root->val == b)
            v2 = 1;
        return root;
    }
    Node *l = lca(root->left, a, b, v1, v2);
    Node *r = lca(root->right, a, b, v1, v2);
    if (l && r)
        return root;

    return (l ? l : r);
}
bool find(Node *root, int a)
{
    if (!root)
        return root;
    if (root->val == a || find(root->left, a) || find(root->right, a))
        return 1;
    return 0;
}
void solve()
{
    int i, j, k;

    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->right = new Node(7);
    root->left->left = new Node(5);
    root->left->left->right = new Node(9);
    root->right = new Node(6);
    
    int a = 9, b = 7;
    int v1 = 0, v2 = 0;
    Node *ans = lca(root, a, b, v1, v2);
    if (v1 && v2 || v1 && find(ans, b) || v2 && find(ans, a))
        cout << ans->val << endl;
    else
        cout << -1 << endl;

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