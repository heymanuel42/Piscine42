#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);
void	ft_print_alphabet(void);
void	ft_print_reverse_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_print_comb(void);
void	ft_print_comb2(void);
void	ft_putnbr(int nb);

void	nl()
{
	ft_putchar('\n');
}

void	sep(int i)
{
	printf("ex 0%d ----------------------------------\n",i);
}

int 	main(void)
{
	sep(0);
	for(int i = 0; i < 10; i++){
		ft_putchar('0'+i);
	}
	nl();
	sep(1);
	ft_print_alphabet();
	nl();
	sep(2);
	ft_print_reverse_alphabet();
	nl();
	sep(3);
	ft_print_numbers();
	nl();
	sep(4);
	ft_is_negative(10);
	nl();
	ft_is_negative(-1);
	nl();
	sep(5);
	ft_print_comb();
	ft_print_comb2();
	nl();
	for(int i = 0; i < 100; i++){
		ft_putnbr(i);
		ft_putchar(' ');
	}
	nl();
	for(int i = 0; i > -100; i--){
		ft_putnbr(i);
		ft_putchar(' ');
	}
	nl();
	return (0);
}
