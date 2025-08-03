// Segment Tree Template
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int seg[4 * N];

void build(int idx, int l, int r, vector<int> &arr) {
    if (l == r) {
        seg[idx] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid, arr);
    build(2 * idx + 1, mid + 1, r, arr);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

int query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && r <= qr) return seg[idx];
    int mid = (l + r) / 2;
    return query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr);
}

void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
        seg[idx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(2 * idx, l, mid, pos, val);
    else update(2 * idx + 1, mid + 1, r, pos, val);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}
