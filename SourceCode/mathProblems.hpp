//
// Created by 徐琛 on 2019/10/11.
//

#ifndef TEST_MATHPROBLEMS_HPP
#define TEST_MATHPROBLEMS_HPP


#include "math.h"


bool isPrime(int n){
    if(n == 1 || n == 0) return false;
    for(int i = 2; i <= pow(n, 0.5); ++i){
        if(n%i == 0)
            return false;
    }
    return true;
}
int countPrimes(int n) {
    if(n < 2)
        return 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(isPrime(i)) ++cnt;
    }
    return cnt;
}


#endif //TEST_MATHPROBLEMS_HPP
