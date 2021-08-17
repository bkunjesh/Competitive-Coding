#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define endl "\n"

vector<int> sort_cyclic_shifts(string const &s)
{
    int n = s.size();
    const int alphabet = 256;

    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[p[i]] != s[p[i - 1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h)
    {
        for (int i = 0; i < n; i++)
        {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++)
        {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s)
{
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp_construction(string const &s, vector<int> const &p)
{

    // LCP[i]=common prefix in i and i-1 suffix in sorted order.
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int h = 0, k;

    vector<int> lcp(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (rank[i] > 0)
        {
            k = p[rank[i] - 1];

            while (s[i + h] == s[k + h])
                h++;

            lcp[rank[i]] = h;

            if (h > 0)
                h--;
        }
    }
    return lcp;
}

signed main()
{
        int n;
        cin >> n;
        #define ld long double
        vector<pair<ld, ld>> a(n + 1);
        auto distance = [&](ld a, ld b, ld c, ld d)
        {
            ld res = (a - c) * (a - c) + (b - d) * (b - d);
            return res;
        };

        auto solution = [&](ld incomingAmount, ld outgoingAmount, int ind)
        {
            ld dis = distance(incomingAmount, outgoingAmount, a[ind].F, a[ind].S);
            return dis;
        };
        auto solution2 = [&](int ind2, int ind)
        {
            ld dis = distance(a[ind2].F, a[ind2].S, a[ind].F, a[ind].S);
            return dis;
        };
        int factor = 1e6;
        cin.ignore();

        for (int i = 1; i <= n; i++)
        {
            string str;
            getline(cin, str);
            stringstream s(str);
            string tmp, id;
            int cnt = 0;

            while (s >> tmp)
            {
                if (cnt == 0)
                    id = tmp;

                if (cnt == 1)
                {

                    ld x = stod(tmp);
                    x *= factor;
                    a[i].F = x;
                }

                if (cnt == 2)
                {
                    ld x = stod(tmp);
                    x *= factor;
                    a[i].S = x;
                }
                cnt++;
            }

            cout << "\n";
        }

        vector<string> result;

        int m;
        cin >> m;
        cin.ignore();

        for (int i = 1; i <= m; i++)
        {

            string str;
            getline(cin, str);
            stringstream s(str);
            string tmp;
            string id;

            ld incomingAmount = -1, outgoingAmount = -1;
            int cnt = 0;

            while (s >> tmp)
            {

                if (cnt == 0)
                {
                    id = tmp;
                }

                if (cnt == 1)
                {

                    incomingAmount = stod(tmp);
                    incomingAmount *= factor;
                }

                if (cnt == 2)
                {
                    outgoingAmount = stod(tmp);
                    outgoingAmount *= factor;
                }

                cnt++;
            }
            cout << "\n";

            if (incomingAmount > 0 && outgoingAmount > 0)
            {

                ld ind = 1, value = solution(incomingAmount, outgoingAmount, 1);

                for (int j = 2; j <= n; j++)
                {

                    ld curr = solution(incomingAmount, outgoingAmount, j);
                    if (curr < value)
                    {
                        value = curr;
                        ind = j;
                    }
                }

                int customer = 1;
                if (ind == 1)
                    customer+=1;

                ld value2 = solution2(customer, ind);

                for (int j = 2; j <= n; j++)
                {
                    if (j == ind)
                        continue;
                    ld curr = solution2(j, ind);
                    if (curr < value2)
                    {
                        value2 = curr;
                    }
                }

                if ((value / value2) < 1)
                {
                    result.push_back(id);
                }
            }
        }
        sort(result.begin(), result.end());
        for (auto x : result)
            cout << x << endl;
    return 0;
}
