//
//  Leetcode20.c
//  DataStruct
//
//  Created by zhangliang on 2019/3/12.
//  Copyright © 2019年 zl. All rights reserved.
//

#include "Leetcode20.h"
int isValid(char* s) {
    if (s == NULL) {
        return 0;
    }
    int end = (int)strlen(s);
    if(end == 0&&s){
        return 1;
    }
    if(end%2){
        return 0;
    }
    end += 1;
    char *ch = malloc(sizeof(char)*end);
    memset(ch, 0, sizeof(char)*end);
    if (!ch) {
        return 0;
    }
    char *temp = s;
    int start = 0;
    int index = 0;
    while(start < end-1){
        switch (temp[start]) {
            case '(':
            case '[':
            case '{':{
                ch[index++] = temp[start++];
            }
                break;
            case ')':
            case ']':
            case '}':{
                int j = -1;
                int k = index - 1;
                for (int i = k;i >= 0; --i) {
                    if ((ch[i] == '('&&temp[start] == ')')||(ch[i] == '['&&temp[start] == ']')||(ch[i] == '{'&&temp[start] == '}')) {
                        j = i;
                        break;
                    }
                }
                if (j >= 0) {
                    for (int i = j; i < index; ++i) {
                        ch[j] = ch[j+1];
                    }
                    ++start;
                    --index;
                }
                else{
                    return 0;
                }
            }
                break;
        }
    }
    
    return strlen(ch)?0:1;
}
