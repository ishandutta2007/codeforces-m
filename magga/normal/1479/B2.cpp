#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
void solve(){
    ll n;cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll ans = 0;
    pair<pii,bool> a = {{n+1,n+1},0};
    set<ll>s;
    for(int i=0;i<n;i++){
        if(a.S && arr[i]==a.F.F){
            continue;
        }else if(a.S && s.find(arr[i])!=s.end()){
            a.S = 0;
            a.F.S = arr[i];
            s.clear();
        }else if(a.S && s.find(arr[i])==s.end()){
            s.insert(a.F.F);
            a.F.F = arr[i];
            ans++;
        }else if(arr[i]==a.F.F || arr[i]==a.F.S){
            continue;
        }else{
            a.S = 1;
            s.clear();
            s.insert(a.F.F);
            s.insert(a.F.S);
            a.F.F = arr[i];
            ans++;
        }
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