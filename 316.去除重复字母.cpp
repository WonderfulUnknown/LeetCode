/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start

class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<char> v;
		v.push_back(s[0]);
		for (int i = 1; i < s.size(); i++)
		{
			if (find(v.begin(), v.end(), s[i]) != v.end())
				continue;
			if (s[i] > v.back())
				v.push_back(s[i]);
			else if (s[i] < v.back())
			{
				while (!v.empty() && s[i] < v.back())
				{
					if (s.find(v.back(), i) != string::npos)
						v.pop_back();
					else
						break;
				}
				v.push_back(s[i]);
			}
		}
		string res;
		while (!v.empty())
		{
			res += v.back();
			v.pop_back();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
// @lc code=end

