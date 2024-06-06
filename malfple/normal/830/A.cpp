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

int n,k,p;
int arra[1005];
int arrb[2005];

bool cek(int t){
    int j = 1;
    rep(i,1,n){
        while(1){
            if(j > k)return false;
            int tnow = abs(arra[i]-arrb[j]) + abs(arrb[j]-p);
            j++;
            if(tnow <= t)break;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>n>>k>>p;
    rep(i,1,n)cin>>arra[i];
    rep(i,1,k)cin>>arrb[i];

    sort(arra+1, arra+n+1);
    sort(arrb+1, arrb+k+1);

    int lo = 0, mid, hi = 2*OO;
    int ans = hi;
    while(lo <= hi){
        mid = ((ll)lo+hi)/2;
        //cerr << mid << endl;

        if(cek(mid)){
            hi = mid-1;
            ans = min(ans, mid);
        }else{
            lo = mid+1;
        }
    }

    cout << ans << endl;

    return 0;
}