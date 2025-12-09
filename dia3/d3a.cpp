#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    long long total = 0;

    while (cin >> s) {
        int n = s.size();
        vector<int> digits(n);
        for (int i = 0; i < n; i++)
            digits[i] = s[i] - '0';

        int bestRight = -1;
        int bestPair = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (bestRight != -1) {
                int val = digits[i] * 10 + bestRight;
                bestPair = max(bestPair, val);
            }
            bestRight = max(bestRight, digits[i]);
        }

        total += bestPair;
    }

    cout << total << "\n";
}
