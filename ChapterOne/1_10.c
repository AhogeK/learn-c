//
// 1.10 外部变量与作用域
// Created by ahogek on 9/25/21.
//

#include <stdio.h>

#define MAXLINE 1000    /* 允许的输入行的最大长度 */
#define TABINC 4

int max;                /* 到目前为止发现的最长行长度 */
char line[MAXLINE];     /* 当前的输入行 */
char longest[MAXLINE];   /* 用于保存最长的行 */

int get_line2(FILE *);

void copy2(void);

/* 打印最长的输入行; 特别版本 */
void external_variable_and_scope(FILE *f) {
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = get_line2(f)) > 0)
        if (len > max) {
            max = len;
            copy2();
        }
    if (max > 0)
        printf("%s", longest);
}

/* get_line: 外部变量版 */
int get_line2(FILE *f) {
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 && (c = fgetc(f)) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: 外部变量版本 */
void copy2() {
    int i;
    extern char line[], longest[];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}

/**
 * 编写程序 detab，将输入中的制表符替换成适当数目的空格,使空格充满到下一个制表符终止位的地方。
 *
 * @param f 文本文件
 */
void exercise_1_20(FILE *f) {
    int nb, pos, c;
    nb = 0;
    pos = 1;

    while ((c = fgetc(f)) != EOF) {
        if (c == '\t') {
            nb = TABINC;

            while (nb > 0) {
                putchar('#');
                ++pos;
                --nb;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }
}

/**
 * 编写程序entab, 将空格串替换为最少数量的制表符和空格，但要保持单词之间的间隔不变。
 *
 * @param f 文本文件
 */
void exercise_1_21(FILE *f) {
    int i, t;
    int spacecount, len;

    while ((len = get_line2(f)) > 0) {
        spacecount = 0;
        for (i = 0; i < len; i++) {
            if (line[i] == ' ')
                spacecount++; /* 每一个空格 + 1 */
            if (line[i] != ' ')
                spacecount = 0; /* 重置数量 */
            /*
             * 如果为true就说明有足够的空格为一个退格
             */
            if (spacecount == TABINC) {
                /*
                 * 因为我们要将4个空格替换为一个退格，因为我们需要回退三个字节并将一个空格替换为退格
                 */
                i -= 3;
                len -= 3;
                line[i] = '\t';
                /*
                 * 现在移动所有的字符向左移动三位，即i后的每一位为该位的+3位
                 */
                for (t = i + 1; t < len; t++)
                    line[t] = line[t + 3];
                /*
                 * 现在重置空格数量为0,并将该行的最后一个字符为\0
                 */
                spacecount = 0;
                line[len] = '\0';
            }
        }
        printf("%s", line);
    }
}

/**
 * 编写一个程序，把较长的输入行"折"成短一些的两行或多行，折行位置在输入行的第n列之前的最后一个非空之后。
 *
 * @param f
 */
void exercise_1_22(FILE *f) {
    int t, len;
    int location, spaceholder;
    const int FOLDLENGTH = 70; /* 每行最长长度，多出换行 */

    while ((len = get_line2(f)) > 0) {
        if (len < FOLDLENGTH) {

        } else {
            /*
             * 如果该行超长，我们就循环替换离 FOLDLENGTH 最近的空格为换行符
             */
            t = 0;
            location = 0;
            spaceholder = 0;
            while (t < len) {
                if (line[t] == ' ' || line[t] == '\t')
                    spaceholder = t;

                if (location == FOLDLENGTH) {
                    if (spaceholder != 0) {
                        line[spaceholder] = '\n';
                        location = 0;
                    }
                }
                location++;
                t++;
            }
        }
        printf("%s", line);
    }
}