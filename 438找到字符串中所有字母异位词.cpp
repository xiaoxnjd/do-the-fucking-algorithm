/*
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
#include <iostream>
#include <climits>

using namespace std; 

class Solution {
public:
    vector<int> findAnagrams(string s, string t) {
		vector<int> ret;
		int right = 0;
		int left = 0;
		int match = 0;
		unordered_map<char, int> window;
		unordered_map<char, int> needs;
		for(char c : t)needs[c]++;
		while(right<s.size()){
			cout<< "right:" << right << endl;
			//cout << window[s[right]] <<" "<< needs[s[right]] << endl;
			if(needs.count(s[right])){
				window[s[right]]++;
				if(window[s[right]] == needs[s[right]]){
					match++;
					//cout<< "match:" << match << endl;
				}
			}
			if(right<t.size()){
				//do nothing
			}
			else{
				//cout<< "size:" << needs.size() << endl;
				//cout << "left:" << left << endl;
				if(needs.count(s[left])){
						window[s[left]]--;
						if(window[s[left]] < needs[s[left]]){
							match--;
							cout<< "match:" << match << endl;
						}
					}
				left++;
			}
			if(match == needs.size()){
				ret.emplace_back(left);
			}
			right++;
		}
		return ret;
    }
};
int main(void)
{
    vector<int> ret = {0};
	Solution test;
	//ret = test.findAnagrams("cbaebabacd","abc");
	//for(int c : ret)cout << " " << c ;
	//cout << endl; 
	ret = test.findAnagrams("baa","aa");
	for(int c : ret)cout << " " << c ;
	cout << endl; 

	return 0;
}

