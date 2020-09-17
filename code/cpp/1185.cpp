#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string dayOfTheWeek(int day, int month, int year)
    {
        vector<string> week = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        int monthDay[2][12] = {
            {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
        };
        int dayCount = 0;    // 保存距离 1970.1.1 多少天
        int now_year = 1970, now_month = 1, now_day = 1;
        while (now_year < year)
        {
            dayCount += isLeap(now_year++) ? 366 : 365;
        }
        while (now_month < month)
        {
            dayCount += monthDay[isLeap(year) ? 1 : 0][now_month-1];
            now_month++;
        }
        dayCount += day - 1;    // 如果是 1970.1.1 应该是相差 0 天
        dayCount += 3;  // 计算相隔 1970.1.4 多少天，1.4 是星期一
        dayCount %= 7;  
        return week[dayCount];
    }
private:
    bool isLeap(int year) {
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return true;
        return false;
    }
};

int main()
{
    Solution *so = new Solution();
    cout << so->dayOfTheWeek(1, 1, 1970) << endl;
    return 0;
}
