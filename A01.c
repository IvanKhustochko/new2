#include <stdio.h>

int main() 
{
    int N;
    scanf("%d", &N);
    
    char ch;
    while ((ch = getchar()) != '.') 
	{
        if (ch >= 'a' && ch <= 'z') 
		{
            printf("%c", 'a' + (ch - 'a' + N) % 26);
        } else if (ch >= 'A' && ch <= 'Z') 
		{
            printf("%c", 'A' + (ch - 'A' + N) % 26);
        } else if (ch == ' ') 
		{
            printf(" ");
        }

    }
    
    printf(".\n");
    return 0;
}