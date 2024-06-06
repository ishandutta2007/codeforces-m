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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    int aid = 0;
    int bid = 0;
    rep(i,n){
        if(a[i]==1){
            aid = i;
        }
        if(b[i]==1){
            bid = i;
        }
    }
    vector<int> p,q;
    for(int i=0;i<n;i++){
        if(a[(aid+i)%n]!=0){
            p.push_back(a[(aid+i)%n]);
        }
        if(b[(bid+i)%n]!=0){
            q.push_back(b[(bid+i)%n]);
        }
    }
    if(p==q){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}