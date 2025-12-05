#include<bits/stdc++.h>
using namespace std;

#define int long long

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* first = head;
    ListNode* second = head->next;
    first->next = swapPairs(second->next);
    second->next = first;
    return second;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ListNode* node = new ListNode(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    head = swapPairs(head);

    ListNode* cur = head;
    bool first = true;
    while (cur) {
        if (!first) cout << " ";
        cout << cur->val;
        first = false;
        cur = cur->next;
    }
    cout << "\n";

    cur = head;
    while (cur) {
        ListNode* tmp = cur->next;
        delete cur;
        cur = tmp;
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
