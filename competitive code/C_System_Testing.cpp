//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int func(int n , int m)
{
	return (200 * m + n) / (2 * n);
}
signed main()
{

	int n, k;
	cin >> n >> k;
	int *arr = new int[n];
	int *test = new int[n]();
	bool *used = new bool[n]();
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int *process = new int[k];
	for (int i = 0; i < k; i++)
		process[i] = -1;
	int total = 0;
	for (int i = 0; i < min(n, k); i++)
		process[i] = i;
	int next = min(n, k);
	int time = 0;
	int ans = 0;
	while (true)
	{
		time++;
		for (int i = 0; i < min(n, k); i++)
		{
			if (process[i] == -1)
				continue;
			test[process[i]]++;
			if (func(n, total) == test[process[i]])
			{
				if (!used[process[i]])
				{
					used[process[i]] = true;
					ans++;
				}
			}
		}
		for (int i = 0; i < min(n, k); i++)
		{
			if (process[i] == -1)
				continue;
			if (test[process[i]] == arr[process[i]])
			{
				total++;
				if (next == n)
				{
					process[i] = -1;
					continue;
				}
				else
				{
					process[i] = next;
					next++;
				}
			}
		}
		int counter = 0;
		for (int i = 0; i < k; i++)
		{
			if (process[i] != -1)
				counter = 1;
		}
		if (counter == 0)
			break;
	}
	cout << ans << endl;
	return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif