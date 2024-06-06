#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;
int n, m, a[MX];

// segment tree library
class SegTree {
    // interface
    typedef ii T;
    typedef T LT;

    T getDefault(int x) {
        return {a[x], 0};
    }
    T getEmpty() {
        return {0,-1};
    }
    T combine(T x, T y) {
        if(x.se == -1) return y;
        if(y.se == -1) return x;
        if(x.se)
            return {x.fi^y.fi,0};
        return {x.fi|y.fi,1};
    }

    LT getDefaultLazy() {
        return getEmpty();
    }
    T addLazy(T x, LT y) {
        return combine(x, y);
    }
    LT combineLazy(LT x, LT y) {
        return combine(x, y);
    }

public:
    void create(int size) {
        _size = size;
        SEG .resize(_size*4);
        LAZY.resize(_size*4);
        create(0,0,_size-1);
    }
    void set(int i, T v) {
        set(i, v, getDefaultLazy(), 0, 0, _size-1);
    }
    void add(int i, int j, LT v) {
        add(i, j, v, getDefaultLazy(), 0, 0, _size-1);
    }
    T get(int i, int j) {
        if(j < i) return getEmpty();
        return get(i, j, getDefaultLazy(), 0, 0, _size-1);
    }
    T get() {
        return get(0, _size-1);
    }

private:
    void create(int p, int l, int r) {
        if(l == r) {
            SEG[p] = getDefault(l);
            return;
        }
        int m=(l+r)/2;
        create(p*2+1,l,m);
        create(p*2+2,m+1,r);
        LAZY[p] = getDefaultLazy();
        SEG [p] = combine(SEG[p*2+1], SEG[p*2+2]);
    }
    void set(int i, T v, LT lazy, int p, int l, int r) {
        SEG [p] = addLazy(SEG[p], lazy);
        LAZY[p] = combineLazy(LAZY[p], lazy);
        if(i < l || i > r) return;
        if(l == r) {
            SEG[p] = v;
            return;
        }
        int m=(l+r)/2;
        set(i,v,LAZY[p],p*2+1,l,m);
        set(i,v,LAZY[p],p*2+2,m+1,r);
        LAZY[p] = getDefaultLazy();
        SEG [p] = combine(SEG[p*2+1], SEG[p*2+2]);
    }
    void add(int i, int j, LT v, LT lazy, int p, int l, int r) {
        SEG [p] = addLazy(SEG[p], lazy);
        LAZY[p] = combineLazy(LAZY[p], lazy);
        if(j < l || i > r) return;
        if(i <= l && j >= r) {
            SEG [p] = addLazy(SEG[p], v);
            LAZY[p] = combineLazy(LAZY[p], v);
            return;
        }
        int m=(l+r)/2;
        add(i,j,v,LAZY[p],p*2+1,l,m);
        add(i,j,v,LAZY[p],p*2+2,m+1,r);
        LAZY[p] = getDefaultLazy();
        SEG [p] = combine(SEG[p*2+1], SEG[p*2+2]);
    }
    T get(int i, int j, LT lazy, int p, int l, int r) {
        SEG [p] = addLazy(SEG[p], lazy);
        LAZY[p] = combineLazy(LAZY[p], lazy);
        if(j < l || i > r) return getEmpty();
        if(i <= l && j >= r) return SEG[p];
        int m=(l+r)/2;
        T a = get(i,j,LAZY[p],p*2+1,l,m);
        T b = get(i,j,LAZY[p],p*2+2,m+1,r);
        LAZY[p] = getDefaultLazy();
        return combine(a,b);
    }

    vector<T> SEG;
    vector<LT> LAZY;
    int _size=0;
};

void program() {
    cin>>n>>m; n=1<<n;
    RE(i,n) cin>>a[i];
    SegTree seg;
    seg.create(n);
    RE(i,m) {
        int p, b; cin>>p>>b;
        seg.set(p-1, {b,0});
        cout<<seg.get(0,n-1).fi<<endl;
    }
}