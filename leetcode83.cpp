// leetcode83.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;

 
  struct ListNode {//节点的结构体
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p1 = head;
       
        while (p1!=nullptr &&p1-> next!=nullptr) 
        {
            if (p1->next->val == p1->val) 
            {
                p1->next = p1->next->next;
                
           }
            else {
                p1 = p1->next;
            }
        }
        if (head->val = p1->val)head->next = nullptr;
        return head;

    }
};
int main()
{
    ListNode aa;
  
    ListNode* head=&aa;
    head->val = 1;
    head->next->val = 1;
    head->next->next->val = 2;
    Solution a;
    a.deleteDuplicates(head);
    cout << head->val << head->next->val << head->next->next->val;
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
