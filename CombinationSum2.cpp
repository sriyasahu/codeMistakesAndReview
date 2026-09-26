#include <bits/stdc++.h>
using namespace std;
class Solution {
    void findAllCombinationSum(int currIdx,vector<int> &currCombination,int currSum,
    vector<int> &candidates,int target){
        if(currSum==target){
            allCombination.push_back(currCombination);
            return;
        }
        if(currIdx==n||currSum>target){
            return;
        }
        int idx=currIdx;
        while(idx<n){
            int nextUniqIdx=idx+1;
            while(nextUniqIdx<n&&candidates[idx]==candidates[nextUniqIdx]){
                nextUniqIdx++;
            }
            findAllCombinationSum(nextUniqIdx,currCombination,currSum,candidates,target);
            currCombination.push_back(candidates[idx]);
            findAllCombinationSum(idx+1,currCombination,currSum+candidates[idx],candidates,target);
            currCombination.pop_back();
            idx++;
        }
    }
public:
    vector<vector<int>> allCombination;
    int n;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> currCombination;
        findAllCombinationSum(0,currCombination,0,candidates,target);
        return allCombination;
    }
};