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
        int nextUniqIdx=currIdx+1;
        while(nextUniqIdx<n&&candidates[currIdx]==candidates[nextUniqIdx]){
            nextUniqIdx++;
        }
        findAllCombinationSum(nextUniqIdx,currCombination,currSum,candidates,target);
        //pick element at curr Idx
        currCombination.push_back(candidates[currIdx]);
        findAllCombinationSum(currIdx+1,currCombination,currSum+candidates[currIdx],candidates,target);
        currCombination.pop_back();
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