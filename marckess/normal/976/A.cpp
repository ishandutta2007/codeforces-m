#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

string s;
int c = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> s >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0')
            c++;

    if (s == "0")
        cout << 0 << endl;
    else {
        cout << 1;
        while (c--)
            cout << 0;
        cout << endl;
    }

    return 0;
}