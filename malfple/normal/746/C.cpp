#include <iostream>
#include <cstdio>

#include <cstring>
#include <string>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define repp(i,a,b,d) for(int i=a;i<=b;i+=d)
#define rep(i,a,b) repp(i,a,b,1)
#define revv(i,a,b,d) for(int i=a;i>=b;i-=d)
#define rev(i,a,b) revv(i,a,b,1)

#define mp make_pair

#define pb push_back
#define ff first
#define ss second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

//end of macro

int main(){
    int s,a,b;
    cin>>s>>a>>b;
    int t1,t2;
    cin>>t1>>t2;
    int x,d;
    cin>>x>>d;

    int ans = abs(a-b)*t2;

    if(d == -1){
        a = s-a;
        b = s-b;
        x = s-x;
    }

    if(x <= b){
        if(a < x){
            x = 2*s - x;
            x = -x;
        }else if(a > b){
            x = 2*s - x;
        }
    }else{
        x = 2*s - x;
        if(a < b)x = -x;
    }

    ans = min(ans, abs(x-b)*t1);

    printf("%d\n",ans);
    return 0;
}