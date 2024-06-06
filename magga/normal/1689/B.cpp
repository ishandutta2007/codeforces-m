#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
void solve(){
    int n;cin>>n;
    set<int>s;
    for(int i=1;i<=n;i++) s.insert(i);
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n==1){
        cout<<-1<<"\n";
        return;
    }
    ll ans[n];
    for(int i=0;i<n-1;i++){
        auto p = (*s.begin());
        ll t = p;
        if(p==arr[i]){
            s.erase(p);
            t = (*s.begin());
            s.insert(p);
        }
        ans[i] = t;
        s.erase(t);
    }
    ans[n-1] = (*s.begin());
    if( arr[n-1] == ans[n-1] ){
        swap(ans[n-1],ans[n-2]);
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}