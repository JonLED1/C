#include <stdio.h>

int main(int argc, char **argv)
{
	int a;
	float aver;
	printf("Enter four-digit number: ");
	scanf("%d", &a);

	aver = (float) (a/1000%10 + a/100%10 + a/10%10 + a%10)/4;

	printf("Average = %.2f", aver);
	
	return 0;
}

/*
Прорамма рабоатет не правильно, если в числе есть нули. кроме как через перебор и проверку цифры на ноль
 (либо со счетчиком цифр) не знаю как решить. но мы вроде циклы и условия еще не проходили.
*/