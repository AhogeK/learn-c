//
// Created by ahogek on 9/13/21.
//
#include <stdio.h>
#include <assert.h>

#define ESC_CHAR '\\'
#define IN 1 /* 在单词内 */
#define OUT 0 /* 在单词外 */

void firstInputAndOutput(FILE *pFile) {
//    char c = getchar();
    putchar(fgetc(pFile));
    printf("\n");
}

/**
 * 文件复制
 */
void fileCopy(FILE *pFile) {
    int c;

    while ((c = fgetc(pFile)) != EOF) {
        putchar(c);
    }
    printf("\n");
}

/**
 * 练习 1-6 验证表达式getchar()!=EOF的值是0还是1
 */
void verifyGetchar(FILE *pFile) {
    int value;
    value = (fgetc(pFile) != EOF);
    printf("%d\n", value);
}

/**
 * 练习1-7 编写一个打印EOF值的程序
 */
void printEOF() {
    printf("This is EOF: %d\n", EOF);
}

/**
 * 统计输入的字符数：版本1
 */
void charCount(FILE *pFile) {
    long nc;
    nc = 0;
    while (fgetc(pFile) != EOF)
        ++nc;
    printf("%ld\n", nc);
}

/**
 * 统计输入的字符数：版本2
 */
void charCountV2(FILE *pFile) {
    int nc;
    for (nc = 0; fgetc(pFile) != EOF; ++nc);
    printf("%d\n", nc);
}

/**
 * 统计输入的行数
 */
void rowCount(FILE *pFile) {
    int c, nl;
    nl = 0;
    while ((c = fgetc(pFile)) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}

/**
 * 统计空格，制表符，换行符
 */
void statistic(FILE *pFile) {
    long c, sn, bn, nn;
    sn = 0, bn = 0, nn = 0;
    while ((c = fgetc(pFile)) != EOF) {
        if (c == ' ')
            ++sn;
        if (c == '\b')
            ++bn;
        if (c == '\n')
            ++nn;
    }
    printf("空格数量：%ld\t退格数量：%ld\t换行数量：%ld\n", sn, bn, nn);
}

/**
 * 输入复制到输出
 */
void copyOutput(FILE *pFile) {
    int c;
    while ((c = fgetc(pFile)) != EOF) {
        if (c == ' ') {
            putchar(c);
            while ((c = fgetc(pFile)) == ' ');
        }
        if (c == EOF)
            break;
        putchar(c);
    }
    putchar('\n');
}

/**
 * 转译符号转转译字符串
 */
void toEscString(FILE *pFile) {
    int c;
    while ((c = fgetc(pFile)) != EOF) {
        switch (c) {
            case '\t':
                putchar(ESC_CHAR);
                putchar('t');
                break;
            case '\b':
                putchar(ESC_CHAR);
                putchar('b');
                break;
            case ESC_CHAR:
                putchar(ESC_CHAR);
                putchar(ESC_CHAR);
            default:
                putchar(c);
                break;
        }
    }
    putchar('\n');
}

/**
 * 单词计数
 */
void wordCount(FILE *pFile) {
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = fgetc(pFile)) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("行数：%d\t\t单词数：%d\t字符数：%d\n", nl, nw, nc);
}

/**
 * 1.5.4 练习 1-11 单元测试
 */
void unitTest(void) {
    FILE *f;
    unsigned long i;
    static char *al = "abcdefghijklmnopqrstuvwxyz";

    /* 输入一个没有字符的文件 */
    f = fopen("test0", "w");
    assert(f != NULL);
    fclose(f);

    /* 输入一个巨大的单词没有换行的文件 */
    f = fopen("test1", "w");
    assert(f != NULL);
    for (i = 0; i < ((66000ul / 26) + 1); i++)
        fputs(al, f);
    fclose(f);

    /* 输入一个包含大量空行的文件 */
    f = fopen("test2", "w");
    assert(f != NULL);
    for (i = 0; i < 66000; i++)
        fputc('\n', f);
    fclose(f);
}

/**
 * 练习 1-12
 * 编写一个程序，以每行一个单词的形式打印其输出
 */
void exercise_1_12(FILE *pFile) {
    int c, state;
    state = IN;
    while ((c = fgetc(pFile)) != EOF) {
        if (c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            putchar('\n');
            putchar(c);
        } else
            putchar(c);
    }
}

int main() {
    FILE *fptr;
    fptr = (fopen("../test.txt", "r"));
    if (fptr) {
        firstInputAndOutput(fptr);
        rewind(fptr);
        fileCopy(fptr);
        rewind(fptr);
        verifyGetchar(fptr);
        printEOF();
        rewind(fptr);
        charCount(fptr);
        rewind(fptr);
        charCountV2(fptr);
        rewind(fptr);
        rowCount(fptr);
        rewind(fptr);
        statistic(fptr);
        rewind(fptr);
        copyOutput(fptr);
        rewind(fptr);
        toEscString(fptr);
        rewind(fptr);
        wordCount(fptr);
        unitTest();
        rewind(fptr);
        exercise_1_12(fptr);
        fclose(fptr);
    }
}