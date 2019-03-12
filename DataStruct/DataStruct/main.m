//
//  main.m
//  DataStruct
//
//  Created by zhangliang on 2019/3/12.
//  Copyright © 2019年 zl. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "Leetcode20.h"
#include "Leetcode21.h"
void test21(){
    struct ListNode* header1 = NULL;
    struct ListNode* header2 = NULL;
    struct ListNode *l1 = NULL,*l2 = NULL;
    for (int i = 0; i < 3; ++i) {
        
        struct ListNode* p = malloc(sizeof(struct ListNode));
        struct ListNode* q = malloc(sizeof(struct ListNode));
        if (i == 0) {
            header1 = p;
            header2 = q;
            l1 = header1;
            l2 = header2;
        }
        else{
            l1->next = p;
            l1 = p;
            l2->next = q;
            l2 = q;
        }
        p->val = i+1;
        q->val = i+2;
        p->next = NULL;
        q->next = NULL;
        
    }
    struct ListNode* temp = mergeTwoLists(header1,header2);
}
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
