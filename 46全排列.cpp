/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

链接：https://leetcode-cn.com/problems/permutations
*/
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;
class Solution {
public:
	vector<int> temp_nums;
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
			for (const auto &c : output) cout << c << " ";
			cout<<endl;
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
	void backtrackOfMy(vector<vector<int>>& res, vector<int>& input, int len){
		int temp_erase_num = 0;
		cout << "input:";
		for (const auto &c : input) cout << c << " ";
			cout<<endl;
		if(len==0){
			for (const auto &c : temp_nums) cout << c << " ";
			cout<<endl;
			res.emplace_back(temp_nums);
		}
		for (int i = 0; i < len; ++i) {
			temp_nums.emplace_back(input[i]);
			temp_erase_num = input[i];
			input.erase(input.begin()+i);
			backtrackOfMy(res, input, input.size());
			input.insert(input.begin()+i,temp_erase_num);
			temp_nums.pop_back();
		}
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        //backtrack(res, nums, 0, (int)nums.size());
		backtrackOfMy(res, nums, (int)nums.size());
        return res;
    }
};
int main(void)
{
    vector<int> coins = {1,2,3};
	Solution test;
	test.permute(coins);

	return 0;
}