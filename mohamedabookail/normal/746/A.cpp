/**
 *    author:  Mohamed Abo_Okail
 *    created: 24/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

int main() 
{
	std::ios_base::sync_with_stdio(0);
	int a, b, c; cin >> a >> b >> c;
	b /= 2; c /= 4;
	cout << min({a, b, c}) * 7 << o_o;
}