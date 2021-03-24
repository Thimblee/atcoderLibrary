#include <vector>
using namespace std;

// Q(i,j) := 整数iを順序を区別せずに「j個の自然数」の和に分ける場合の数
// R(i,j) := 整数iを順序を区別せずに「j個以下の自然数」の和に分ける場合の数
template<typename T> struct PartitionNumber {
    int n;
    vector<vector<T>> _Q, _R;
    PartitionNumber(int _n) {
        n = _n;
        _Q.resize(n + 1, vector<T>(n + 1));
        _R.resize(n + 1, vector<T>(n + 1));

        _Q[0][0] = 1;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                _Q[i][j] += _Q[i - 1][j - 1];
                if (j <= i) _Q[i][j] += _Q[i - j][j];
            }
        }
        for (int i = 0; i < n + 1; ++i) {
            _R[i][0] = _Q[i][0];
            for (int j = 1; j < n + 1; ++j) {
                _R[i][j] = _R[i][j - 1] + _Q[i][j];
            }
        }
    }

    T R(int i, int j) {
        assert(0 <= j and 0 <= i and j <= n and i <= n);
        return _R[i][j];
    }
};