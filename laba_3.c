#include <stdio.h>
#define SIZE 1000
int main(void)
{
    char str1[SIZE];
    char str2[SIZE];
    char pr[SIZE];
    
    
    int cpr = 0;
    int counter = 0;
    int p, i, j, n;
    int len2;
    
    printf("Enter the string: \n");
    fgets(str1, SIZE, stdin);
    int len = strlen(str1);
    str1[len] = ' ';
    char *s = str1;

 
    
    printf("Enter the prist: \n");
    fgets(pr, SIZE, stdin);
    
    int prlen = strlen(pr);
    char *h = pr;
    
    char *s2 = str2;
    
    for(int i = 0; i <= len; i++)
    {
        if(((*(s+i) >= '0')&&(*(s+i) <= '9'))||((*(s+i-1) >= '0')&&(*(s+i-1) <= '9')))
        {
            counter = 0;
            continue;
        }
        else if((*(s+i) != ' ')&&(*(s+i) != '.')&&(*(s+i) != ','))
            counter++;
        else
        {
            
            for(p = i - counter, j = 0; j < prlen; j++, p++)
            {
                if(*(s+p) == *(h+j))
                    cpr++;
                else
                    break;
            }
            
            if(cpr == prlen)
            {
                for(p = i - counter, j = 0; j < counter; j++, p++)
                    *(s+p) = ' ';
            }
            
            cpr = 0;
            counter = 0;
        }
    }
    
    for( i = 0, j =0; i < len; i++)
    {
        if((*(s+i) == ' ') && (*(s+i+1) == ' '))
            continue;
        *(s2+j) = *(s+i);
        j++;
    }
    
    len2 = strlen(str2);
    
    for(int i = 0; i < len2; i++)
    {
        printf("%c", *(s2+i));
    }
    
    return 0;
}

