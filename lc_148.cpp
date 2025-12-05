#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
    };

    auto readList = [&]() -> ListNode* {
        int n;
        cin >> n;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ListNode* node = new ListNode(x);
            if (!head) head = node;
            else tail->next = node;
            tail = node;
        }
        return head;
    };

    function<ListNode*(ListNode*, ListNode*)> merge = [&](ListNode* a, ListNode* b) -> ListNode* {
        if (!a) return b;
        if (!b) return a;
        if (a->val < b->val) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    };

    function<ListNode*(ListNode*)> sortList = [&](ListNode* head) -> ListNode* {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    };

    ListNode* head = readList();
    head = sortList(head);

    for (ListNode* cur = head; cur; cur = cur->next) {
        cout << cur->val;
        if (cur->next) cout << ' ';
    }
    cout << '\n';
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
