#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <cassert>
#include <deque>
using namespace std;

#ifndef MDEBUG
#define NDEBUG
#endif

#define x first
#define y second
#define ll long long
#define d double
#define ld long double
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pss pair<string,string>
#define psi pair<string,int>
#define pis pair<int,string>
#define psl pair<string,ll>
#define pls pair<ll,string>
#define wh(x) (x).begin(),(x).end()
#define ri(x) int x;cin>>x;
#define rii(x,y) int x,y;cin>>x>>y;
#define rl(x) ll x;cin>>x;
#define rv(v) for(auto&_cinv:v) cin>>_cinv;
#define wv(v) for(auto&_coutv:v) cout << _coutv << ' '; cout << endl;
#define ev(v) for(auto&_cerrv:v) cerr << _cerrv << ' '; cerr << endl;
#define MOD 1000000007

namespace std { 
template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
// auto fraclt = [](auto&a,auto&b) { return (ll)a.x * b.y < (ll)b.x * a.y; };
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }
template<typename T> void fracn(pair<T,T>&a) {auto g=gcd(a.x,a.y);a.x/=g;a.y/=g;}
template<typename T> struct Index { int operator[](const T&t){auto i=m.find(t);return i!=m.end()?i->y:m[t]=m.size();}int s(){return m.size();} unordered_map<T,int> m; };

int main(int,char**) {
    rii(N,M);
    vector<int> F(N,-1);
    vector<int> S(N,0);
    for (int i = 0; i < M; i++) {
        int p,q;
        cin >> p >> q;
        F[q-1] = p-1;
        S[p-1]++;
    }

    vector<int> P(N);
    rv(P);
    for (int i = 0; i < N; i++) {
        --P[i];
    }

    deque<int> Q;
    vector<int> Sol;
    for (int i = 0; i < N; i++) {
        if (!S[i]) Q.push_back(i); 
    }

    bool ok = true;
    while(Q.size() > 0 && ok) {
        int i = Q.front(); Q.pop_front();
        int j = i;
        while ( true ) {
            if (F[j] == -1) {
                if (P[j] == j) {
                    Sol.push_back(j);
                } else {
                    ok = false;
                }
                break;
            } else if (P[j] == j) {
                Sol.push_back(j);
                if (--S[F[j]] == 0) Q.push_back(F[j]);
                break;
            } else if (P[F[j]] != P[j]) { 
                ok = false;
                break;
            } else if (--S[F[j]] == 0) {
                j = F[j];
            } else {
                break;
            }
        }
    }
    
    if (ok) {
        cout << Sol.size() << endl;
        for (int i:Sol) cout << i+1 << endl;
    } else {
        cout << -1 << endl;
    }

}