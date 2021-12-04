#include <stdio.h>
#include "ChapterOne/1_4.h"
#include "ChapterOne/1_5.h"

int main() {
    printf("###########################\n");
    printf("########## 第一章 ##########\n");
    printf("###########################\n\n");
    printf("打印摄氏度，华氏对照表: \n");
    symbolConstants();
    printf("-----------------------------------------\n");
    FILE *pFile = fopen("/home/ahogek/CLionProjects/learn-c/test.txt", "r");
    printf("打印文本文件中的内容: \n");
    firstInputAndOutput(pFile);
    printf("-----------------------------------------\n");
    printf("打印文本文件中的全部内容: \n");
    pFile = fopen("/home/ahogek/CLionProjects/learn-c/test.txt", "r");
    fileCopy(pFile);
    printf("-----------------------------------------\n");
    printf("验证表达式getchar()!=EOF的值是0还是1: \n");
    pFile = fopen("/home/ahogek/CLionProjects/learn-c/test.txt", "r");
    verifyGetchar(pFile);
    printf("-----------------------------------------\n");
    printf("打印EOF: \n");
    printEOF();
    printf("-----------------------------------------\n");
    printf("文本文件字符数统计v1: \n");
    pFile = fopen("/home/ahogek/CLionProjects/learn-c/test.txt", "r");
    charCount(pFile);
    printf("-----------------------------------------\n");
    printf("文本文件字符数统计v2: \n");
    pFile = fopen("/home/ahogek/CLionProjects/learn-c/test.txt", "r");
    charCountV2(pFile);
    printf("-----------------------------------------\n");
}