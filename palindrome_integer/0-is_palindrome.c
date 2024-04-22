#include <stdio.h>
#include <palindrome.h>
int size(int n)
{
    for(int i = 1;;i++)
    {
        n/=10;
        if(n==0)
            return i;
    }
    return 0;
}

int pow_10(int n){
    int value = 1;
    for(int i =0;i<n;i++)
    {
        value*=10;
    }
    return value;
}
int is_palindrome(int n) {
    int Size = size(n);
    for(int i =0;i<Size;i++)
    {
        int leftmost = n / pow_10(Size-i-1) % 10;
        int rightmost = n / pow_10(i) % 10;
        if(leftmost!=rightmost)
            return 0;
    }
    return 1;
}
