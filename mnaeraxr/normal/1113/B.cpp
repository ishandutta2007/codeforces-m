/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author marX
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

class BSashaAndMagneticMachines {
public:
    void solve(std::istream& in, std::ostream& out) {
        int n; in >> n;

        long long sum = 0;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            in >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.end());

        long long answer = sum;

        for (int i = 1; i < n; ++i) {
            for (int x = 1; x <= a[i]; ++x) {
                if (a[i] % x == 0) {
                    long long cur = sum - a[i] - a[0] + a[0] * x + a[i] / x;
                    answer = min(answer, cur);
                }
            }
        }

        out << answer << endl;
    }
};


int main() {
	BSashaAndMagneticMachines solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}