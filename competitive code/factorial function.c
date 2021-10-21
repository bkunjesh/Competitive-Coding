#include<stdio.h>
int fac(a)
{
    int i,ans;
    ans=1;
    for(i=1;i<=a;i++)
    {
                     ans=ans*i;
    }
return ans;
}

    int main()
    {
        int n,k;
        scanf("%d\n%d",&n,&k);
        if(n>k){
                 printf("n choose k is %d ",((fac(n)/fac(k))/fac(n-k)));}
        
        
        system("pause");
        return 0;
    }
