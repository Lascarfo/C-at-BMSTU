# include <stdio.h>
# include <conio.h>
int main(void)
{
	int number, pod, st;
	setbuf (stdout, NULL);
	printf("input room's number: ");
	scanf("%d", &number);
	pod = (number + 35) / 36;
	number = number - (pod  -1 ) * 36;
	st = (( number + 3 ) / 4);
	printf("podjezd is: %d, stage is: %d", pod, st);
}
