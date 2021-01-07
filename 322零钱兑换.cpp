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
    int coinChange(vector<int>& coins, int amount) {
        return coinChange(0, coins, amount);
    }
};

 
int main(void)
{
    vector<int> characters;
 
//   characters.assign(7, 'a');
	characters.push_back(1);
	characters.push_back(1);
	characters.push_back(1);
	characters.push_back(1);
	characters.push_back(1);
	
	cout << ".size() = " << characters.size() << endl;
	cout << ".capacity() = " << characters.capacity() << endl;
	cout << ".max_size() = " << characters.max_size() << endl;
	
	
 
#if 0
    for (auto c : characters) {
        cout << c << ' ';
    } 
 
    characters.assign({'\n', 'C', '+', '+', '1', '1', '\n'});
 
    for (auto c : characters) {
        std::cout << c;
    }
	
	cout << "characters[3] = " << characters[3] << endl;
	
	cout << "data1 = " << static_cast<void *> (characters.data()) << endl;
	
	// 中间可以有很多代码
	characters.resize(50);
	cout << "data2 = " << static_cast<void *> (characters.data()) << endl;
#endif
	system("pause");
	return 0;
}