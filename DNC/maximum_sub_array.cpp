#include <bits/stdc++.h>
using namespace std;

int maxCrossSum(vector<int>& nums, int l, int m, int r){
    int left_max_sum = INT_MIN;
    int right_max_sum = INT_MIN;
    int left_sum = 0;
    int right_sum = 0;

    for(int i = m; i >= l; i--){
        left_sum += nums[i];
        left_max_sum = max(left_max_sum, left_sum);
    }

    for(int i = m+1; i <= r; i++){
        right_sum += nums[i];
        right_max_sum = max(right_max_sum, right_sum);
    }

    return left_max_sum + right_max_sum;
}

int maxSubArray(vector<int>& nums, int l, int r){
    if(l == r) return nums[l];
    int mid = l + (r-l)/2;

    int left_sum = maxSubArray(nums, l, mid);
    int right_sum = maxSubArray(nums, mid+1, r);

    int cross_sum = maxCrossSum(nums, l, mid, r);
    
    return max(max(left_sum, right_sum), cross_sum);
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums, 0, nums.size()-1) << endl;
    return 0;
}