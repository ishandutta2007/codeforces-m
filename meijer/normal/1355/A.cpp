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
ll testCases;
ll a, k;

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>a>>k; k--;
        while(k--) {
            string s;
            stringstream ss;
            ss << a;
            s = ss.str();
            ll mn=9, mx=0;
            REV(i,0,s.sz) {
                ll numb = s[i]-'0';
                mn = min(mn, numb), mx = max(mx, numb);
            }
            if(mn == 0 || mx == 0) break;
            a += mn*mx;
        }
        cout<<a<<endl;
    }
}