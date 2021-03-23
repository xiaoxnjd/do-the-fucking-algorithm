/*给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 

提示：

0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/edit-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std; 
class Solution {
public:
	int Distance(string word1,int m, string word2,int n,int **dp)
		{
			if(m == 0)
			{
				return dp[0][n];
			}
			if(n == 0)
			{
				return dp[m][0];
			}
			printf("1-m:%d[%c],n:%d[%c]\r\n",m-1,word1[m-1],n-1,word2[n-1]);
			if(word1[m-1] == word2[n-1])
			{
				printf("2-m:%d,n:%d\r\n",m,n);
				if(dp[m-1][n-1]!=0)
				{
					printf("3-m:%d,n:%d\r\n",m,n);
					dp[m][n] = dp[m-1][n-1];
				}
				else
				{
					printf("4-m:%d,n:%d\r\n",m,n);
					dp[m][n] = Distance(word1,m-1, word2,n-1,dp);
				}
			}
			else
			{
				printf("5-m:%d,n:%d\r\n",m,n);
				//插入,替换,删除
				dp[m][n] = min(min(dp[m][n-1]!=0?dp[m][n-1]:Distance(word1,m, word2,n-1,dp),dp[m-1][n-1]!=0?dp[m-1][n-1]:Distance(word1,m-1, word2,n-1,dp)),dp[m-1][n]!=0?dp[m-1][n]:Distance(word1,m-1, word2,n,dp))+1;
			}
			return dp[m][n];
		}
    int minDistance(string word1, string word2) {
		int m = word1.length();
		int n = word2.length();
		int ret = 0;
		//int dp[m+1][n+1] = {0};
		#if 1
		int **dp=new int *[m+1];//开辟行空间
		for(int i=0;i<m+1;i++)
			dp[i]=new int[n+1];//开辟列空间
		for(int i=1;i<m+1;i++)
		{
			dp[i][0]=i;
		}
		for(int i=1;i<n+1;i++)
		{
			dp[0][i]=i;
		}
		dp[0][0] = 0;
		#endif
		ret = Distance(word1,m,word2,n,dp);
		#if 1
		for(int i=0;i<m+1;i++)
			delete[]dp[i];
		delete []dp;
		#endif
		return ret;
    }
};


int main(void)
{
    string s1 = "horse";
	string s2 = "ros";
	Solution test;
	int max_len = test.minDistance(s1,s2);
	cout << max_len << endl;
	return 0;
}
