#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n){
			a[i] = (i+1)%n + 1;
		}
		
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<a[i];
		}
		cout<<endl;
		
		
		
		
	}
	
	return 0;
}