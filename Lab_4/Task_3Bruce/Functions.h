#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "vector.h"
#include "pair.h"

void Normalize(vector<int>& c) {
    for (int i = 0; i < (int)c.size() - 1; ++i) {
        c[i + 1] += c[i] >> 1;
        c[i] &= 1;
    }
}

void AddZero(vector<int>& c, int x) {
    c.resize(x + 1);
    c[x] = 0;
}

vector<int> AddNum(vector<int>& a, vector<int>& b, int k) {

    vector<int> c(std::max(a.size(), b.size()) + 1);

    for (int i = 0; i < (int)c.size(); ++i) {
        if (i < (int)a.size()) {
            c[i] += a[i];
        }
        if (i < (int)b.size()) {
            c[i] += b[i];
        }
    }

    Normalize(c);
    AddZero(c, k);

    return c;
}

int GetBit(vector<int>& v, int b) {
    return v[b] & 1;
}

vector<int> Multiply(vector<int>& a, int x, int k) {

    vector<int> b = a;
    b.push_back(0);

    for (int i = 0; i < (int)b.size(); ++i) {
        b[i] *= x;
    }

    Normalize(b);
    AddZero(b, k);

    return b;
}

void GenerateSequence(vector<int> n, vector<vector<int>>& p, int k, int i, vector<Pair<int, vector<int>>>& v) {
    if (i == k) {
        n.resize(k + 1);
        if (GetBit(n, k)) {
            v.push_back(make_pair(k, n));
        }
        return;
    }

    if (GetBit(n, i)) {
        return;
    }

    GenerateSequence(n, p, k, i + 1, v);

    if (i) {
        GenerateSequence(AddNum(n, p[i], k + 1), p, k, i + 1, v);
    }
    return;
}
#endif // FUNCTIONS_H
