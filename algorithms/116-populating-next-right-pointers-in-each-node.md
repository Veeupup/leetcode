[TOC]

# Problem

[116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)



# Solution

## 思路和分析

1. 层序遍历

由于是按照每层的从左到右的顺序，所以采用层序遍历来进行操作。

在每层的时候，首先计算出当前层的节点数目，然后进行递归增加 next 指针操作。

2. 采用现成的 next 指针

在一棵树中，存在两种类型的 next 指针：

1. 同一个父节点的两个子节点，可以直接进行赋值

```c++
node->left->next = node->right;
```

2. 不同父节点的右子节点和下一个父节点的左子节点

```c++
node->right->next = node->next->left;
```

如果每个节点有指向父节点的指针，可以通过该指针找到 next 节点。如果不存在该指针，则按照下面思路建立连接：

第 N 层节点之间建立 next 指针后，再建立第N+1 层节点的 next 指针。可以通过 next 指针访问同一层的所有节点，因此可以使用第 N 层的 next 指针，为第 N+1 层节点建立 next 指针。

算法:

从根节点开始，由于第 0 层只有一个节点，所以不需要连接，直接为第 1 层节点建立 next 指针即可。该算法中需要注意的一点是，当我们为第 N 层节点建立 next 指针时，处于第 N-1 层。当第 N 层节点的 next 指针全部建立完成后，移至第 N 层，建立第 N+1 层节点的 next 指针。

遍历某一层的节点时，这层节点的 next 指针已经建立。因此我们只需要知道这一层的最左节点，就可以按照链表方式遍历，不需要使用队列。

## code

1. 层序遍历

```c++
Node* connect(Node* root) {
    if(root == nullptr)
        return root;

    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty())
    {
        int size = Q.size();
        for (int i = 0; i < size; i++)
        {
            Node* node = Q.front();
            Q.pop();

            if (i < size - 1)
                node->next = Q.front();

            if (node->left != nullptr)
                Q.push(node->left);
            if (node->right != nullptr)
                Q.push(node->right);
        }
    }

    return root;
}
```

2. 利用 next 指针

```c++
Node* connect2(Node* root) {
    if (root == nullptr)
        return root;
    Node* leftmost = root;
    while (leftmost->left != nullptr)
    {
        Node* head = leftmost;

        while (head != nullptr)
        {
            head->left->next = head->right;

            if (head->next != nullptr) 
                head->right->next = head->next->left;

            head = head->next;
        }
        leftmost = leftmost->left;
    }
    return root;
}
```

