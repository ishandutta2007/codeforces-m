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
int testCases;
int n;

// find primes
vi getFactors(int x) {
    vi ans;
    for(int i=2; i*i<=x; i++) {
        while(x%i == 0) {
            ans.pb(i);
            x /= i;
        }
    }
    if(x > 1) ans.pb(x);
    return ans;
}


void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n;
        bool win = n%2;
        if(n == 1) win = 0;
        else {
            if(!win) {
                vi f = getFactors(n);
                int cnt = 0, cnt2=0;
                for(int i:f) if(i%2) cnt++;
                for(int i:f) if(i==2) cnt2++;
                win = cnt >= 2;
                if(cnt2 >= 2 && cnt >= 1) win = 1;
            }
        }
        if(n == 2) win = 1;
        cout<<(win ? "Ashishgup" : "FastestFinger")<<endl;
    }
}