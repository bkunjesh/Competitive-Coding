Given a matrix Sorted row wise and cloumn wise
 3  4  5  7  8
 9  12 15 19 34
 38 42 45 59 62
 70 73 80 82 85 
 
 Given an element, return its index.
 
 if not preset return -1 -1
 
 
 void searchElement(vector<vector<int>> a,int x)
 {
    int n=a.size();
    int m=a[0].size();
    
    auto check1=[&](int mid)
    {
        if(a[mid][0]<=x) return 1;
        else return 0;
    }
    
    int l=0,r=n-1,ans=-1;
    while(l<=r)
    {
        int mid=l+(h-l)/2;
        
        if(check1(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    
    if(ans==-1)
    {
        cout<<-1<<" "<<-1<<endl;
        return;
    }
    if(a[ans][0]==x)
    {
        cout<<ans<<","<<0<<endl;
        return;
    }
    int row=ans;
    l=0,r=m-1,ans=-1;
    
    while(l<=r)
    {
        int mid=l+(h-l)/2;
        
        if(a[row][mid]==x)
        {
            cout<<row<<" "<<mid<<endl;
            return;
        }
        else if(a[row][mid]<x)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    
    
    cout<<-1<<" "<<-1<<endl;
    
    
 }
 
 
  Q2.abab
     ab
     YES
     Input string
     Target String
     If its possible to get target string from input string.
     
     abab
     bb
     NO
     bab
     YES
     
     
     ababcd
     ab
     YES
     
     012345678
     ababcdabb
       i
     abb
       j
       
     
aababab
i

ababa
j

abaabacd

aa

ba

void ismatch(string s,string t)
{
    int n=s.size(),m=t.size();
    
    int i=n-1,j=m-1,ans=0;
    
    while(1)
    {
        if(s[i]==s[j]) i--,j--;
        else 
        {
            i-=2;
            ans++;
            
        }
        if(j<0)
        {
            ans+=(i/2+i%2);
            cout<<1<<endl;
            return;
        }
        if(i<0)
        {
            cout<<0<<end;
            break;
        }
    }
}

      
     
     
     