# include <stdio.h>

int main(void)
{
    float vol1, vol2, temp1, temp2, vol, temp;
    setbuf(stdout, NULL);
	printf ("input vol1, vol2: ");
	scanf ("%f,%f", &vol1, &vol2);
	printf ("input temp1, temp2: ");
	scanf ("%f,%f", &temp1, &temp2);
	vol = vol1 + vol2;
	temp = (vol1 * temp1 + vol2 * temp2) / (vol1 + vol2);
	printf("Liquid volume is: %f, temperature is: %f", vol, temp);
}
