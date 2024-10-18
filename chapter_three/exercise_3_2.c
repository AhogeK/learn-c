//
// Created by AhogeK on 10/18/24.
//

#include <stdio.h>

void escape(char s[], const char t[])
{
    int i, j;
    i = j = 0;
    while (t[i] != '\0')
    {
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        case '\b':
            s[j++] = '\\';
            s[j++] = 'b';
            break;
        case '\r':
            s[j++] = '\\';
            s[j++] = 'r';
            break;
        case '\f':
            s[j++] = '\\';
            s[j++] = 'f';
            break;
        case '\v':
            s[j++] = '\\';
            s[j++] = 'v';
            break;
        case '\\':
            s[j++] = '\\';
            s[j++] = '\\';
            break;
        case '\"':
            s[j++] = '\\';
            s[j++] = '\"';
            break;
        case '\'':
            s[j++] = '\\';
            s[j++] = '\'';
            break;
        default:
            s[j++] = t[i];
            break;
        }
        i++;
    }
    s[j] = '\0';
}

void unescape(char s[], const char t[])
{
    int i, j;
    i = j = 0;
    while (t[i] != '\0')
    {
        if (t[i] == '\\')
        {
            switch (t[i + 1])
            {
            case 'n':
                s[j++] = '\n';
                i++;
                break;
            case 't':
                s[j++] = '\t';
                i++;
                break;
            case 'b':
                s[j++] = '\b';
                i++;
                break;
            case 'r':
                s[j++] = '\r';
                i++;
                break;
            case 'f':
                s[j++] = '\f';
                i++;
                break;
            case 'v':
                s[j++] = '\v';
                i++;
                break;
            case '\\':
                s[j++] = '\\';
                i++;
                break;
            case '\"':
                s[j++] = '\"';
                i++;
                break;
            case '\'':
                s[j++] = '\'';
                i++;
                break;
            default:
                s[j++] = t[i];
                break;
            }
        }
        else
        {
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0';
}

int main()
{
    char t[] = "Hello\tWorld\nThis is a test with \\backslash and \"quotes\".";
    char s[200];
    char u[200];

    escape(s, t);
    printf("Escaped: %s\n", s);

    unescape(u, s);
    printf("Unescaped: %s\n", u);

    return 0;
}
