/*
user: 
problem: https://codeforces.com/contest/126/problem/B
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

// hii there,


// This question can be solved by two method

// 1) Using prefix_function 
// 2) Rabin-karp + binary search

// 1. Using prefix_function ( refer https://cp-algorithms.com/string/prefix-function.html#toc-tgt-12 for prefix function)


//  Problem in simple word:

//  We need to find the longest substring T of given string s, which is a prefix, a suffix, and also appears in the middle. Output T or "just a legend" if not present such substring.

// We will create an array pi. where pi is prefix array of size n ( ;n=s.size()).

// *** pi[i] is the length of the longest prefix of the substring s[0…i] which is also a suffix of THIS SUBSTRING.

// for e.g
// 
// let say we have string s= "fixprefixsuffix" . so pi for string s is

// index:  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14    
//         f i x p r e f i x s  u  f  f  i  x
// pi:     0 0 0 0 0 0 1 2 3 0  0  1  1  2  3

// look at the substring "fixpref"

// index:  0 1 2 3 4 5 6   
//         f i x p r e f     
// pi:     0 0 0 0 0 0 1 
// pi[6]= 1 because longest prefix which is sufix ending at index 6 is "f" 

// similarly,
// look at the substring "fixprefi"

// index:  0 1 2 3 4 5 6 7  
//         f i x p r e f i    
// pi:     0 0 0 0 0 0 1 2
// pi[7]= 2 because longest prefix which is sufix ending at index 7 is "fi"

// in this manner we can find pi array for every index.
// (for algo, refer above link. cp-algorithm has beautiful artical on prefix function.)

vector<int> prefix_function(string s)
{
    int n = s.size(), i, j;
    vector<int> pi(n + 1);

    for (i = 1; i < n; i++)
    {
        j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        // cout << pi[i] << " ";
    }

    return pi;
}
// ***EXPLANATION***

// now we want longest substring, which is prefix,suffix and also present in middle
// so let say x=pi[n-1];

// now if x is greater than 0 that means
//    we have a prefix of length x which is also suffix right.
//    now we need to check that is that prefix occurs anywhere in the middle of the string or not..

//    for this we iterate through the pi array from i= 0 to n-2   (** till n-2 because we know pi[n-1] is already x.)
//    and we search for x in pi ..

//    if we find x somewhere in pi
//          that means prefix of length x is also present in between the string s as substring as well as suffix .
//          so we simply output substring of length x (s[0...x])

//    if we did't find x in pi
//           then there is possiblity that there exist smaller prefix whose length is less than x which is suffix as well as present in between the string s just like this example:

//                  string s= aabcaacdaabcaa
// index:           0 1 2 3 4 5 6 7 8 9 10 11 12 13 
//                  a a b c a a c d a a  b  c  a  a
// pi:              0 1 0 0 1 2 0 0 1 2  3  4  5  6
//             we have "aabcaa" {length x=6} as prefix as well as suffix but we did't find it any where in middle of string right
//             so we have to look for prefix of length less than 6(x)
//             we have "aa" {length 2} which satisfy all our need. 
//             so now question is how to rech "aa".

//             here you need a little bit deeper understanding of prefix function.
//             we will see pi[pi[n-1]-1]
//             lets understand "pi[pi[n-1]-1]" by above example
//             pi[n-1]=6 right so pi[6-1] that is pi[5]=2
//             that means in substring "aabcaa" ( 'cause pi[n-1]=6 )
// index:           0 1 2 3 4 5
//                  a a b c a a
// pi:              0 1 0 0 1 2
//             we have prefix of length 2 which is also suffix right..
//             and from pi[n-1]=6 we know substring "aabcaa" is prefix as well as suffix of string s
//             so we have definitely substring "aa" which occurs in prefix and suffix and also in middle somewhere in string s.
//             so in this case we print prefix "aa".


// ***QUICK EXPLANATION***

//  simply we need to check pi[n-1] is greater than 0 or not:
//  if it is then need to find such j where pi[j]==x  (here x=pi[n-1])
//      if we find such j 
//          then output prefix of length x 
//      otherwise we see for smaller prefix
//      that is pi[pi[n-1]-1] is greater than 0 or not:
//          if it is then 
//              output the prefix of length pi[pi[n-1]-1] (that is pi[x-1])
//          other wise 
//              print "Just a legend"


void solve()
{
    int i, j, k, n;

    string s;
    cin >> s;
    auto pi = prefix_function(s);
    n = s.size();
    if (pi[n - 1] == 0)
    {
        cout << "Just a legend" << endl;
        return;
    }
    else
    {
        f(i, n - 1)
        {
            if (pi[i] == pi[n - 1])
            {
                cout << s.substr(0, pi[n - 1]) << endl;
                return;
            }
        }

        if (pi[pi[n - 1] - 1] == 0)
        {
            cout << "Just a legend" << endl;
            return;
        }
        else
        {
            cout << s.substr(0, pi[pi[n - 1] - 1]) << endl;
            return;
        }
    }

    return;
}

// (first understand the above method then go for this, although they are diffferent solution but it's recommendation)
// 2. Rabin-karp + binary_search
//  https://codeforces.com/contest/126/submission/89824218

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

