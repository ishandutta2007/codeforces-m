#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
#define mod 998244353
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    vector<ll>a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll sm = 0;
    for(ll i=n;i>n-k;i--){
        sm += i;
    }
    vector<ll> c;
    ll s = 0;
    bool flag = 1;
    for(int i=0;i<n;i++){
        if(a[i]>n-k){
            if(flag){
                flag = 0;
            }else{
                c.push_back(s);
            }
            s = 0;
        }else{
            s++;
        }
    }
    ll res = 1;
    for(auto x:c){
        res *= (x+1);
        res %= mod;
    }
    cout << sm << " " << res << "\n";
    return 0;
}