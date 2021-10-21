#include<bits/stdc++.h>
using namespace std;

int waysofchange(int a[], int m, int n)
{
	int i, j;
	int dp[m + 1][n + 1];
	dp[0][0] = 1;
	for (i = 0; i <= m; i++) dp[i][0] = 1;
	for (i = 1; i <= n; i++) dp[0][i] = 0;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (a[i - 1] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j] + dp[i][j - a[i - 1]];
		}
	}
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++) cout << dp[i][j] << " ";
		cout << endl;
	}
	return dp[m][n];
}

int main()
{
	int n = 6;
	int coin[] = {2, 5, 3, 6};
	cout << waysofchange(coin, 4, n) << endl;
}