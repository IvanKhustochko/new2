#include <stdio.h>
#include <string.h>

int main() 
{
    char N[100];
    scanf("%s", N);
    
    int len = strlen(N);
    int count = 0;
    for (int num = 100; num <= 999; num++) 
    {
        int d1 = num / 100;         
        int d2 = (num / 10) % 10;    
        int d3 = num % 10;          
        int found = 0;
        for (int i = 0; i < len && !found; i++) 
        {
            if (N[i] == d1 + '0') {
                for (int j = i + 1; j < len && !found; j++) 
                {
                    if (N[j] == d2 + '0') {
                        for (int k = j + 1; k < len && !found; k++) 
                        {
                            if (N[k] == d3 + '0') 
                            {
                                found = 1;
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("%d\n", count);
    return 0;
}
