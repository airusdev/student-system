#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int power(int base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}

int main() {
    int passed = 0;
    int failed = 0;

    // fibonacci tests
    printf("fibonacci:\n");
    if (fibonacci(0) == 0)  { printf("\033[1;32m  PASS\033[0m fibonacci(0)\n"); passed++; }
    else                    { printf("\033[1;31m  FAIL\033[0m fibonacci(0) expected 0, got %d\n", fibonacci(0)); failed++; }
    if (fibonacci(1) == 1)  { printf("\033[1;32m  PASS\033[0m fibonacci(1)\n"); passed++; }
    else                    { printf("\033[1;31m  FAIL\033[0m fibonacci(1) expected 1, got %d\n", fibonacci(1)); failed++; }
    if (fibonacci(7) == 13) { printf("\033[1;32m  PASS\033[0m fibonacci(7)\n"); passed++; }
    else                    { printf("\033[1;31m  FAIL\033[0m fibonacci(7) expected 13, got %d\n", fibonacci(7)); failed++; }
    if (fibonacci(12) == 144) { printf("\033[1;32m  PASS\033[0m fibonacci(12)\n"); passed++; }
    else                      { printf("\033[1;31m  FAIL\033[0m fibonacci(12) expected 144, got %d\n", fibonacci(12)); failed++; }

    // factorial tests
    printf("\nfactorial:\n");
    if (factorial(0) == 1)   { printf("\033[1;32m  PASS\033[0m factorial(0)\n"); passed++; }
    else                     { printf("\033[1;31m  FAIL\033[0m factorial(0) expected 1, got %d\n", factorial(0)); failed++; }
    if (factorial(1) == 1)   { printf("\033[1;32m  PASS\033[0m factorial(1)\n"); passed++; }
    else                     { printf("\033[1;31m  FAIL\033[0m factorial(1) expected 1, got %d\n", factorial(1)); failed++; }
    if (factorial(5) == 120) { printf("\033[1;32m  PASS\033[0m factorial(5)\n"); passed++; }
    else                     { printf("\033[1;31m  FAIL\033[0m factorial(5) expected 120, got %d\n", factorial(5)); failed++; }
    if (factorial(10) == 3628800) { printf("\033[1;32m  PASS\033[0m factorial(10)\n"); passed++; }
    else                          { printf("\033[1;31m  FAIL\033[0m factorial(10) expected 3628800, got %d\n", factorial(10)); failed++; }

    // power tests
    printf("\npower:\n");
    if (power(2, 0) == 1)    { printf("\033[1;32m  PASS\033[0m power(2,0)\n"); passed++; }
    else                     { printf("\033[1;31m  FAIL\033[0m power(2,0) expected 1, got %d\n", power(2,0)); failed++; }
    if (power(2, 8) == 256)  { printf("\033[1;32m  PASS\033[0m power(2,8)\n"); passed++; }
    else                     { printf("\033[1;31m  FAIL\033[0m power(2,8) expected 256, got %d\n", power(2,8)); failed++; }
    if (power(3, 4) == 81)   { printf("\033[1;32m  PASS\033[0m power(3,4)\n"); passed++; }
    else                     { printf("\033[1;31m  FAIL\033[0m power(3,4) expected 81, got %d\n", power(3,4)); failed++; }
    if (power(5, 5) == 3125) { printf("\033[1;32m  PASS\033[0m power(5,5)\n"); passed++; }
    else                     { printf("\033[1;31m  FAIL\033[0m power(5,5) expected 3125, got %d\n", power(5,5)); failed++; }
    if (power(10, 3) == 1000) { printf("\033[1;32m  PASS\033[0m power(10,3)\n"); passed++; }
    else                      { printf("\033[1;31m  FAIL\033[0m power(10,3) expected 1000, got %d\n", power(10,3)); failed++; }

    printf("\n=========================\n");
    printf("\033[1;32mPassed: %d\033[0m  \033[1;31mFailed: %d\033[0m\n", passed, failed);
    return 0;
}