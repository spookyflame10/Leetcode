// print the ith primes less than 10^8 such that i mod 100 =1, 
// cool theorem: num primes less than or equal to n is approximately n/(ln n)
#include "bits/stdc++.h"
using namespace std;
int main(){
    vector<bool> sieve(1e8, true);// if sieve[i] = true if is prime
    sieve[0] = sieve[1] = false;
    int count =0;
    for(long long i=2; (long long)i*i<1e8; i++){ //
        if(sieve[i]){ // only do it when prime because prime def is that it has no prime factorization beside 1 and itself. so you take out all prime factors
            for(long long j=i*i; j<1e8; j+=i){
                sieve[j] = false;
            }
        }
    }
    // go through sieve to see if prime
    for(int i=2; i<1e8; i++){
        if(sieve[i]){
            count++;
            if(count%100==1){
                cout<<i<<endl;
                fflush(stdout);
            }
        }
    }
}