#include <stdio.h>

void printMaxActivities(int s[], int f[], int n)
{
    int preAct, nextAct;
    preAct = 0;
    printf("%d ", preAct);
    
    for(nextAct = 1; nextAct < n; nextAct++)
    {
        if(s[nextAct] > f[preAct])
        {
            printf("%d ", nextAct);
            preAct = nextAct;
        }
    }
}

int main()
{
//activities are already sorted according to their finish time
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
}