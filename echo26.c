#include "stdio.h"
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int arr[a][b];
    int time=0;
    double frequency=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
        scanf("%d",&arr[a][b]);}}
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if (arr[i-1][j]==arr[i][j])
            {time++;}}
    }
    frequency = time/(a*b);
    printf("time=%d,frequency=%lf\n",time,frequency);
    system("pause");
    return 0;
}

          
