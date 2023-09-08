# [1359. Count All Valid Pickup and Delivery Options](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/?envType=daily-question&envId=2023-09-10)

## Thoughts:
Always feels good to brave through a 'hard' problem. Reminds of Combo problems I solved back then. Never Give up! Never What?  
On a side note. It's so easy to give up and take the easy route. Why start something and only put half your effort? Try your best.
## Solution 1: Combinatorics
You first choose 2 from 2*n to be the first order. Then from remaining you choose 2 to be second order etc. So the total amount of valid sequences is C(2*n, 2)*C(2*n-2, 2)*C(2*n-4, 2)*....*C(2, 2). where C(n, r) = n Choose r.    
Note that my solution just makes general combination and factorial funcitons that may be not the most efficient. You can just simplify these.
```cpp
// OJ: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/?envType=daily-question&envId=2023-09-10
// Author: https://github.com/spookyflame10
// Time: O(N) Because At most we are choosing 2, calculating number of combinations is O(1). So we just loop through to find all.
// Space: O(1). No space.
class Solution {
public:
    int mod = 1e9+7;
    int comb(int n, int r){
        int res =1;
        for(int i=0; i<r; i++){
            res*=(n-i)%mod;
            res%=mod;
        }
        return res/fact(r);
    }
    int fact(int n){
        int res =1;
        for(int i=1; i<=n; i++) res = ((res%mod)*i)%mod;
        return res;
    }
    int countOrders(int n) {
        n*=2; long long res =1;
        while(n>=2){
            res*=comb(n, 2)%mod;
            res%=mod;
            n-=2;
        }
        return res;
    }
};
```
## Solution 1: Math Simplification
C(2*n, 2)*C(2*n-2, 2)*C(2*n-4, 2)*....*C(2, 2) = 2*n(2*n-1)/2 * (2*n-2)(2*n-3)/2 * .... 1 = (2n)!/2^n.  
Or intuitive thinking: 2 order n pairs its: (2n)! ways. and since pairs are overcounted we divide by 2 for each pair = 2^n. 
In this algo. for the ith order, the num ways = 2*i(2*i-1)/2 = i*(2*i-1).
```cpp
// OJ: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/?envType=daily-question&envId=2023-09-10
// Author: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/solutions/516968/java-c-python-easy-and-concise/?envType=daily-question&envId=2023-09-10
// Time: O(n): we calculate n times
// Space: O(1): no space storage.
class Solution {
public:
    int countOrders(int n) {
        long res = 1, mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i)
            res = res * (i * 2 - 1) * i % mod;
        return res;
    }
};
```