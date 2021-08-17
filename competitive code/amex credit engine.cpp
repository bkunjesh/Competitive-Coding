/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

class Bureau_Data
{
public:
    string firstName, lastName, fullName;
    string annualSpend, totalAssets, totalLiability, homeOwnFlag, bureauScore;
    Bureau_Data(string firstName, string lastName, string annualSpend, string totalAssets, string totalLiability, string homeOwnFlag, string bureauScore)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->fullName = firstName + " " + lastName;
        this->annualSpend = annualSpend;
        this->totalAssets = totalAssets;
        this->totalLiability = totalLiability;
        this->homeOwnFlag = homeOwnFlag;
        this->bureauScore = bureauScore;
    }
    void print()
    {
        cout << this->fullName << " " << this->annualSpend << " " << this->totalAssets << " " << this->totalLiability << " " << this->homeOwnFlag << " " << this->bureauScore << " " << endl;
    }
};

vector<string> takeInput()
{
    string str;
    cin >> str;
    vector<string> v;
    stringstream ss(str);

    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }
    return v;
}
int todouble(string s)
{
    if (s == "")
        return 0;
    int isneg = (s[0] == '-') ? 1 : 0;
    int start = 0;
    if (isneg)
        start++;
    int ans = 0;
    for (auto it : s)
    {
        ans = ans * 10 + (it - '0');
    }
    if (isneg)
        return ans;
    // int ans = stold(s);
    return ans;
}
// bool rule1(Bureau_Data *a, int avgSpend, int income)
bool rule1(Bureau_Data *a, int avgSpend, string income)
{
    // cout << a->fullName << endl;
    // a->print();
    // cout << avgSpend << " " << income << endl;
    if ((a->totalAssets > a->totalLiability) &&
        (a->bureauScore > "50") &&
        (todouble(a->annualSpend) > avgSpend) &&
        ((a->annualSpend + "0") > income))
    // ((a->annualSpend) > income * 0.1))
    {
        return 1;
    }

    return 0;
}
// bool rule2(Bureau_Data *a, int avgSpend, int income)
bool rule2(Bureau_Data *a, int avgSpend, string income)
{
    // cout << a->fullName << endl;
    if (
        (a->totalAssets > a->totalLiability) &&
        (a->homeOwnFlag == "1") &&
        (a->bureauScore > "30") &&
        (todouble(a->annualSpend) > avgSpend) &&
        ((a->annualSpend + "0") > income))
    // (a->annualSpend > income * 0.1))
    {
        return 1;
    }

    return 0;
}

signed main()
{
    int i, j, k, n;
    long double avgSpend = 0;
    cin >> n;
    vector<Bureau_Data *> a;
    for (i = 0; i < n; i++)
    {
        auto inp = takeInput();
        string firstName = inp[0], lastName = inp[1];
        string annualSpend = (inp[2]), totalAssets = (inp[3]), totalLiability = (inp[4]), homeOwnFlag = (inp[5]), bureauScore = (inp[6]);
        // int annualSpend = todouble(inp[2]), totalAssets = todouble(inp[3]), totalLiability = todouble(inp[4]), homeOwnFlag = todouble(inp[5]), bureauScore = todouble(inp[6]);

        Bureau_Data *newdata = new Bureau_Data(firstName, lastName, annualSpend, totalAssets, totalLiability, homeOwnFlag, bureauScore);
        a.push_back(newdata);
        avgSpend += todouble(annualSpend);
    }
    avgSpend /= n;

    int m;
    cin >> m;
    map<string, string> mp;
    for (i = 0; i < m; i++)
    {
        auto inp = takeInput();

        string appicationId = inp[0], firstname = inp[1], secondname = inp[2];
        string fullname = firstname + " " + secondname;
        string income = (inp[3]);
        // int income = todouble(inp[3]);

        mp[appicationId] = "No";
        for (j = 0; j < n; j++)
        {
            if (a[j]->fullName == fullname)
            {

                // a[j]->print();

                if (rule1(a[j], avgSpend, income) || rule2(a[j], avgSpend, income))
                {
                    mp[appicationId] = "Yes";
                    break;
                }
            }
        }
    }

    for (auto it : mp)
    {
        cout << it.first << "," << it.second << endl;
    }
}

// #include <algorithm>
// #include <string>
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// string getBestMatchingString(vector<string> &dictionary, string toMatch);
// int damerau_levenshtein_distance(string p_string1, string p_string2);

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

// struct pt
// {
//     long long x, y;
//     pt operator+(const pt &p) const
//     {
//         return pt{x + p.x, y + p.y};
//     }
//     pt operator-(const pt &p) const
//     {
//         return pt{x - p.x, y - p.y};
//     }
//     long long cross(const pt &p) const
//     {
//         return x * p.y - y * p.x;
//     }
// };

// void reorder_polygon(vector<pt> &P)
// {
//     size_t pos = 0;
//     for (size_t i = 1; i < P.size(); i++)
//     {
//         if (P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
//             pos = i;
//     }
//     rotate(P.begin(), P.begin() + pos, P.end());
// }

