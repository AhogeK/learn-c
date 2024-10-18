//
// Created by AhogeK on 10/18/24.
//

#include <stdio.h>
#include <ctype.h>

void expand(const char s1[], char s2[])
{
    int i, j;
    char start, end;

    i = j = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0' &&
            ((isalpha(s1[i - 1]) && isalpha(s1[i + 1]) && s1[i - 1] <= s1[i + 1]) ||
                (isdigit(s1[i - 1]) && isdigit(s1[i + 1]) && s1[i - 1] <= s1[i + 1])))
        {
            start = s1[i - 1] + 1;
            end = s1[i + 1];
            while (start <= end)
                s2[j++] = start++;
            i++;
        }
        else
            s2[j++] = s1[i];
        i++;
    }
    s2[j] = '\0';
}

int main()
{
    char s1[] = "-=a-z0-9=-";
    char s2[100];

    expand(s1, s2);
    printf("Expanded: %s\n", s2);

    return 0;
}
