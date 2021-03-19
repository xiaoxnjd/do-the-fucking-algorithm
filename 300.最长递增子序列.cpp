/*给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1
 

提示：

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

进阶：

你可以设计时间复杂度为 O(n2) 的解决方案吗？
你能将算法的时间复杂度降低到 O(n log(n)) 吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <iostream>

using namespace std; 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int> max_cnt(nums.size());
		int temp = 1;
		int max_max_cnt = 0;
		for(int i=nums.size()-1;i>=0;i--)
		{
			//cout << "1i:" << i << endl;
			max_cnt[i] = 1;
			//cout << "i:" << i << endl;
			if(i==nums.size()-1)
			{
				//cout << "2i:" << i << endl;
			}
			else
			{
				//cout << "3i:" << i << endl;
				temp = 1;
				for(int j=i+1;j<nums.size();j++)
				{
					if(nums[j]>nums[i])
					{
						if(max_cnt[j]>=1)
						{
							temp = max(temp,max_cnt[j]+1);
						}
					}
				}
				max_cnt[i] = temp;
			}
			max_max_cnt = max(max_max_cnt,max_cnt[i]);
		}
		return max_max_cnt;
    }
};
int main(void)
{
    vector<int> nums = {7,7,7,7,7,7,7};
	Solution test;
	int max_len = test.lengthOfLIS(nums);
	cout << max_len << endl;
	return 0;
}

