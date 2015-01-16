#include<stdio.h>

void clear_buffer(char*, int);


int main(int argc, char* argv[])
{
    char buf[32];

    int c;
    for (int i = 0; (c = getchar()) != EOF; i++) {
        if (c == '\n') {
            printf("%s\n", buf);
            clear_buffer(buf, i);
            i = -1;
        } else {
            buf[i] = c;
        }
    }
}

void clear_buffer(char* buf, int sz)
{
    for (int i = 0; i < sz; i++) {
        buf[i] = 0;
    }
}
