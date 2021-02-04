int closer(int a[], int n, int x)
{
    int l = 1, h = n - 2;
    int m;
    while (l <= h)
    {
        m = (l + h) / 2;
        if (a[m] == x)
            return m;
        if (a[m - 1] == x)
            return m - 1;
        if (a[m + 1] == x)
            return m + 1;
        if (x < a[m])
            l = m - 1;`
        else if (x > a[m])
            h = m + 1;
    }

    return -1;
}

// { Driver Code Starts.

int main()
{

    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int x;
        cin >> x;

        int res = closer(arr, n, x);

        cout << res << endl;
    }

    return 0;
} // } Driver Code Ends