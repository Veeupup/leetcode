#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 需要逐步处理字符串
     * 
     * 需要一直保存当前的合法目录，然后逐步向后整合，如果遇到 . 或者 .. 就可能需要回退，
     * 所以最好用一个辅助栈来保存上一级目录
     * 
     * @param  {string} path : 
     * @return {string}      : 
     */
    string simplifyPath(string path) {
        // trim
        path.erase(0, path.find_first_not_of(" "));
        path.erase(path.find_last_not_of(" ") + 1);
                
        // 状态信息
        string cur_dir;
        stack<string> dirs;
        for (int i = 0, len = path.size(); i < len; i++) {
            // 第一个 /
            while (i < len && path[i] == '/') 
                i++;
            // 找到下一个分隔符或者最后的位置
            int k = i;
            while (k < len && path[k] != '/')
                k++;
            string tmp = path.substr(i, k - i);
            // 特殊处理当前目录和上级目录
            if (tmp == ".") {
                // 不做特殊处理，直接忽略当前的目录处理
            }else if (tmp == "..") {
                if (!dirs.empty()) {
                    string top_dir = dirs.top();
                    dirs.pop();
                    cur_dir.erase(cur_dir.size() - top_dir.size() - 1);
                }
            }else if (tmp != "") {
                cur_dir += '/';
                cur_dir += tmp;
                dirs.push(tmp); // 当前目录入栈
            }
            i = k;    
        }
        return cur_dir == "" ? "/" : cur_dir;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.simplifyPath("/home/") << endl;
    cout << so.simplifyPath("/../") << endl;
    cout << so.simplifyPath("/home//foo/") << endl;
    cout << so.simplifyPath("/a/./b/../../c/") << endl;
    cout << so.simplifyPath("/a//b////c/d//././/..") << endl;
    cout << so.simplifyPath("/a/../../b/../c//.//") << endl;
    
        


    return 0;
}