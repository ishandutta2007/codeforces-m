#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,m; cin>>n>>m;
  /*ll a[n];
  fore(i,0,n)a[i]=1;
  fore(i,0,m){
    a[]*/
  if(m>=(n+1)/2){
    cout<<n-m;   
  }else if(m==0){
    cout<<1;  
  }else{
    cout<<m;
  }
    

	return 0;
}