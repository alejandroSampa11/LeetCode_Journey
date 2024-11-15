#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;cin>>n;
	long long resu = n/4;
	if(n%2!=0){
		cout<<0<<endl;
	}
	else if(n%4==0){
		cout<<resu-1<<endl;
	}else{
		cout<<resu<<endl;
	}
	return 0;
}
