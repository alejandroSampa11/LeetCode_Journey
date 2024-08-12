#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int cases;cin>>cases;
	while(cases--){
		int n;cin>>n;
		int c;cin>>c;
		vector<int>v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
			v[i]+=(i+1);
		}
		sort(v.begin(), v.end());
		int suma=0;
		int contador=0;
		for (int i = 0; i < n; ++i)
		{
			if((suma+v[i])<=c){
				contador++;
				suma+=v[i];
			}
		}
		cout<<contador<<endl;
 
	}
	return 0;
}