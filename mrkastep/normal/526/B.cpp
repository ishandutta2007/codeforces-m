#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;

vector<vector<pair<int,int>>> g;

int ans=0;

int deep(int v){
    int t=0,sm=0,tmp;
    For(i,g[v].size()){
        tmp=deep(g[v][i].x);
        sm+=tmp;
        sm+=g[v][i].y;
        t=max(t,tmp+g[v][i].y);
    }
    ans+=t*g[v].size()-sm;
    return t;
}

void solve(int n){
    int a;
    g.resize((1<<(n+1)));
    For(i,(1<<(n+1))-2){
        scanf("%d",&a);
        g[(i+2)/2].pb(mp(i+2,a));
    }
    deep(1);
    printf("%d",ans);



}






int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    char c[100100];
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}