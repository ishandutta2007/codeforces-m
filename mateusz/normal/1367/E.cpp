#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.first <<","<<P.second <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif
const int N = 100005;
int n, k;
char word[N];
int cnt[N];

bool good(int w, int d) {
    int ans = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        ans += cnt[i] / w;
    }
    return ans >= d;
}

int check(int d) {
    int low = 1;
    int high = n;
    int res = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (good(mid, d)) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res * d;
}
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
 
        scanf("%s", &word[1]);
        for (int i = 'a'; i <= 'z'; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) {
            cnt[word[i]]++;
        }
        
        int ans = 0;
        for (int d = 1; d <= k; d++) {
            if (k % d == 0) {
                ans = max(ans, check(d));
            }
        }
        printf("%d\n", ans);
        
    }
    
    return 0;
}