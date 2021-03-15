/*给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。

函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。

你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

 
示例 1：

输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
示例 2：

输入：numbers = [2,3,4], target = 6
输出：[1,3]
示例 3：

输入：numbers = [-1,0], target = -1
输出：[1,2]
 

提示：

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers 按 递增顺序 排列
-1000 <= target <= 1000
仅存在一个有效答案

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
/* 还可以优化的，我自己想多了，直接重两头开始往中间缩，*/
    vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> ret;
		int i=0,j=0;
		while(++j){
			cout<<"["<<i<<"]:"<<numbers[i]<<" ["<<j<<"]:"<<numbers[j]<<endl;
			if(numbers[i]+numbers[j]<target){
				if((j+1 == numbers.size())||(numbers[i]+numbers[j+1]>target)){
					while(++i){
						if(i>=j){
							return(ret);
						}
						else if(numbers[i]+numbers[j] == target){
							ret.emplace_back(i+1);
							ret.emplace_back(j+1);
							return(ret);
						}
						else{
							while(numbers[i]+numbers[j] > target){
								j--;
								if(numbers[i]+numbers[j] == target){
								ret.emplace_back(i+1);
								ret.emplace_back(j+1);
								return(ret);
								}
							}
						}
						
					}
				}
				else if(numbers[i]+numbers[j+1]==target){
					ret.emplace_back(i+1);
					ret.emplace_back(j+2);
					return(ret);
				}
			}
			else if(numbers[i]+numbers[j]>target){
				return(ret);
			}
			else{
				ret.emplace_back(i+1);
				ret.emplace_back(j+1);
				return(ret);
			}
		}
		return(ret);
    }
};
int main(void)
{
    vector<int> numbers = {12,13,23,28,43,44,59,60,61,68,70,86,88,92,124,125,136,168,173,173,180,199,212,221,227,230,277,282,306,314,316,321,325,328,336,337,363,365,368,370,370,371,375,384,387,394,400,404,414,422,422,427,430,435,457,493,506,527,531,538,541,546,568,583,585,587,650,652,677,691,730,737,740,751,755,764,778,783,785,789,794,803,809,815,847,858,863,863,874,887,896,916,920,926,927,930,933,957,981,997};
	vector<int> sum;
	Solution test;
	sum = test.twoSum(numbers,542);
	for (const auto &i : sum) cout << i << " ";
	cout<<endl;
	return 0;
}