#include <bits/stdc++.h>

using namespace std;

int main(){
	long long cases;cin>>cases;
	while(cases--){
		long long a;cin>>a;
		long long b;cin>>b;
		long long cont = 0;
		if(a==b){
			cout<<"0"<<endl;
			continue;
		}
		while(true){
			if(a<b){
				if((a*8)<=b){
					a*=8;
					cont++;
				}else if((a*4)<=b){
					a*=4;
					cont++;
				}else if((a*2)<=b){
					a*=2;
					cont++;
				}else{
					cout<<"-1"<<endl;
					break;
				}
			}
			if(a>b){
				if((a/8 >= b) && (a%8==0)){
					a/=8;
					cont++;
				}else if((a/4 >= b) && (a%4==0)){
					a/=4;
					cont++;
				}else if((a/2 >= b) && (a%2==0)){
					a/=2;
					cont++;
				}else{
					cout<<"-1"<<endl;
					break;
				}
			}
			if(a==b){
				cout<<cont<<endl;
				break;
			}
		}
	}
	return 0;
}
