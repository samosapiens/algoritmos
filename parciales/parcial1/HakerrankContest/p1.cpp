#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    bool is_all;
    int n, k, i, minutes_left, total;
    
    // read input
    cin >> n >> k;

    // Time for contest
    minutes_left = 4.0*60.0 - k;
    
    // Estimate number of problems to solve
    total = 0;
    is_all = true;
    for(i=0; i<n; i++) {
        total += 5*(i+1);
        if(total > minutes_left) {
            is_all = false;
            break;
        }
    }

    // Can do all?
    if(is_all) printf("%d\n", n);
    else printf("%d\n", i);

    return 0;
}