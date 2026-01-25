#include <stdio.h>

int main() 
{
    int N;
    scanf("%d", &N);

    if (N <= 0) 
    {
        printf("0\n");
        return 0;
    }

    int max;
    int count = 0;
    int num;
    scanf("%d", &num);
    max = num;
    count = 1;
    for (int i = 1; i < N; i++) 
    {
        scanf("%d", &num);
        
        if (num > max) 
        {
            max = num;
            count = 1;
        } else if (num == max) 
        {

            count++;
        }
    }
    
    printf("%d\n", count);
    return 0;
}