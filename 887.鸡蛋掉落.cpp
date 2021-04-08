/*给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。

已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都会碎，从 f 楼层或比它低的楼层落下的鸡蛋都不会破。

每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <= n）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 重复使用 这枚鸡蛋。

请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？

 
示例 1：

输入：k = 1, n = 2
输出：2
解释：
鸡蛋从 1 楼掉落。如果它碎了，肯定能得出 f = 0 。 
否则，鸡蛋从 2 楼掉落。如果它碎了，肯定能得出 f = 1 。 
如果它没碎，那么肯定能得出 f = 2 。 
因此，在最坏的情况下我们需要移动 2 次以确定 f 是多少。 
示例 2：

输入：k = 2, n = 6
输出：3
示例 3：

输入：k = 3, n = 14
输出：4
 

提示：

1 <= k <= 100
1 <= n <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/super-egg-drop
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。\
妄想用推理出来的公式 y=sqrt(x)+x递归。实际上不行。是不是还可以考虑y= log(x)+x的的递归，两者取最优解。
*/
#include "math.h"
#include <iostream>
#include <unordered_map>

using namespace std; 

class Solution {
public:
	unordered_map<int, int> memo;
    int superEggDrop(int k, int n) {
		int add = 0;
		float interval = n;
		float last_interval = n;
		//cout << sqrt(100) << " " <<   sqrt(10) << " " <<   sqrt(sqrt(10)) << endl;
		for(int i=k;i>0;i--)
		{
			if(i == 1)
			{
				add+=interval-1;
				break;
			}
			else
			{

				interval=(int)(sqrt(last_interval));
				cout<<"interval="<<interval<<endl;
				if(interval<2)
				{
					add += 1;
					break;
				}
				add += (int)(last_interval/interval);
				cout<<"add="<<add<<endl;
				last_interval = interval;
			}
		}
		return(add);
    }
	//我肤浅了，动态规划之所以为动态，是因为在变量的情况下遍历，找出最优解
	//纯数学方法是解不出来的，上面的“y= log(x)+x的的递归”思路到是可以离散作为动态规划的二分法条件
	//数学方法应该也是有的，只不过我数学没好到那个程度
	int superEggDrop1(int k, int n) {
		int t1 = 0;
		int t2 = 0;
		int high = n;
		int low = 0;
		if (memo.find(n * 100 + k) == memo.end()){
			if(k == 1){
				return n;
			}
			else if(n == 1){
				return 1;
			}
			else if(n == 0){
				return 0;
			}
			else{
				while(low+1 < high)
				{
					int i = (high+low)/2;
					cout<< "i:" << i <<endl;
					cout<< "k:" << k << " n-i:" << n-i << endl;
					t1 = superEggDrop1(k,n-i);
					cout<< "k-1:" << k-1 << " i-1:" << i-1 << endl;
					t2 = superEggDrop1(k-1,i-1);
					if(t1>t2){
						low = i;
					}
					else if(t1<t2){
						high = i;
					}
					else{
						low = high = i;
					}
				}
				memo[100*n+k] = min(max(superEggDrop1(k,n-low),superEggDrop1(k-1,low-1)),max(superEggDrop1(k,n-high),superEggDrop1(k-1,high-1)))+1;
			}
		}
		else{
			//return memo[100*n+k];
		}
		return memo[100*n+k];
	}
};
int main(void)
{
	Solution test;
	int f = test.superEggDrop1(7,10000);
	cout<<"f="<<f<<endl;
	return 0;
}
