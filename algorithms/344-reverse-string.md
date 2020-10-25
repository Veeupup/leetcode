# problem
[344.reverse-string-ii](https://leetcode-cn.com/problems/reverse-string-ii/)

[541, ii](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

[557, iii](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

# solution

## i

space O(1)
 ```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, len = s.size(); i < len / 2; ++i) {
            swap(s[i], s[len - i - 1]);
        }
    }
};
 ```

## ii

```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }
};
```

## iii

```c++
class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        int i = 0;
        while (i < len)
        {
            int start = i;
            while (i < len && s[i] != ' ')
                i++;
            
            int left = start, right = i - 1;
            while (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            
            while (i < len && s[i] == ' ') 
                i++;
        }
        return s;
    }
};


```

