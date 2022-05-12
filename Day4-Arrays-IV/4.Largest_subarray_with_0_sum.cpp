/*
link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1# 
TC: O(n)
SC: O(n)
Method: start traversing the array and add the element to the sum one by one then if(sum==0) update answer to i+1, else if sum is there
in the hash table then update answer to i-m[sum] else hash the sum with index in the hash table.
*/
    
    
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<long long,int> m;
        int ans=0;
        long long sum=0;
        
        for(int i=0; i<n; i++){
            sum += A[i];
            if(sum==0) ans = max(ans,i+1);
            else if(m.find(sum) != m.end()) ans=max(ans, i-m[sum]);
            else m[sum]=i;
        }
        
        return ans;
    }