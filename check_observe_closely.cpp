#include<bits/stdc++.h>
using namespace std;

struct A {
    A() { cout << "1"; }
    A(const A &a) { cout << "2"; }
    virtual void f() { cout << "3"; }
};

int main() {
    A a[2];
    for (auto x : a) {
        x.f();
    }
}