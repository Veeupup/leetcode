#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * 逆序的数字代表链表
     * 1. 暴力法
     *      先变成数字，再生成链表
     *      直接超标了，不能这么做
     * 2. 从末尾开始合并节点
     *      计算两个末尾的和，如果有进位保存进位，直到一方计算完毕，另外的全部把节点复制到头部
     *
     * @param  {ListNode*} l1 :
     * @param  {ListNode*} l2 :
     * @return {ListNode*}    :
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode;
        ListNode* head = res;
        int flag = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + flag; // flag 是进位
            flag = sum >= 10 ? 1 : 0;
            sum %= 10;
            head->next = new ListNode(sum);
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            int sum = l1->val + flag;
            flag = sum >= 10 ? 1 : 0;
            sum %= 10;
            head->next = new ListNode(sum);
            head = head->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            int sum = l2->val + flag;
            flag = sum >= 10 ? 1 : 0;
            sum %= 10;
            head->next = new ListNode(sum);
            head = head->next;
            l2 = l2->next;
        }
        if (flag)
            head->next = new ListNode(1);
        return res->next;
    }

    
    /**
     * 暴力法，范围超过了
     * @param  {ListNode*} l1 : 
     * @param  {ListNode*} l2 : 
     * @return {ListNode*}    : 
     */
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        using ll = long long;
        ll x = getNumber(l1);
        ll y = getNumber(l2);
        ll sum = x + y;
        if (sum == 0)
            return new ListNode;
        ListNode* res = new ListNode;
        ListNode* head = res;
        while (sum)
        {
            res->next = new ListNode(sum % 10);
            sum /= 10;
            res = res->next;
        }
        return head->next;
    }

    long long getNumber(ListNode* l) {
        if (l == nullptr)
            return 0;
        ListNode* l1 = l;
        long long res = 0, layer = 0;
        while (l1 != nullptr) {
            res += l1->val * int(pow(10, layer++));
            l1 = l1->next;
        }
        return res;
    }
};

int main(int argc, char const* argv []) {
    
    

    return 0;
}