// Given 2 strings A and B returns starting indexs of occurences B in A
// This is the Hosrpool Implementation
#include<bits/stdc++.h>
#define CHAR_SET_SIZE 256
int maximum (int a, int b)
{
    return (a > b)? a: b;
}
void preprocess(char *str, int size, int R[CHAR_SET_SIZE])
{
    int i;
    for(i = 0; i < CHAR_SET_SIZE; i++)
       R[i] = -1;

    for(i = 0; i < size; i++)
       R[(int) str[i]] = i;
}

void patternMatcher(char *T,  char *P)
{
    int n=strlen(T),m=strlen(P),j;
    int R[CHAR_SET_SIZE];

    preprocess(P,m,R);
    int s=0,count=0;

    while(s <= (n - m))
    {
        j = m-1;
        while(j >= 0 && P[j] == T[s+j])
            j--;

        if(j < 0)
        {
            printf("(%d)", s);count++;
            s += (s+m < n)? m-R[(int)T[s+m]] : 1;
        }
        else
            s += maximum(1, j - R[(int)T[s+j]]);
    }

    if(!count)
        printf("%d",-1);
}

int main()
{
    char T[100];
    char P[100];

    scanf("%s%s",T,P);
    patternMatcher(T, P);
    return 0;
}
