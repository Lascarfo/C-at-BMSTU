# include <stdio.h>

int main(void)
{
	float vol1, vol2, temp1, temp2, vol, temp;
	setbuf(stdout, NULL);
    printf("input vol1, temp1: ");
    scanf("%f %f", &vol1, &temp1);
    printf("input vol2, temp2: ");
    scanf("%f %f", &vol2, &temp2);
	vol = vol1 + vol2;
	temp = (vol1 * temp1 + vol2 * temp2) / (vol1 + vol2);
    printf("Liquid volume is: %.4f, temperature is: %.4f", vol, temp);
}
