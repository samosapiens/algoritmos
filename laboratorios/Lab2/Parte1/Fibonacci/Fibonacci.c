#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

const double PHI1 = (1.0 + sqrt(5.0))/2.0;
const double PHI2 = (1.0 - sqrt(5.0))/2.0;

unsigned long long fiboLinear(int n) {
    int i;
    unsigned long long fibo0, fibo1, fibo;
    if(n == 0) 			
        return 0;
    else if(n == 1) 	
        return 1;
    fibo = 0;
    fibo0 = 0; 
    fibo1 = 1; 
    for(i=1; i<n; i++) {
        fibo = fibo0 + fibo1; 
        fibo0 = fibo1; 
        fibo1 = fibo;
    }
    return fibo;
}

unsigned long long fiboRecursive(int n) {
    if(n<2) return (unsigned long long) n;
    else  	return fiboRecursive(n-1) + fiboRecursive(n-2);
        
}

unsigned long long fiboAnalythic(int n) {
    return (unsigned long long) ((unsigned long long) (pow(PHI1, n) - pow(PHI2, n))/sqrt(5.0));
}

void testChar() {
    int n=0;
    time_t t0, t1;
    unsigned long long fibo=0;
    // Test lineal:
    t0 = clock();
    while(fibo < pow(2, 8*sizeof(char)-1))
        fibo = fiboLinear(n++);
    t1 = clock();
    printf("- Overflow Char Fibonacci: (N=%d, t=%f ns, avg=%lf ns)\n", n-1, (float) (t1 - t0)/CLOCKS_PER_SEC, (t1 - t0)/((double) n));
}

void testUnsignedChar() {
    int n=0;
    time_t t0, t1;
    unsigned long long fibo=0;
    // Test lineal:
    t0 = clock();
    while(fibo < pow(2, 8*sizeof(char)))
        fibo = fiboLinear(n++);
    t1 = clock();
    printf("- Overflow Unsigned Char Fibonacci: (N=%d, t=%f ns, avg=%lf ns)\n", n-1, (float) (t1 - t0)/CLOCKS_PER_SEC, (t1 - t0)/(((double) n)*CLOCKS_PER_SEC));
}

void testShort() {
    int n=0;
    time_t t0, t1;
    unsigned long long fibo=0;
    // Test lineal:
    t0 = clock();
    while(fibo < pow(2, 8*sizeof(short)-1))
        fibo = fiboLinear(n++);
    t1 = clock();
    printf("- Overflow Short Fibonacci: (N=%d, t=%f ns, avg=%lf ns)\n", n-1, (float) (t1 - t0)/CLOCKS_PER_SEC, (t1 - t0)/((double) n));
}

void testUnsignedShort() {
    int n=0;
    time_t t0, t1;
    unsigned long long fibo=0;
    // Test lineal:
    t0 = clock();
    while(fibo < pow(2, 8*sizeof(short)))
        fibo = fiboLinear(n++);
    t1 = clock();
    printf("- Overflow Unsigned Short Fibonacci: (N=%d, t=%f ns, avg=%lf ns)\n", n-1, (float) (t1 - t0)/CLOCKS_PER_SEC, (t1 - t0)/((double) n));
}

void testInt() {
    int n=0;
    time_t t0, t1;
    unsigned long long fibo=0;
    // Test lineal:
    t0 = clock();
    while(fibo < pow(2, 8*sizeof(int)-1))
        fibo = fiboLinear(n++);
    t1 = clock();
    printf("- Overflow Integer Fibonacci: (N=%d, t=%f ns, avg=%lf ns)\n", n-1, (float) (t1 - t0)/CLOCKS_PER_SEC, (t1 - t0)/((double) n));
}

void testUnsignedInt() {
    int n=0;
    time_t t0, t1;
    unsigned long long fibo=0;
    // Test lineal:
    t0 = clock();
    while(fibo < pow(2, 8*sizeof(int)))
        fibo = fiboLinear(n++);
    t1 = clock();
    printf("- Overflow Unsigned Integer Fibonacci: (N=%d, t=%f ns, avg=%lf ns)\n", n-1, (float) (t1 - t0)/CLOCKS_PER_SEC, (t1 - t0)/((double) n));
}

void testLong() {
    int n=0;
    time_t t0, t1;
    unsigned long long fibo=0;
    // Test lineal:
    t0 = clock();
    while(fibo < pow(2, 8*sizeof(long)-1))
        fibo = fiboLinear(n++);
    t1 = clock();
    printf("- Overflow Long Fibonacci: (N=%d, t=%f ns, avg=%lf ns)\n", n-1, (float) (t1 - t0)/CLOCKS_PER_SEC, (t1 - t0)/((double) n));
}

void testUnsignedLong() {
    int n=0;
    time_t t0, t1;
    unsigned long long fibo=0, fibo0=0;
    // Test lineal:
    t0 = clock();
    while(fibo < pow(2, 8*sizeof(long)) && fibo >= fibo0) {
        fibo0 = fibo;
        fibo = fiboLinear(n++);
    }
    t1 = clock();
    printf("- Overflow Unsigned Long Fibonacci: (N=%d, t=%f ns, avg=%lf ns)\n", n-1, (float) (t1 - t0)/CLOCKS_PER_SEC, (t1 - t0)/((double) n));
}

int main() {
    // Test Char
    testChar();
    // Test Unsigned Char
    testUnsignedChar();
    // Test Short
    testShort();
    // Test Unsigned Short
    testUnsignedShort();
    // Test int
    testInt();
    // Test unsigned int
    testUnsignedInt();
    // Test long
    testLong();
    // Test unsigned long
    testUnsignedLong();
}
