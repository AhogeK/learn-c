//
// Created by Ahoge Knight on 2023/2/7.
//

// Only for this file, can't get static_function.c's define
// static void count();

void count2();

int main()
{
    // undefined reference to "count()"
    // count();

    count2();
    count2();
    count2();
}
