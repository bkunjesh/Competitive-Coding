string s="my name is kunjesh and kunjesh is programmer."

int solution(string s,string t)
{
    int n = s.size();
    int m = t.size();

    int i, j,k,ans=0;

    for (i = 0; i < n;i++)
    {
        j = 0;
        k = i;

        while(j<m&&k<n&&t[j]==s[k])
        {
            j++;
            k++;
        }

        if(j==m)
        {
            ans++;
        }
    }
    return ans;
}
