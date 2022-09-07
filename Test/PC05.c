#include "utils.h"

int ft_iterative_factorial(int nb);


int main()
{
	for(int i = 0; i < 10; i++)
	{
		printf("%d! = %d\n",i,ft_iterative_factorial(i));
	}
	return 0;
}
