class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int en = n-1;

        while(st < en){
            int mid = st + (en - st)/2;
            bool isOdd = (en - mid) % 2 != 0 ? 1 : 0;
            
            if(nums[mid] == nums[mid+1]){
                if(isOdd) en = mid - 1;
                else st = mid + 2;
            }
            else{
                if(isOdd) st = mid + 1;
                else en = mid;
            }
        }

        return nums[en];
    }
};