#include <math.h>
#include <complex>
using namespace std;

const double PI = acos(-1);

complex<double> rotate(complex<double> vec, double ang) {
    double x = real(vec), y = imag(vec);
    return complex<double> (x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));
}
