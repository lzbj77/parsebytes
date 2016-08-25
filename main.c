#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i = 0;
	unsigned char j = 0;
	long num = 0x12AB56EF;
	long *ptr;
	char *ptrc;
	
	printf("we take one long number: 0x%X\n\n", num);
	
	//преобразуем в побайтовое представление через логические сдвиги вправо
	
	for (i=0;i<4;i++)
	{
		j =  (num & 0xFF000000)>>24;
		printf("%x\n", j);
		num = num << 8;
	}

	//преобразуем в побайтовое представление через чтение ячеек памяти, занимаемых переменной
	
	num = 0x12AB56EF;
	ptrc = (char *)&num;
	printf("\n\nand again we take one long number: 0x%X\n", num);
	printf("it lies in memory at %x\n\n",ptrc);


	for (i=0;i<4;i++)
	{
		j = *ptrc;
		printf("%x - %x\n", ptrc, j);
		*ptrc++;
	}
	
	return 0;
	
}
