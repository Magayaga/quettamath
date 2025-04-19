#include "quettamath.h"
#include <stdarg.h>

/* Mathematical constants */
struct qm_constant {
    double PI;
    double E;
};

const struct qm_constant qm_constants = {
    .PI = 3.14159265358979323846,
    .E = 2.71828182845904523536
};

// Unary operations
double qm_positive(double x) {
    return x;
}

double qm_negative(double x) {
    return -x;
}

double qm_add(size_t count, ...) {
    va_list args;
    va_start(args, count);
    double sum = 0.0;
    for (size_t i = 0; i < count; ++i) {
        sum += va_arg(args, double);
    }
    va_end(args);
    return sum;
}

double qm_subtract(size_t count, ...) {
    if (count == 0) return 0.0;
    va_list args;
    va_start(args, count);
    double result = va_arg(args, double);
    for (size_t i = 1; i < count; ++i) {
        result -= va_arg(args, double);
    }
    va_end(args);
    return result;
}

double qm_multiply(size_t count, ...) {
    va_list args;
    va_start(args, count);
    double product = 1.0;
    for (size_t i = 0; i < count; ++i) {
        product *= va_arg(args, double);
    }
    va_end(args);
    return product;
}

double qm_divide(size_t count, ...) {
    if (count == 0) return 0.0/0.0;
    va_list args;
    va_start(args, count);
    double result = va_arg(args, double);
    for (size_t i = 1; i < count; ++i) {
        double d = va_arg(args, double);
        if (d == 0.0) {
            /* division by zero yields NaN */
            result = 0.0/0.0;
            break;
        }
        result /= d;
    }
    va_end(args);
    return result;
}

double qm_min(size_t count, ...) {
    if (count == 0) return 0.0/0.0;
    va_list args;
    va_start(args, count);
    double m = va_arg(args, double);
    for (size_t i = 1; i < count; ++i) {
        double v = va_arg(args, double);
        if (v < m) m = v;
    }
    va_end(args);
    return m;
}

double qm_max(size_t count, ...) {
    if (count == 0) return 0.0/0.0;
    va_list args;
    va_start(args, count);
    double m = va_arg(args, double);
    for (size_t i = 1; i < count; ++i) {
        double v = va_arg(args, double);
        if (v > m) m = v;
    }
    va_end(args);
    return m;
}

double qm_sq(double x) {
    return x * x;
}

double qm_sqrt(double x) {
    if (x < 0) {
        return 0.0/0.0;
    }
    /* Newton's method */
    double guess = x > 1.0 ? x : 1.0;
    const double epsilon = 1e-10;
    while (1) {
        double next = 0.5 * (guess + x / guess);
        if (positive(next - guess) < epsilon)
            break;
        guess = next;
    }
    return guess;
}

double qm_cb(double x) {
    return x * x * x;
}

/* Cube root using Newton's method */
double qm_cbrt(double x) {
    if (x == 0.0) return 0.0;
    double guess = x;
    const double epsilon = 1e-10;
    while (1) {
        double next = (2.0 * guess + x / (guess * guess)) / 3.0;
        if (fabs(next - guess) < epsilon) break;
        guess = next;
    }
    return guess;
}

double qm_fabs(double x) {
    return x < 0.0 ? -x : x;
}

double qm_trunc(double x) {
    long long t = (long long)x;
    return (double)t;
}

double qm_floor(double x) {
    double t = trunc(x);
    if (x < 0.0 && t != x) return t - 1.0;
    return t;
}

double qm_ceil(double x) {
    double t = trunc(x);
    if (x > 0.0 && t != x) return t + 1.0;
    return t;
}

long long qm_gcd(size_t count, ...) {
    if (count == 0) return 0;
    va_list args;
    va_start(args, count);
    long long g = va_arg(args, long long);
    if (g < 0) g = -g;
    for (size_t i = 1; i < count; ++i) {
        long long v = va_arg(args, long long);
        if (v < 0) v = -v;
        while (v != 0) {
            long long t = g % v;
            g = v;
            v = t;
        }
    }
    va_end(args);
    return g;
}

long long qm_lcm(size_t count, ...) {
    if (count == 0) return 0;
    va_list args;
    va_start(args, count);
    long long l = va_arg(args, long long);
    if (l < 0) l = -l;
    for (size_t i = 1; i < count; ++i) {
        long long v = va_arg(args, long long);
        if (v < 0) v = -v;
        long long g = gcd(2, l, v);
        if (g == 0) { l = 0; }
        else { l = (l / g) * v; }
    }
    va_end(args);
    return l;
}

double qm_degrees(double radians) {
    return radians * (180.0 / qm_constants.PI);
}

double qm_radians(double degrees) {
    return degrees * (qm_constants.PI / 180.0);
}
