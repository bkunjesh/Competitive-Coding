#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, m, ans = 0;
    int t;
    char in[105][105];
    int arr[105] = {0};
    cin >> n >> m; // m columns n rows

    for (i = 0; i < n; i++)
    {
        scanf("%s", in[i]);
    }

    int prevtaken = -1, prevleft = -1;

    for (j = 0; j < m; j++)
    {
        for (i = 1; i < n; i++)
        {
            if (in[i][j] < in[i - 1][j])
            {
                if (prevtaken == -1)
                {
                    prevleft++;
                    arr[prevleft] = -1;
                    break;
                }

                else
                {
                    int z;
                    for (z = 0; z < j; z++)
                    {
                        if (arr[z] == -1)
                            continue;
                        if (in[i][z] != in[i - 1][z])
                            break;
                    }

                    if (z == j)
                    {
                        prevleft = j;
                        arr[j] = -1;
                        break;
                    }
                }
            }
        }

        if (i == n)
        {
            prevtaken = j;
        }
        if (arr[j] == -1)
            ans++;
    }

    cout << ans;

    return 0;
}