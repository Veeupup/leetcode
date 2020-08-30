[TOC]

# Problem

**1185.一周中的第几天**

给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。

输入为三个整数：day、month 和 year，分别表示日、月、年。

您返回的结果必须是这几个值中的一个` {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}`。

示例 1：

```
输入：day = 31, month = 8, year = 2019
输出："Saturday"
```


示例 2：

```
输入：day = 18, month = 7, year = 1999
输出："Sunday"
```


示例 3：

```
输入：day = 15, month = 8, year = 1993
输出："Sunday"
```


提示：

给出的日期一定是在 1971 到 2100 年之间的有效日期。

# Solution

## 分析和思路

思路1：

计算从当前输入的日期和 1970.1.1 相差多少天，根据查表 1970.1.1 是星期四，所以计算出相差多少天后就能马上知道当前日期星期几。

具体计算过程：如果相差年份比较大，先计算 1970 到当前年份相差的年份，每年加上 365 或者 366；然后计算相差的月份，从 1 月一直计算到当前月份；最后计算相差的日期天数

易错点：

* 需要判断出闰年，闰年的整年天数和 2 月天数不同
* 加上最后的天数时候需要 -1，因为 1970.1.1 到 本身相差 0 天



## cpp

```cpp
class Solution {
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
```

执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗：6 MB, 在所有 C++ 提交中击败了68.18%的用户

## Java

Java 可以使用 库函数 来进行日期的计算。

```java
import java.util.Calendar;
class Solution {
        String[] week = new String[]{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    public String dayOfTheWeek(int day, int month, int year) {
        Calendar calendar = Calendar.getInstance();
        calendar.set(Calendar.YEAR, year);
        calendar.set(Calendar.MONTH, month-1);
        calendar.set(Calendar.DAY_OF_MONTH, day);
        return week[calendar.get(Calendar.DAY_OF_WEEK)-1];
    }
}
```









