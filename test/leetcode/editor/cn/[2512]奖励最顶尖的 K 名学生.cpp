//给你两个字符串数组 positive_feedback 和 negative_feedback ，分别包含表示正面的和负面的词汇。不会 有单词同时是正面的和
//负面的。 
//
// 一开始，每位学生分数为 0 。每个正面的单词会给学生的分数 加 3 分，每个负面的词会给学生的分数 减 1 分。 
//
// 给你 n 个学生的评语，用一个下标从 0 开始的字符串数组 report 和一个下标从 0 开始的整数数组 student_id 表示，其中 
//student_id[i] 表示这名学生的 ID ，这名学生的评语是 report[i] 。每名学生的 ID 互不相同。 
//
// 给你一个整数 k ，请你返回按照得分 从高到低 最顶尖的 k 名学生。如果有多名学生分数相同，ID 越小排名越前。 
//
// 
//
// 示例 1： 
//
// 输入：positive_feedback = ["smart","brilliant","studious"], negative_feedback = 
//["not"], report = ["this student is studious","the student is smart"], student_
//id = [1,2], k = 2
//输出：[1,2]
//解释：
//两名学生都有 1 个正面词汇，都得到 3 分，学生 1 的 ID 更小所以排名更前。
// 
//
// 示例 2： 
//
// 输入：positive_feedback = ["smart","brilliant","studious"], negative_feedback = 
//["not"], report = ["this student is not studious","the student is smart"], 
//student_id = [1,2], k = 2
//输出：[2,1]
//解释：
//- ID 为 1 的学生有 1 个正面词汇和 1 个负面词汇，所以得分为 3-1=2 分。
//- ID 为 2 的学生有 1 个正面词汇，得分为 3 分。
//学生 2 分数更高，所以返回 [2,1] 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= positive_feedback.length, negative_feedback.length <= 10⁴ 
// 1 <= positive_feedback[i].length, negative_feedback[j].length <= 100 
// positive_feedback[i] 和 negative_feedback[j] 都只包含小写英文字母。 
// positive_feedback 和 negative_feedback 中不会有相同单词。 
// n == report.length == student_id.length 
// 1 <= n <= 10⁴ 
// report[i] 只包含小写英文字母和空格 ' ' 。 
// report[i] 中连续单词之间有单个空格隔开。 
// 1 <= report[i].length <= 100 
// 1 <= student_id[i] <= 10⁹ 
// student_id[i] 的值 互不相同 。 
// 1 <= k <= n 
// 
//
// Related Topics 数组 哈希表 字符串 排序 堆（优先队列） 👍 45 👎 0

#include <bits/stdc++.h>

using namespace std;


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    struct student {
        int index, score;

        student() : index(0), score(0) {}

        student(int index, int score) : index(index), score(score) {}
    };

    vector<string> string_split(string s) {
        vector<string> res;
        string tmp = "";
        for (int i = 0; i < s.length(); i += 1) {
            if (s[i] == ' ') {
                if (tmp != "") {
                    res.push_back(tmp);
                    tmp = "";
                }
            } else {
                tmp = tmp + s[i];
            }
        }
        if (tmp != "") {
            res.push_back(tmp);
        }
        return res;
    }

    bool static cmp(student a, student b) {
        if (a.score == b.score) {
            return a.index < b.index;
        }
        return a.score > b.score;
    }

public:
    vector<int>
    topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report,
                vector<int> &student_id, int k) {
        int student_count = report.size();
        map<string, int> mp;
        for (int i = 0; i < positive_feedback.size(); i += 1) {
            mp[positive_feedback[i]] = 3;
        }
        for (int i = 0; i < negative_feedback.size(); i += 1) {
            mp[negative_feedback[i]] = -1;
        }
        student a[student_count];
        vector<int> ans;
        for (int i = 0; i < student_count; i += 1) {
            a[i].index = student_id[i];
            a[i].score = 0;
            string student_report = report[i];
            vector<string> feedbacks = string_split(student_report);
            for (int j = 0; j < feedbacks.size(); j += 1) {
                a[i].score += mp[feedbacks[j]];
            }
        }
        sort(a, a + student_count, cmp);
        for (int i = 0; i < k; i += 1) {
            ans.push_back(a[i].index);
        }

        return ans;


    }
};
//leetcode submit region end(Prohibit modification and deletion)
