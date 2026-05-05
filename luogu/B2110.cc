#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt[26] = {0};
    for (char c : s) {
        cnt[c - 'a']++;
    }
    for (char c : s) {
        if (cnt[c - 'a'] == 1) {
            cout << c;
            return 0;
        }
    }

    cout << "no";
    return 0;
}
