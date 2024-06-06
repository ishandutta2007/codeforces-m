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
    int t;
    cin >> t;
    rep(zz,t){
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        bool ng = 0;
        int s = a[0];
        int pre = 0;
        a[0] = 0;
        for(int i=1;i<n;i++){
            if(a[i]<pre){
                ng = 1;
                break;
            }
            if(a[i]-pre <=s){
                s = a[i]-pre;
                a[i] = pre;
            }else{
                a[i]-= s;
                pre = a[i];
            }
        }
        if(ng){
            cout << "NO\n";
            continue;
        }
        int T = a[n-1];
        a[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            if(a[i]<=T){
                T = a[i];
                a[i] = 0;
            }else{
                ng = 1;
            }
        }
        rep(i,n){
            if(a[i]!=0)ng = 1;
        }
        if(ng){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
    return 0;
}