/*
 * QUETTAMATH - MATHEMATICAL LIBRARY FOR THE C PROGRAMMING LANGUAGE
 * COPYRIGHT (c) 2025 CYRIL JOHN MAGAYAGA
 */

#ifndef QUETTAMATH_H
#define QUETTAMATH_H

#include <stddef.h>

// Unary operations
double qm_positive(double x);
double qm_negative(double x);

// Variadic arithmetic:
double qm_add(size_t count, ...);
double qm_subtract(size_t count, ...);
double qm_multiply(size_t count, ...);
double qm_divide(size_t count, ...);

// Variadic extremes
double qm_min(size_t count, ...);
double qm_max(size_t count, ...);

double qm_sq(double x);
double qm_sqrt(double x);
double qm_fabs(double x);
double qm_floor(double x);
double qm_ceil(double x);
double qm_trunc(double x);

#endif // QUETTAMATH_H