/*
link: https://leetcode.com/problems/powx-n/
TC: O(log n)
SC: O(1)
Method: Every time exponent is even then divide it by 2 and multiply the base by itself. If the exponent is odd then multiply the base 
to the final answer and reduce the exponent by 1. 
*/ 
 
 
 double myPow(double x, int n) {
        double ans=1.0;
        long long nn = n;
        if(nn<0) nn *= (-1);
        while(nn){
            if(nn%2){
                ans *= x;
                nn--;
            }else{
                x *= x;
                nn /= 2;
            }
        }
        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
    }