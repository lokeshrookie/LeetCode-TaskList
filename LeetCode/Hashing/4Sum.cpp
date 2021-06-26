
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int target2 = target - nums[i] - nums[j];
                int front = j + 1;
                int back = n - 1;
                while (front < back)
                {
                    int twoSum = nums[front] + nums[back];
                    if (twoSum < target2)
                        front++;
                    else if (twoSum > target2)
                        back--;
                    else
                    {
                        //found the quadruplets
                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        res.push_back(quad);
                        //jumping the duplicates
                        while (front < back && nums[front] == quad[2])
                            --front;
                        while (front < back && nums[back] == quad[3])
                            --back;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j])
                    ++j;
            }
            while (i + 1 < n && nums[i + 1] == nums[i])
                ++i;
        }
        return res;
    }
};