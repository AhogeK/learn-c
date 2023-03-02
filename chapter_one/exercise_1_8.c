//
// Created by Ahoge Knight on 2023/3/1.
//

#include <stdio.h>

int main()
{
    int c;
    int space_count = 0;
    int tab_count = 0;
    int newline_count = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            space_count++;
        else if (c == '\t')
            tab_count++;
        else if (c == '\n')
            newline_count++;
    }

    printf("Spaces: %d\n", space_count);
    printf("Tabs: %d\n", tab_count);
    printf("Newlines: %d\n", newline_count);

    return 0;
}