// vector<pt> minkowski(vector<pt> P, vector<pt> Q)
// {
//     // the first vertex must be the lowest
//     reorder_polygon(P);
//     reorder_polygon(Q);
//     // we must ensure cyclic indexing
//     P.push_back(P[0]);
//     P.push_back(P[1]);
//     Q.push_back(Q[0]);
//     Q.push_back(Q[1]);
//     // main part
//     vector<pt> result;
//     size_t i = 0, j = 0;
//     while (i < P.size() - 2 || j < Q.size() - 2)
//     {
//         result.push_back(P[i] + Q[j]);
//         auto cross = (P[i + 1] - P[i]).cross(Q[j + 1] - Q[j]);
//         if (cross >= 0)
//             ++i;
//         if (cross <= 0)
//             ++j;
//     }
//     return result;
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

// int main()
// {
//     ll n, m, sum = 0;
//     long double avg;
//     cin >> n;
//     map<string, vector<string>> bd;
//     vector<string> dict;
//     for (int i = 0; i < n; i++)
//     {
//         string s, s1, fn, ln;
//         cin >> s;
//         ll j = 0;
//         fn = "";
//         while (s[j] != ',')
//         {
//             fn += s[j];
//             j++;
//         }
//         j++;
//         ln = "";
//         while (s[j] != ',')
//         {
//             ln += s[j];
//             j++;
//         }
//         j++;
//         s1 = "";
//         vector<string> vs;
//         while (j < s.size())
//         {
//             if (s[j] == ',')
//             {
//                 if (s1.size() == 0)
//                 {
//                     vs.push_back("0");
//                 }
//                 else
//                 {
//                     vs.push_back(s1);
//                 }
//                 s1 = "";
//             }
//             else
//             {
//                 s1 += s[j];
//             }
//             j++;
//         }
//         vs.push_back(s1);
//         s1 = "";
//         bd[fn + " " + ln] = vs;
//         dict.push_back(fn + " " + ln);
//         sum += stol(vs[0]);
//     }
//     avg = (long double)sum / (long double)n;
//     cin >> m;
//     for (int i = 0; i < m; i++)
//     {
//         string s, s1 = "", id = "", fn = "", ln = "", inc = "";
//         cin >> s;
//         ll j = 0;
//         while (s[j] != ',')
//         {
//             id += s[j];
//             j++;
//         }
//         j++;
//         while (s[j] != ',')
//         {
//             fn += s[j];
//             j++;
//         }
//         j++;
//         while (s[j] != ',')
//         {
//             ln += s[j];
//             j++;
//         }
//         j++;
//         while (j < s.size())
//         {
//             inc += s[j];
//             j++;
//         }
//         j++;
//         string bm = getBestMatchingString(dict, fn + " " + ln);
//         ll ta = stol(bd[bm][1]);
//         ll tl = stol(bd[bm][2]);
//         ll bs = stol(bd[bm][4]);
//         ll sp = stol(bd[bm][0]);
//         ll income = stoi(inc);
//         long double f = (long double)sp / (long double)income;
//         if (bd[bm][3] == "1")
//         {

//             if (ta > tl && bs > 30 && f > 0.1 && sp > avg)
//             {
//                 cout << id << ","
//                      << "Yes" << endl;
//             }
//             else
//             {
//                 cout << id << ","
//                      << "No" << endl;
//             }
//         }
//         else
//         {
//             if (ta > tl && bs > 50 && f > 0.1 && sp > avg)
//             {
//                 cout << id << ","
//                      << "Yes" << endl;
//             }
//             else
//             {
//                 cout << id << ","
//                      << "No" << endl;
//             }
//         }
//     }
//     return 0;
// }

// int damerau_levenshtein_distance(string p_string1, string p_string2)
// {
//     int l_string_length1 = p_string1.length();
//     int l_string_length2 = p_string2.length();
//     int d[l_string_length1 + 1][l_string_length2 + 1];

//     int i;
//     int j;
//     int l_cost;

//     for (i = 0; i <= l_string_length1; i++)
//     {
//         d[i][0] = i;
//     }
//     for (j = 0; j <= l_string_length2; j++)
//     {
//         d[0][j] = j;
//     }
//     for (i = 1; i <= l_string_length1; i++)
//     {
//         for (j = 1; j <= l_string_length2; j++)
//         {
//             if (p_string1[i - 1] == p_string2[j - 1])
//             {
//                 l_cost = 0;
//             }
//             else
//             {
//                 l_cost = 1;
//             }
//             d[i][j] = std::min(
//                 d[i - 1][j] + 1,                   // delete
//                      min(d[i][j - 1] + 1,          // insert
//                          d[i - 1][j - 1] + l_cost) // substitution
//             );
//             if ((i > 1) &&
//                 (j > 1) &&
//                 (p_string1[i - 1] == p_string2[j - 2]) &&
//                 (p_string1[i - 2] == p_string2[j - 1]))
//             {
//                 d[i][j] = std::min(
//                     d[i][j],
//                     d[i - 2][j - 2] + l_cost // transposition
//                 );
//             }
//         }
//     }
//     return d[l_string_length1][l_string_length2];
// }

// string getBestMatchingString(vector<string> &dictionary, string toMatch)
// {
//     vector<int> distances(dictionary.size());
//     int mn = INT_MAX;
//     string ms = "";
//     for (int i = 0; i < dictionary.size(); ++i)
//     {
//         distances[i] = damerau_levenshtein_distance(dictionary[i], toMatch);
//         if (distances[i] < mn)
//         {
//             mn = distances[i];
//             ms = dictionary[i];
//         }
//     }
//     return ms;
// }
