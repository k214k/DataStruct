//
//  Leetcode21.c
//  DataStruct
//
//  Created by zhangliang on 2019/3/12.
//  Copyright © 2019年 zl. All rights reserved.
//

#include "Leetcode21.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    if(l1 == NULL&&l2) return l2;
    if(l1&&l2 == NULL) return l1;
    if(l1 == NULL &&l2 == NULL) return NULL;
    struct ListNode *p = l1;
    struct ListNode *q = l2;
    struct ListNode *header = NULL;
    struct ListNode *point = NULL;
    while(p&&q){
        if (p->val > q->val) {
            if (!header) {
                header = q;
                point = header;
            }
            else{
                point->next = q;
                point = q;
            }
            q = q->next;
        }
        else{
            if (!header) {
                header = p;
                point = header;
            }
            else{
                point->next = p;
                point = p;
            }
            p = p->next;
        }
        
    }
    
    if (p) {
        point->next = p;
    }
    else if (q){
        point->next = q;
    }
    return header;
}
