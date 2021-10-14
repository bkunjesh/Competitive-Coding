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
#define dbg(...) logger(#__VA_ARGS__, VA_ARGS)
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

int n;

void solve()
{

    int i, j, k;
    // if((0)&(5+9)>(5&15+9)) cout<<"YES"<<endl;

    // cout<<((16&11))<<endl;

    int p=5,q=6,r=9;

    q=6+q;
    if((p^5)&(5+9)>(p&q+r))
    {
        p=5+p;
        p=(p+6)+p;
        r=p^r;
    }
    p=11&p;
    cout<<p+q+r<<endl;

return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    //cin >> t;
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


struct  Node * uncommonNode( struct  node * temp_list1, struct  node * temp_list_2) 
{

    set<int> current_elements;

    while(temp_list_2!=NULL) current_elements.insert(temp_list_2->data) , temp_list_2=temp_list_2-> next;

    while( temp_list1!=NULL && current_elements.count(temp_list1->data) )  temp_list1=temp_list1->next;
    Node * temp=temp_list1;
    while(temp!=NULL && temp->next!=NULL) {
            Node * temp2=temp->next;
            while(temp2!=NULL && current_elements.count(temp2->data)) temp2=temp2->next;
            temp->next=temp2;
            temp=temp2;
    }

    return temp_list1;
    
};

struct  Node * uncommonNode( struct  Node * list1, struct  Node * list2) 
{

    set<int> s;

    while(list2!=NULL) s.insert(list2->data) , list2=list2-> next;

    while( list1!=NULL && s.count(list1->data) )  list1=list1->next;
    Node * temp=list1;
    while(temp!=NULL && temp->next!=NULL) {
            Node * temp2=temp->next;
            while(temp2!=NULL && s.count(temp2->data)) temp2=temp2->next;
            temp->next=temp2;
            temp=temp2;
    }

    return list1;
    
};