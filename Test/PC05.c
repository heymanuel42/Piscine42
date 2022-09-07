#include "utils.h"

int ft_iterative_factorial(int nb);
int ft_recursive_factorial(int nb);
int ft_iterative_power(int nb, int power);
int ft_recursive_power(int nb, int power);
int ft_fibonacci(int index);
int ft_sqrt(int index);

int main()
{
	printf("\nfactorial \n");
	for(int i = 0; i < 10; i++)
	{
		printf("iter(%d! = %d) && rec(%d! = %d)\n",i,ft_iterative_factorial(i),i,ft_recursive_factorial(i));
	}

	printf("\npower\n");
	for(int i = -5,j = 0; i < 10; i++ ,j++)
	{
		printf("iter(%d^%d) = %d, rec(%d^%d) = %d\n",i,j,ft_iterative_power(i,j),i,j,ft_recursive_power(i,j));
	}

	printf("\nfibonacci\n");
	for(int i = 0; i < 10; i++)
	{
		printf("fib(%d) = %d\n",i,ft_fibonacci(i));
	}

	printf("%d\n",ft_recursive_power(1,1));
	printf("\nsqrt\n");
	for(int i = 0; i < 100; i++)
	{
		printf("sqrt(%d) = %d\n",i,ft_sqrt(i));
	}
	return 0;
}
