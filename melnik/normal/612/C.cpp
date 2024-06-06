#include <iostream>
#include <fstream>
#include <stdio.h>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1e6 + 100;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

char t[maxn];
list < int > a;

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, kol = 0, j;
    gets( t );
    n = strlen( t );
    for ( j = 0; j < n; j++ ) {
        if ( t[j] == '<' || t[j] == '[' || t[j] == '{' || t[j] == '(' ) kol++; else kol--;
        if ( kol < 0 ) break;
    }
    if ( kol != 0 ) {
        printf ( "Impossible\n" );
        return 0;
    }
    int ans = 0;
    for ( j = 0; j < n; j++ ) {
        if ( t[j] == '<' || t[j] == '[' || t[j] == '{' || t[j] == '(' ) {
            a.pb( t[j] );
            continue;
        }
        if ( t[j] == ')' && a.back() == '(' ) ans--;
        if ( t[j] == ']' && a.back() == '[' ) ans--;
        if ( t[j] == '}' && a.back() == '{' ) ans--;
        if ( t[j] == '>' && a.back() == '<' ) ans--;
        ans++;
        a.pop_back();
    }
    printf ( "%d\n", ans );
    return 0;
}