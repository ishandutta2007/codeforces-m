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
        vector<int> s(n);
        s[0] = a[0];
        rep(i,n-1) s[i+1] = s[i] + a[i+1];
        int sm = s[n-1];
        int mi = n-1;
        for(int i=1;i<sqrt(sm)+2;i++){
            if(sm%i ==0){
                int k = sm/i;
                int cnt = 0;
                rep(j,n){
                    if(s[j]%i==0){
                        cnt++;
                    }    
                }
                if(cnt==k){
                    chmin(mi,n-k);   
                }
                cnt = 0;
                rep(j,n){
                    if(s[j]%k==0){
                        cnt++;
                    }    
                }
                if(cnt==i){
                    chmin(mi,n-i);   
                }
            }
        }
        cout << mi << "\n";
    }
    return 0;
}