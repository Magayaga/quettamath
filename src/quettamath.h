/*
 * QUETTAMATH - MATHEMATICAL LIBRARY FOR THE C PROGRAMMING LANGUAGE
 * COPYRIGHT (c) 2025 CYRIL JOHN MAGAYAGA
 */

#ifndef QUETTAMATH_H
#define QUETTAMATH_H

#include <stddef.h>

// Unary operations
double positive(double x);
double negative(double x);

// Variadic arithmetic:
double add(size_t count, ...);
double subtract(size_t count, ...);
double multiply(size_t count, ...);
double divide(size_t count, ...);

// Variadic extremes
double min(size_t count, ...);
double max(size_t count, ...);

double sq(double x);
double sqrt(double x);
double fabs(double x);
double floor(double x);
double ceil(double x);
double trunc(double x);

#endif // QUETTAMATH_H