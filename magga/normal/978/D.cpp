#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
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
ll inf = 1e18;
ll arr[100000];
ll n;
ll check(ll oo,ll oj){
    ll a = oo;
    ll ret = 0;
    ll d = oj-oo;
    for(int i=0;i<n;i++){
        if(arr[i]==a+i*d){
            continue;
        }else if(abs(arr[i]-a-i*d)>1){
            return inf;
        }else{
            ret++;
        }
    }
    return ret;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<0<<"\n";
        return;
    }
    ll ans = inf;
    //cout<<check(arr[0]+1,arr[1]-1)<<"\n";
    ans=min(ans,check(arr[0],arr[1]));
    ans=min(ans,check(arr[0],arr[1]+1));
    ans=min(ans,check(arr[0],arr[1]-1));
    ans=min(ans,check(arr[0]+1,arr[1]));
    ans=min(ans,check(arr[0]-1,arr[1]));
    ans=min(ans,check(arr[0]-1,arr[1]-1));
    ans=min(ans,check(arr[0]-1,arr[1]+1));
    ans=min(ans,check(arr[0]+1,arr[1]-1));
    ans=min(ans,check(arr[0]+1,arr[1]+1));
    if(ans>n){
        ans=-1;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}