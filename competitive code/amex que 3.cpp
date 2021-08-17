#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second

double roundOff(double var)
{
    double value = (int)((var*100));
    return (double)value / 100;
}
int power(int p, int q)
{
    int res = 1;
#define mod 1000000007
    p = p % (mod);
    if (p == 0)
        return 0;

    while (q > 0)
    {

        if (q & 1)
            res = (res * p) % mod;

        q = q >> 1;
        p = (p * p) % mod;
    }
    return res;
}
double change(string &s, double p)
{
    double res = 0.0;
    if (s == "Euro")
        return p;

    else if (s == "Dollar")
    {
        res = (50* p) / 59;
    }

    else
    {
        res = (p* 13) / 118;
    }

    res = roundOff(res);
    return res;
}
struct pers
{
    // string fname,lname;
    int aSpend, tAsset, tAbilitq, hof, bscore, credit;
};
double avgspend = 0;
map<string, pers> mp;
bool check(double income, string temp)
{
    pers p = mp[temp];
    int asset = p.tAsset;
    int bscore = p.bscore;
    int aspend = p.aSpend;
    int liable = p.tAbilitq;
    if (asset > liable && (bscore > 50) && ((aspend * 1.0) / income) > (.1) && (aspend > avgspend))
        return true;
    return false;
}
bool check2(double income, string temp)
{
    pers p = mp[temp];
    int asset = p.tAsset;
    int bscore = p.bscore;
    int aspend = p.aSpend;
    int liable = p.tAbilitq;
    if (asset > liable && (bscore > 30) && ((aspend * 1.0) / income) > (0.1) && (aspend > avgspend) && (p.hof) == 1)
        return true;
    return false;
}
int getans()
{
    int n;
    cin >> n;

    map<int, double> ans;
    multiset<double> m;

    int fac = 1e6;

    while (n--)
    {
        int p, q;
        double amt;
        string tqp;
        cin >> p >> q >> amt >> tqp;
        amt *= fac;

        amt = change(tqp, amt);
        ans[p] -= amt;
        ans[q] += amt;
    }

    for (auto p : ans)
    {
        if (p.S != 0.0)
            m.insert(p.S);
    }

    int count = 0;

    while (m.size() >= 2)
    {
        count++;

        auto lowpointer = m.begin();
        auto highpointer = prev(m.end(), 1);

        double debitamount = *lowpointer;
        double creditamount = *highpointer;

        m.erase(lowpointer);
        m.erase(highpointer);

        double settlement = min(-debitamount, creditamount);

        debitamount += settlement;
        creditamount -= settlement;

        if (abs(debitamount) > 1e-2)
            m.insert(debitamount);
        if (abs(creditamount) > 1e-2)
            m.insert(creditamount);
    }

    return count;
}

void solution()
{
    int res = getans();
    cout << res << "\n";
}

signed main()
{

    int test = 1;
    while (test--)
    {
        solution();
    }

    return 0;
}

int nCr(int n, int r)
{
    int p = 1, k = 1;

    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            int m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;

    return p;
}