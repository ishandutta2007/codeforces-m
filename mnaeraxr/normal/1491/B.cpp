#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>
#include <map>
#include <math.h>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <stdint.h>

namespace asl
{
    template <typename T>
    using vec = std::vector<T>;

    template <typename T>
    std::istream &operator>>(std::istream &is, std::vector<T> &vec)
    {
        for (auto &value : vec)
            is >> value;
        return is;
    }

} 

#include <experimental/optional>

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, u, v;
    cin >> n >> u >> v;

    vec<int> a(n);
    cin >> a;

    int equal = 1;
    int joint = 1;

    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1])
            equal = 0;

        if (abs(a[i] - a[i - 1]) > 1)
            joint = 0;
    }

    if (!joint)
        cout << 0 << endl;
    else if (!equal)
        cout << min(u, v) << endl;
    else
        cout << v + min(u, v) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}