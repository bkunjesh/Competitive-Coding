#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int i;
	vector <int> v;
	for(i=0;i<5;i++)
	v.push_back(i);
	vector<int>::iterator ir;
	for(ir=v.begin();ir!=v.end();ir++)
	cout<<*ir<<" ";
	cout<<endl;
	
	v.insert(v.begin()+2,9);
	
	v.erase(v.begin()+3);
    //v.assign(2,10);
	for(ir=v.begin();ir!=v.end();ir++)
	cout<<*ir<<" "<<" ";
	cout<<endl;
	for(ir=v.begin();ir!=v.end();ir++)
	cout<<*ir<<" "<<v.at(2)<<" ";
}
