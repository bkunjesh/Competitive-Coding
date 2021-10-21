#include<stdio.h>
int main()
{int i,n,ppre,pre,curr;
scanf("%d",&n);

scanf("%d",&ppre);i=1;
while((ppre<0)&&(i<n))
{scanf("%d",&ppre);i=i+1;
                     }
if(i<n)
{scanf("%d",&pre);
while((pre<0)&&(i<n))
{scanf("%d",&pre);i=i+1;
                     
                     }
       }
if(i<n)
{scanf("%d",&curr);
while((curr<0)&&(i<n))
{scanf("%d",&curr);i=i+1; 
                    }       
      }
      
      while(1)
      {if((ppre*ppre)+(pre*pre)==(curr*curr))
      {printf("(%d,%d,%d)",ppre,pre,curr);
      break;}
      else
      {ppre=pre;pre=curr;
      if(i<n){
              scanf("%d",&curr);
              while((curr<0)&&(i<n))
              {scanf("%d",&curr);i=i+1;
                                    }
                                    
              }
          }
          
          
      }
      system("pause");
      return 0;
      
       
    }
