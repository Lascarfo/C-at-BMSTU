# include <stdio.h>
# define SS 36
# define SF 35
# define KVO 4
# define KV 3
int main(void)
{
    int number, pod, st;
    setbuf (stdout, NULL);
    printf("input room's number: ");
    scanf("%d", &number);
    pod = (number + SF) / SS;
    number = number - (pod - 1 )* SS;
    st = (( number + KV ) / KVO);
    printf("podjezd is: %d, stage is: %d", pod, st);
}
