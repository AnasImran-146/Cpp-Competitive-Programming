#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long calculate_score(long long a, long long b, const vector<long long>& v) {
    long long score = 0;
    for (long long val : v) {
        long long dist_b = abs(val - b);
        long long dist_a = abs(val - a);

        if (dist_b < dist_a) {
            score++;
        }
    }
    return score;
}

void solve() {
    int n;
    long long a;
    if (!(cin >> n >> a)) return;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    long long max_score = calculate_score(a, a + 1, v);
    long long best_b = a + 1;

    for (int i = 0; i < n - 1; ++i) {
        long long v_i = v[i];
        long long v_i_plus_1 = v[i + 1];
        long long target_b = v_i + v_i_plus_1 - a;
        long long current_score = calculate_score(a, target_b, v);

        if (current_score > max_score) {
            max_score = current_score;
            best_b = target_b;
        }
    }
    
    for (long long val : v) {
        long long current_score = calculate_score(a, val, v);
        if (current_score > max_score) {
            max_score = current_score;
            best_b = val;
        }
    }

    long long b_win_all = v[0] - abs(v[0] - a) - 1; 
    if (b_win_all < 0) b_win_all = 0;

    long long safe_large_b = 2000000000;
    long long large_b_score = calculate_score(a, safe_large_b, v);
    if(large_b_score > max_score){
        best_b = safe_large_b;
    }
    
    cout<<best_b<<"\n";
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}