//
// Created by ahogek on 9/17/21.
//

int powerv2(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}