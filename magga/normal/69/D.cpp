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
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
ll x,y,n,d,u,v;
vector<pii>moves;
map<pii,ll>m;
ll dist(pii a){
    return a.first*a.first+a.second*a.second;
}
ll mex(set<ll> &s){
    int i = 0;
    while(s.find(i)!=s.end()){
        i++;
    }
    return i;
}
ll nim(pii a){
    if(m.find(a)!=m.end()){
        return m[a];
    }
    if(dist(a)>d){
        return 1;
    }
    set<ll>s;
    for(auto i:moves){
        s.insert(nim({a.first+i.first,a.second+i.second}));
    }
    m[a]=mex(s);
    //cout<<a.first<<" "<<a.second<<" "<<m[a]<<"\n";
    return m[a];
}
void solve(){
    cin>>x>>y>>n>>d;
    d*=d;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        moves.pb({u,v});
    }
    if(nim({x,y})>0){
        cout<<"Anton";
    }else{
        cout<<"Dasha";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}