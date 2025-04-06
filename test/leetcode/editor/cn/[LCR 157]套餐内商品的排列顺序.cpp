//某店铺将用于组成套餐的商品记作字符串 goods，其中 goods[i] 表示对应商品。请返回该套餐内所含商品的 全部排列方式 。 
//
// 返回结果 无顺序要求，但不能含有重复的元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：goods = "agew"
//输出：["aegw","aewg","agew","agwe","aweg","awge","eagw","eawg","egaw","egwa",
//"ewag","ewga","gaew","gawe","geaw","gewa","gwae","gwea","waeg","wage","weag","wega",
//"wgae","wgea"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= goods.length <= 8 
// 
//
// 
//
// Related Topics 字符串 回溯 👍 730 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<string> ans;

    vector<char> path;
    vector<bool> vis;


    string pathToString(){
        string res;
        for(auto c:path){
            res += c;
        }
        return res;
    }

    void dfs(string &goods){
        if(path.size() == goods.size()){
            ans.push_back(pathToString());
            return;
        }
        for (int i = 0; i < goods.size(); i += 1) {
            if(vis[i]) continue;
            if(i > 0 && goods[i] == goods[i - 1] && !vis[i - 1]) continue;
            vis[i] = true;
            path.push_back(goods[i]);
            dfs(goods);
            path.pop_back();
            vis[i] = false;
        }
    }


    vector<string> goodsOrder(string goods) {
        int n = goods.size();
        vis.resize(n, false);
        sort(goods.begin(), goods.end());
        dfs(goods);

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
