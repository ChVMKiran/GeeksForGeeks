class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        unordered_map<int,int>ump;
        int n=arr.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==target)return{1,i+1};
            if(ump.find(sum-target)!=ump.end()){
                return {ump[sum-target]+1,i+1};
            }
            ump[sum]=i+1;
        }
        return {-1};
    }
};
