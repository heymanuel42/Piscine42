#include "utils.h"

int ft_iterative_factorial(int nb);
int ft_recursive_factorial(int nb);
int ft_iterative_power(int nb, int power);
int ft_recursive_power(int nb, int power);
int ft_fibonacci(int index);
int ft_sqrt(int index);
int ft_is_prime(int index);
int ft_find_next_prime(int index);

int main()
{
	printf("\nfactorial \n");
	for(int i = -5; i < 10; i++)
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
	printf("sqrt(%d) = %d\n",__INT_MAX__,ft_sqrt(__INT_MAX__));

	printf("%d\n",ft_recursive_power(1,1));
	printf("\nprime\n");
	for(int i = -10; i < 100; i++)
	{
		printf("is_prime(%d) = %d\n",i,ft_is_prime(i));
	}

	printf("\nnext prime\n");
	for(int i = -10; i < 100; i++)
	{
		printf("next_prime(%d) = %d\n",i,ft_find_next_prime(i));
	}

	printf("next_prime(%d) = %d\n",2147483643,ft_find_next_prime(2147483643));
	printf("next_prime(%d) = %d\n",2147483644,ft_find_next_prime(2147483644));
	printf("next_prime(%d) = %d\n",2147483645,ft_find_next_prime(2147483645));
	printf("next_prime(%d) = %d\n",2147483646,ft_find_next_prime(2147483646));


	printf("%d %d\n",(int)9742051863,ft_find_next_prime((int)9742051863));
	return 0;
}
