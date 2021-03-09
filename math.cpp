#include <vector>
#include <algorithm>
using namespace std;

bool isprime(long long N) {
    if (N%2 == 0) return false;
    long long f = 3;
    while (f*f <= N) {
        if (N%f == 0) return false;
        f += 2;
    }
    return true;
}

vector<long long> prime_factorize(long long N) {
    vector<long long> vec;
    while (N % 2 == 0) {
        vec.push_back(2);
        N /= 2;
    }
    long long f = 3;
    while (f*f <= N) {
        if (N%f == 0) {
            vec.push_back(f);
            N /= f;
        }
        else f += 2;
    }
    if (N != 1) vec.push_back(N);
    return vec;
}

vector<pair<long long, long long>> prime_f(long long N) {
    vector<pair<long long, long long>> res;
    if (N%2 == 0) {
        long long ex = 0;
        while (N%2 == 0) {
            ++ex;
            N /= 2;
        }
        res.push_back({2, ex});
    }
    for (long long f = 3; f*f <= N; f += 2) {
        if (N%f == 0) {
            long long ex = 0;
            while (N%f == 0) {
                ++ex;
                N /= f;
            }
            res.push_back({f, ex});
        }
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i*i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i*i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

struct Eratos {
    vector<int> primes;
    vector<bool> isprime;
    vector<int> min_factor;

    Eratos(int MAX) : primes(), isprime(MAX+1, true), min_factor(MAX+1, -1) {
        isprime[0] = isprime[1] = false;
        min_factor[0] = 0, min_factor[1] = 1;
        for (int i = 2; i <= MAX; ++i) {
            if (!isprime[i]) continue;
            primes.push_back(i);
            min_factor[i] = i;
            for (int j = i*2; j <= MAX; j += i) {
                isprime[j] = false;
                if (min_factor[j] == -1) min_factor[j] = i;
            }
        }
    }

    vector<pair<int, int>> prime_factors(int n) {
        vector<pair<int, int>> res;
        while (n != 1) {
            int prime = min_factor[n];
            int exp = 0;
            while (min_factor[n] == prime) {
                ++exp;
                n /= prime;
            }
            res.push_back(make_pair(prime, exp));
        }
        return res;
    }

    vector<int> divisors(int n) {
        vector<int> res({1});
        auto pf = prime_factors(n);
        for (auto p : pf) {
            int len = (int)res.size();
            for (int i = 0; i < len; ++i) {
                int v = 1;
                for (int j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};
