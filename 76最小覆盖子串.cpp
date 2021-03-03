/*给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成
 

进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
#include <iostream>
#include <climits>

using namespace std; 

class Solution {
public:
	int right = 0;
	int left = 0;
	int match = 0;
	int min_start = 0;
	int min_len = INT_MAX;
	unordered_map<char, int> window;
	unordered_map<char, int> needs;
    string minWindow(string s, string t) {
		for(char c : t)needs[c]++;
		while(right<s.size()){
			cout<< "right:" << right <<" "<< s.size() << endl;
			window[s[right]]++;
			//cout << window[s[right]] <<" "<< needs[s[right]] << endl;
			if(needs.count(s[right])){
				if(window[s[right]] == needs[s[right]]){
					match++;
					cout<< "match:" << match << endl;
				}
			}
			right++;
			//cout<< "size:" << needs.size() << endl;
			while(match == needs.size()){
				cout << "left:" << left << endl;
				if(needs.count(s[left])){
					window[s[left]]--;
					if(window[s[left]] < needs[s[left]]){
						cout<< "right:" << right << " left:" << left<< " min_len:" << min_len << endl;
						if(right - left < min_len){
							min_start = left;
							min_len = right - left;
						}
						match--;
					}
				}
				left++;
			}
		}
		return min_len == INT_MAX ?
                "" : s.substr(min_start, min_len);
    }
};
int main(void)
{
    string min_str;
	Solution test;
	min_str = test.minWindow("ADOBECODEBANC","ABC");
	cout << min_str << endl;
	return 0;
}




