#include <bits/stdc++.h>
using namespace std;
const int BUCKET_NUM = 10;

struct ListNode {
    explicit ListNode(int i) : val(i), next(nullptr) {};
    int val;
    ListNode* next;
};

ListNode* insert(ListNode* head, int val) {
    ListNode dummyNode(-1);
    ListNode* newNode = new ListNode(val);
    ListNode* pre = &dummyNode;
    dummyNode.next = head;
    ListNode* cur = head;
    while (cur != nullptr && val > cur->val) {
        pre = cur;
        cur = cur->next;
    }
    pre->next = newNode;
    newNode->next = cur;
    return dummyNode.next;
}

ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode dummy(-1);
    ListNode* node = &dummy;
    while (head1 && head2) {
        if (head1->val < head2->val) {
            node->next = head1;
            head1 = head1->next;
        }
        else {
            node->next = head2;
            head2 = head2->next;
        }
        node = node->next;
    }
    if (head1)
        node->next = head1;
    if (head2)
        node->next = head2;
    return dummy.next;
}

void bucket_sort(int arr [], int len) {
    vector<ListNode*> buckets(BUCKET_NUM, nullptr);
    // 先放入不同的桶内
    for (int i = 0; i < len; i++) {
        int idx = arr[i] / BUCKET_NUM;
        ListNode* head = buckets.at(idx);
        buckets.at(idx) = insert(head, arr[i]);
    }
    // 输出每个桶内的元素
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        ListNode* head = buckets.at(i);
        cout << "bucket " << i << " :";
        while (head)
        {
            cout << head->val << ", ";
            head = head->next;
        }
        cout << endl;
    }
    
    // 桶内的元素进行合并
    ListNode* head = buckets.at(0);
    for (int i = 1; i < BUCKET_NUM; i++) {
        head = merge(head, buckets.at(i));
    }
    for (int i = 0; i < len; i++) {
        arr[i] = head->val;
        head = head->next;
    }
}

int main(int argc, char const* argv []) {

    srand((unsigned)time(NULL));
    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 100;
    }
    bucket_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    


    return 0;
}