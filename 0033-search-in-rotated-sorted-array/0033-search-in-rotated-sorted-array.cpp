class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s =0;
        int e = nums.size()-1;
        while (s < e) {
            int mid = s + (e - s) / 2;

     
            if (nums[mid] > nums[e]) {
                s = mid + 1; 
            } else {
                e = mid;
            }
        }
        int pivot = s;
        s = 0;
        e = nums.size() - 1;

        
        if (target >= nums[pivot] && target <= nums[e]) {
            s = pivot; 
        } else {
            e = pivot - 1; 
        }

       
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                s = mid + 1; 
            } else {
                e = mid - 1; 
            }
        }

        return -1;
        
    }
};