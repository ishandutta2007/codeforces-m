#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
void solve(){
  ll n,d;cin>>n;
  deque<ll>q;
  for(int i=0;i<n;i++){
    cin>>d;
    q.push_back(d);
  }
  ll ans = 0,a=0,b=0;
  ll val = q.front()-1;
  while(q.size()>0){
    ll oo = 0;
    if(ans%2==0){
      while(q.size()>0 && oo<=val){
        a+=q.front();
        oo+=q.front();
        q.pop_front();
      }
    }else{
      while(q.size()>0 && oo<=val){
        b+=q.back();
        oo+=q.back();
        q.pop_back();
      }
    }
    val=oo;
    ans++;
  }
  cout<<ans<<" "<<a<<" "<<b<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
      //  cout<<"Case #"<<i+1<<" :";
       	solve();
    }   
}