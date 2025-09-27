#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a;

    cout << "Initially: size = " << a.size()
         << ", capacity = " << a.capacity() << "\n";

    a.push_back(1);
    cout << "After push_back(1): size = " << a.size()
         << ", capacity = " << a.capacity() << "\n";

    a.push_back(2);
    cout << "After push_back(2): size = " << a.size()
         << ", capacity = " << a.capacity() << "\n";

    a.push_back(4); // may trigger reallocation
    cout << "After push_back(4): size = " << a.size()
    << ", capacity = " << a.capacity() << "\n";

    auto it = a.begin(); // iterator to first element

    a.push_back(5);
    cout << "After push_back(5): size = " << a.size()
         << ", capacity = " << a.capacity() << "\n";

    a.push_back(6);
    cout << "After push_back(6): size = " << a.size()
         << ", capacity = " << a.capacity() << "\n";

    cout << "Iterator value *it (dangling if reallocated): "
         << *it << "\n";
}
