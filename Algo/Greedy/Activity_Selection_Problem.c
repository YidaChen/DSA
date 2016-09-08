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
/*
Let N denote the number of activities and
{I}  the activity I  ( 1 <= I <= N )
For each {I}, consider S[I] and F[I] its starting and finishing time
Sort the activities in the increasing order of their finishing time
- that is, for every I < J we must have F [I] <= F [J]

//  A denotes the set of the activities that will be selected
A = {1}
//  J denotes the last activity selected
J = 1
For I = 2  to N
// we can select activity 'I' only if the last activity
// selected has already been finished
      If S [I] >= F [J]
//  select activity 'I'
                A = A + {I}
// Activity 'I' now becomes the last activity selected
                J = I
      Endif
Endfor
Return A
*/