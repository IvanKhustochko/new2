#include <stdio.h>

int main() 
{
    unsigned int N;
    unsigned int K;
  
    scanf("%u %u", &N, &K);

    unsigned int right_part = N >> K; 

    unsigned int left_part = N << (32 - K);     
    
    unsigned int result = right_part | left_part;
    
    printf("%u\n", result);
    
    return 0;
}