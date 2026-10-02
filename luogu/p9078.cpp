#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' ||
           c == 'o' || c == 'u' || c == 'y';
}

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int cnt = 0;
    int last = -1;

    long long ans = 0;

    for (int i = 0; i < n; i++) {

        if (i == 0 || isVowel(s[i]) != isVowel(s[i - 1])) {
            cnt = 1;
        } else {
            cnt++;
        }

        if (cnt >= 3) {
            last = i - 2;
        }

        if (last != -1) {
            ans += last + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
