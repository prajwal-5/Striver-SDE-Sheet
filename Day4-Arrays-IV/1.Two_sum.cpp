/*
link: https://leetcode.com/problems/two-sum/
TC: O(n)
SC: O(n)
Method: checking for target-nums[i] in unordered_map if not there then insert it with index.
*/ 
 
 
 vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(m[target-nums[i]]){
                ans.push_back(m[target-nums[i]]-1);
                ans.push_back(i);
                break;
            }
            m[nums[i]]=i+1;
        }
        return ans;
    }