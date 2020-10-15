class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while (k>0)
        {
            nums.insert(nums.begin(),nums.back());
            nums.pop_back();
            k--;
        }
    }
};
