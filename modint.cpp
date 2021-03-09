#include <ostream>
using namespace std;

const int mod = 1000000007;
class mint {
    long long x;
public :
    mint(long long x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const {
        return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(long long t) const {
        if(!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint& operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }

    friend ostream& operator<<(ostream& os, const mint& m) {
        os << m.x;
        return os;
    }
};