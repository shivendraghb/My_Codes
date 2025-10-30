#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Bank {
    vector<long long> bal;
    int n;

    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }

    bool valid(int acc) {
        return acc > 0 && acc <= n;
    }
    
    bool transfer(int from, int to, long long amt) {
        if(!valid(from) || !valid(to) || bal[from - 1] < amt) return false;
        bal[from - 1] -= amt;
        bal[to - 1] += amt;
        return true;
    }

    bool deposit(int acc, long long amt) {
        if(!valid(acc)) return false;
        bal[acc - 1] += amt;
        return true;
    }

    bool withdraw(int acc, long long amt) {
        if(!valid(acc) || bal[acc - 1] < amt) return false;
        bal[acc - 1] -= amt;
        return true;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<long long> balance(n);
    for(int i = 0; i < n; i++)
        cin >> balance[i];
    
    Bank bank(balance);

    int q;
    cin >> q;

    while(q--) {
        string op;
        cin >> op;

        if(op == "transfer") {
            int a1, a2, m;
            cin >> a1 >> a2 >> m;
            cout << (bank.transfer(a1, a2, m) ? "true\n" : "false\n");
        }
        else if(op == "deposit") {
            int a, m;
            cin >> a >> m;
            cout << (bank.deposit(a, m) ? "true\n" : "false\n");
        }
        else if(op == "withdraw") {
            int a, m;
            cin >> a >> m;
            cout << (bank.withdraw(a, m) ? "true\n" : "false\n");
        }
    }
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