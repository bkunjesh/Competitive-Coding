#include<iostream>
#include<vector>
using namespace std;
int main(){
	
	int t;
	vector <int> p(5,0);	
	vector<int>::iterator i;
	for(i=p.begin();i<p.end();i++)
	{
		cout<<*i<<endl;
	}
	
	p.push_back(3);
	cout<<endl;
	for(i=p.begin();i<p.end();i++)
	{
		cout<<*i<<endl;
	}
	cout<<*(p.end()-1);
}
