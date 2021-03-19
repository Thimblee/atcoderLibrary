#include <iostream>
#include <vector>
using namespace std;

bool isOK(long long mid) {
    
}

long long binary_search() {
    long long ng = -1;
    long long ok = 1LL << 60;

    while (abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}