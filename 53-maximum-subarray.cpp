class Solution {
public:
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    int maxSubArray(vector<int>& nums) {
        //if (!nums.size()) return 0;
        int best_running_sum = nums[0];
        int running_sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            // running sum is negative and this incoming number is better: 
            // throw away everything so far
            // running sum must be negative for us to want to throw away.
            // if running_sum is positive, then it's better to add
            
            /*
            if (nums[i] > running_sum && running_sum < 0) {
                running_sum = nums[i];
            }   
            else {
                running_sum += nums[i];
            }
            */
            
            // i just realised we can write the above like this
            // this is called Kadane's algorithm
            running_sum = max(nums[i], running_sum + nums[i]);
            best_running_sum = max(best_running_sum, running_sum);
        }
        return best_running_sum;
    }
};
