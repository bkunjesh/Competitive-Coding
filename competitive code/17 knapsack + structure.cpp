#include<iostream>
#include<vector>
using namespace std;

struct object
{
	double prof;
	double wt;
	double ratio;
};
double profit(struct object obj[7],double wt,double netprofit)  //wt& profit =0 kar dena main me
{
	double max_ratio=0;
	int max_index;
	for(int i=0;i<7;i++)
	{
		if(obj[i].ratio > max_ratio)
		{
	       max_ratio=obj[i].ratio;
	       max_index=i;
	    }
	}
	wt=wt+obj[max_index].wt;
	if(wt>15)
	{
		wt=wt-obj[max_index].wt;
		netprofit+=((15-wt)/obj[max_index].wt)*obj[max_index].prof;
		cout<<netprofit;
		return 0;
	
	}
	netprofit+=obj[max_index].prof;
	obj[max_index].ratio=0;
	profit(obj,wt,netprofit);
}


int main()
{
	//m=15
	struct object obj[7];
	double wt=0,netprofit=0,max=0;
	for(int i=0;i<7;i++)
	{
		cin>>obj[i].prof>>obj[i].wt;
		obj[i].ratio=obj[i].prof/obj[i].wt;
	}
/*	for(int i=0;i<7;i++)
	{
		cout<<" "<<obj[i].prof<<" "<<obj[i].wt<<" "<<obj[i].ratio<<endl;
	}
*/
	profit(obj,wt,netprofit);
	
	
	
	
}
