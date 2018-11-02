Fibonacci(y) {
    if (y <= 0) return 0;
    if (y <= 2) return 1;
    if (y in fibonacci_cache) {
        return fibonacci_cache[y];
    }
    int f, b, a;
    b = y / 2; // integer division
    a = y - b;
    f = (Fibonacci(a) * Fibonacci(b + 1) + Fibonacci(a - 1) * Fibonacci(b)) % MOD;
    fibonacci_cache[y] = f;
    return f;
}
