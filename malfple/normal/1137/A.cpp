//pragma
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define mp make_pair

#define pb push_back
#define F first
#define S second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
    return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
    return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

#define getc getchar
template<typename T>
T getnum(){
    int sign = 1;
    T ret = 0;
    char c;

    do{
        c = getc();
    }while(c == ' ' || c == '\n');
    if(c == '-')sign = -1;
    else ret = c-'0';
    while(1){
        c = getc();
        if(c < '0' || c > '9')break;
        ret = 10*ret + c-'0';
    }
    return sign * ret;
}

inline void ini(int& x){
    x = getnum<int>();
}

inline void scani(int& x){
    scanf("%d",&x);
}

//end of macro

const int N = 1005;

int n,m;
int arr[N][N];
map<int,int> mepx[N], mepy[N];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    cin>>n>>m;
    REP(i,1,n){
        REP(j,1,m){
            cin>>arr[i][j];
            mepx[i][arr[i][j]] = 0;
            mepy[j][arr[i][j]] = 0;
        }
    }
    REP(i,1,n){
        int cntr = 0;
        for(map<int,int>::iterator it = mepx[i].begin(); it != mepx[i].end(); it++){
            it->S = ++cntr;
        }
    }
    REP(i,1,m){
        int cntr = 0;
        for(map<int,int>::iterator it = mepy[i].begin(); it != mepy[i].end(); it++){
            it->S = ++cntr;
        }
    }
    
    REP(i,1,n){
        REP(j,1,m){
            int lo = 0, hi = 0;
            int px = mepx[i][arr[i][j]];
            lo = max(lo, px-1);
            hi = max(hi, (int)mepx[i].size()-px);
            int py = mepy[j][arr[i][j]];
            lo = max(lo, py-1);
            hi = max(hi, (int)mepy[j].size()-py);
            cout << lo+hi+1 << " ";
        }
        cout << endl;
    }

    return 0;
}