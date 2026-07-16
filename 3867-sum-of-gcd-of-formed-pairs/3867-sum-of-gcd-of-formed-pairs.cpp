class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), arr(n);
        pref[0] = nums[0];
        arr[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = max(pref[i-1], nums[i]);
            arr[i] = __gcd(pref[i], nums[i]);
        }
        int l = 0, h = n - 1;
        long long sum = 0;
        sort(arr.begin(), arr.end());
        while(l < h) {
            sum += __gcd(arr[l], arr[h]);
            l++; h--;
        }
        cout << sum;
        return sum;
    }
};