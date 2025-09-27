#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    map<int, int> freqs;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        freqs[val]++;
    }

    map<int, long long> total_moves_by_freq;
    for(auto const& [val, cnt] : freqs)
        total_moves_by_freq[cnt] += val;

    vector<int> sorted_freqs;
    for(auto const& [cnt, total_moves] : total_moves_by_freq)
        sorted_freqs.push_back(cnt);

    sort(sorted_freqs.rbegin(), sorted_freqs.rend());

    long long alice_score = 0;
    long long bob_score = 0;
    long long total_turns = 0;

    for(int c : sorted_freqs) {
        long long moves_in_phase = total_moves_by_freq[c];

        long long alice_moves_in_phase = (moves_in_phase + 1) / 2;
        long long bob_moves_in_phase = moves_in_phase / 2;

        if(total_turns % 2 == 1)
            swap(alice_moves_in_phase, bob_moves_in_phase);

        alice_score += alice_moves_in_phase * c;
        bob_score += bob_moves_in_phase * c;

        total_turns += moves_in_phase;
    }

    cout << alice_score << " " << bob_score << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
