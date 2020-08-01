// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
// 示例：
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

//解法一：添加一个表头，依次判断两个链表值大小，小的值过来，
//到最后可能一个链表全加进来，另一个没变的情况，也得把哪些值都加过了
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (!l1 )
        return l2;
    if (!l2)
        return l1;
    //两个表头，因为p会变化，需要先把它的地址记录下来。
    struct ListNode *p= (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *head= p;
    while(l1 && l2){
        if(l1->val > l2->val){
            p->next = l2;
            l2 = l2->next;
        }
        else{
            p->next = l1;
            l1 = l1->next;
        }
        p = p->next;
    }
    if(l1)
        p->next = l1;
    if(l2)
        p->next = l2;
    return head->next;
}
//解法2 递归
// 可以这么个想：
// 最终的目的就是判断l1链表的值和l2链表值的大小，
//数谁小，那么这个就是 该对应链表指向 其下一个值 与另一个链表的下一个值比较较小的值。 最后返回的是该链表。
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (!l1 )
        return l2;
    if (!l2)
        return l1;
    if(l1->val > l2->val){
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    else
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
}

