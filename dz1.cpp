#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, max_ = -1, s = 0;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        max_ = max(a[i], max_);
        s += a[i];
    }
    ll e = min(s / 2, s - max_);
    cout << e << "\n";

    for (ll i = 0; i < n - 1; i++) {
        for (ll j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                ll k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
                cout << j << " " << j + 1 << "\n";
            }
        }
    }

    return 0;
}