#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char word[101];
    scanf("%[^\n]", word);
    int i = 0;
    int sum= 0;
    while(word[i])
    {
        if (word[i] % 2 != 0)
        {
            sum += word[i];
        }
        i++;
    }
    printf("%d\n", sum);
    return 0;
}