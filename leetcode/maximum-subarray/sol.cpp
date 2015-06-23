#include <vector>
#include <cstdio>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;
        int sz = nums.size();
        int sum = nums[0] , least_sum = min(0,nums[0]),ret = nums[0];
        for(int i=1;i<sz;i++){
            sum+=nums[i];
            ret = max( ret , sum - least_sum);
            least_sum = min( sum , least_sum );
        }
        return ret;
    }
};

