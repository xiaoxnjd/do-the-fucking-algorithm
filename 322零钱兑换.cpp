/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
你可以认为每种硬币的数量是无限的。

示例 1：
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1

示例 2：
输入：coins = [2], amount = 3
输出：-1

示例 3：
输入：coins = [1], amount = 0
输出：0

示例 4：
输入：coins = [1], amount = 1
输出：1

示例 5：
输入：coins = [1], amount = 2
输出：2
 
提示：
1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

*/

#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;
 
class Solution{
    int coinChange(int idxCoin, vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (idxCoin < coins.size() && amount > 0) {
            int maxVal = amount / coins[idxCoin];
            int minCost = INT_MAX;
            for (int x = 0; x <= maxVal; x++) {
                if (amount >= x * coins[idxCoin]) {
                    int res = coinChange(idxCoin + 1, coins, amount - x * coins[idxCoin]);
                    if (res != -1) minCost = min(minCost, res + x);
                }
            }
            return minCost == INT_MAX ? -1: minCost;
        }
        return -1;
    }
public:
	vector<int>coinRecord;
    int coinChange(vector<int>& coins, int amount) {
        return coinChange(0, coins, amount);
    }
	int coinChange2(vector<int>& coins, int amount) 
	{
		int minCost = INT_MAX;
		int res = 0;
		if(amount<0)
		{
			return -1;
		}
		else if(amount == 0)
		{
			return 0;
		}
		else
		{
			for (int i = 0; i < coins.size(); i++)
			{
				//cout << "coins["<< i<<"]=" << coins[i] << " amount="<< amount << endl;
				if((amount>= coins[i])&&(coinRecord[amount - coins[i]]!=0))
				{
					res = coinRecord[amount - coins[i]]+1;
					//cout << "res1="<< res<<" "<<amount<<" "<<coins[i]<< endl;
				}
				else
				{
					res = coinChange2(coins, amount - coins[i]) + 1;
					//cout << "res2="<< res << endl;
				}
				if(res>0)
				{
					minCost = min(res,minCost);
				}
				//cout << "minCost="<< minCost << endl;
			}	
			if(minCost!=INT_MAX)
			{
				coinRecord[amount] = minCost;
				//cout << "coinRecord["<< amount<<"]=" << coinRecord[amount] << endl;
				return minCost;
			}
			else
			{
				return -1;
			}
			
		}
    }
	int coinChange3(vector<int>& coins, int amount) {
		coinRecord.resize(amount+1);
        return coinChange2(coins, amount);
    }
	int coinChange4(vector<int>& coins, int amount) 
	{
		vector<int> min_cnt(amount + 1, amount + 1);
		if(amount < 0) return -1;
		if(amount == 0) return 0;
		if(amount > 0) 
		{
			for(auto i=0;i<min_cnt.size();i++)
			{
				if(i == 0) 
				{
					min_cnt[i] = 0;
					//printf("min_cnt1[%d]:%d\n",i,min_cnt[i]);
					continue;
				}
				for(auto j=0;j<coins.size();j++)
				{
					if(i>=coins[j])
					{
						min_cnt[i] = min(min_cnt[i],min_cnt[i-coins[j]]+1);
					}
				}
				//printf("min_cnt2[%d]:%d\n",i,min_cnt[i]);
			}
		}
		return min_cnt[amount];
	}
};

 
int main(void)
{
    vector<int> coins = {5,3,1};
	Solution test;
	cout << "coinCnt = " << test.coinChange(coins,143) << endl;
	cout << "coinCnt2 = " << test.coinChange3(coins,143) << endl;
	cout << "coinCnt3 = " << test.coinChange4(coins,143) << endl;
	return 0;
}