#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int>alice(5);
	vector<int>bob(4);
	for (int i = 0; i < 5; ++i)
	{
		cin>>alice[i];
	}
	for (int i = 0; i < 4; ++i)
	{
		cin>>bob[i];
	}	
	sort(alice.begin(), alice.end());
	sort(bob.begin(), bob.begin());
	for (int i = 0; i < bob.size(); i)
	{
		if(alice[i]!=bob[i]){
			cout<<alice[i]<<endl;
			break;
		}
	}
	return 0;
}
