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
//#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
//template <typename... Args>
//void logger(string vars, Args &&...values)
//{
//    cout << vars << " = ";
//    string delim = "";
//    (..., (cout << delim << values, delim = ","));
//    cout << endl;
//}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;
int sum(int x, int y)
{
    vector<int> a(20, 0), b(20, 0), carry(20, 0), ans(20, 0);
    int i = 0;
    while (x)
    {
        a[i] += x % 10;
        x /= 10;
        i++;
    }
    i = 0;
    while (y)
    {
        b[i] += y % 10;
        y /= 10;
        i++;
    }

    for (i = 0; i < 20; i++)
    {
        int val = a[i] + b[i];
        if (val >= 10)
            carry[i + 2] += 1;
        ans[i] += (val % 10 + carry[i]);
    }
    reverse(ans.begin(), ans.end());

    int res = 0;
    for (i = 0; i < 20; i++)
    {
        res = res * 10 + ans[i];
    }
    return res;
}

void solve()
{
    int i, j, k;

    // cin>>n;
    string s;
    cin >> s;

    // for (n = 1; n <= 50; n++)
    // {
    //     int cnt = 0;
    //     for (i = 1; i < n; i++)
    //     {
    //         for (j = 1; j < n; j++)
    //         {
    //             if (sum(i, j) == n)
    //             {
    //                 // dbg(n, i, j);
    //                 cnt++;
    //             }
    //         }
    //     }
    //     // cout<<"n,cnt - "<<n<<" "<<cnt<<endl;
    //     cout<<cnt<<" ";
    // }

    int a = 0, b = 0;

    for (i = 0; i < s.size(); i++)
    {
        if (i % 2)
            a = a * 10 + (s[i] - '0');
        else
            b = b * 10 + (s[i] - '0');
    }
    cout << (a + 1) * (b + 1) - 2 << endl;

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

int find_root(int x,vector<int> &rt)
{
    if(rt[x]==x)
        return x;
    rt[x] == find_root(rt[x],rt);
    return rt[x];
}

vector<int> getStorage(int connections_nodes,vector<int> connections_from,vector<int> connections_to,vector<int> storage,int threshold)
{
    vector<int> res;

    int initval = 0;
    for(auto val:storage)
    {
        if(val<=threshhold)
            initval += 1;
    }
    vector<int> rt;
    for (int i = 0; i < storage.size();i++)
    {
        rt.push_back(i);
    }

    

    for (int i = 0; i < connection_to.size();i++)
    {
        int v = find_root(connections_to[i],rt);
        int u = find_root(connections_from[i],rt);

        if(u==v)
        {
            res.push_back(initval);
            continue;
        }
        if (storage[u] <= threshold)
            initval -= 1;
        if (storage[v] <= threshold)
            initval -= 1;

        if (storage[u] + storage[v] <= threshold)
            initval += 1;

        rt[u] = v;
        storage[v] += storage[u];

        res.push(initval)
    }

    return res;

}

// def maxDiff(arr, arr_size):
//     max_diff = arr[1] - arr[0]
//     for i in range( 0, arr_size ):
//         for j in range( i+1, arr_size ):
//             if(arr[j] - arr[i] > max_diff):
//                 max_diff = arr[j] - arr[i]
//     return max_diff

// def solution(str) : 
//     arr = str.split(",")
//     arr_size= len(arr)

//     return maxDiff(arr,arr_size)

// print(solution(input()))