#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<string> stored(n);
    for (int i = 0; i < n; i++) {
        cin >> stored[i];
    }

    while (q--) {
        string s;
        cin >> s;

        bool found = false;

        for (const string &t : stored) {
            if (t.length() != s.length()) continue;

            int diff = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != t[i]) {
                    diff++;
                    if (diff > 1) break;
                }
            }

            if (diff == 1) {
                found = true;
                break;
            }
        }

        cout << (found ? "Yes" : "No") << "\n";
    }

    return 0;
}