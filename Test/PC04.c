#include "utils.h"


int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int i);
int		ft_atoi(char* str);
void	ft_putnbr_base(int nb, char* base);

int main()
{

	print_ex(0);
	printf("ft_strlen(\"Salut\")  = %d strlen(\"Salut\")  = %lu\n",ft_strlen("Salut"),strlen("Salut"));
	printf("ft_strlen(\"\")       = %d strlen(\"\")       = %lu\n",ft_strlen(""),strlen(""));
	printf("ft_strlen(\" Salut\") = %d strlen(\" Salut\") = %lu\n",ft_strlen(" Salut"),strlen(" Salut"));

	print_ex(1);
	ft_putstr("Salut");
	ft_putstr(" Salut");
	ft_putstr(" Sa\0lut");
	printf("\n");
	print_ex(2);
	ft_putnbr(10);
	printf("\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(30);
	printf("\n");
	ft_putnbr(50);
	printf("\n");
	ft_putnbr(-100);
	printf("\n");
	ft_putnbr(-1000);
	printf("\n");
	ft_putnbr(1000);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(-1);

	printf("\n");
	print_ex(3);

	printf("ft_atoi(\"    --+---+2147483648dd\" )                 = %d\n",ft_atoi("   --+---+2147483648dd"));
	printf("ft_atoi(\"    --+---+2147483647dd\" )                 = %d\n",ft_atoi("   --+--+2147483647dd"));
	printf("ft_atoi(\"    --+---+21474836438dd\" )                 = %d\n",ft_atoi("   --+--+21474836438dd"));

	printf("ft_atoi(\"    --+---+1234dd\" )                 = %d\n",ft_atoi("   --+---+1234dd"));
	printf("ft_atoi(\"    --+---+5346d/d45\" )              = %d\n",ft_atoi("    --+---+5346d/45"));
	printf("ft_atoi(\"--+--+1234dd\" )                      = %d\n",ft_atoi("--+--+1234dd"));
	printf("ft_atoi(\"                   --+++-+1234dd\" )  = %d\n",ft_atoi("                   --+++-+1234dd"));
	printf("ft_atoi(\"    ++++---+12#34dd\" )               = %d\n",ft_atoi("    ++++---+12#34dd"));
	printf("ft_atoi(\"    --+---+1234dd\" )                 = %d\n",ft_atoi("    --+---+1234dd"));
	printf("ft_atoi(\"    --+-,-+1234dd\" )                 = %d\n",ft_atoi("    --+-,-+1234dd"));
	printf("ft_atoi(\"    --+- -+1234dd\" )                 = %d\n",ft_atoi("    --+-,-+1234dd"));
	printf("ft_atoi(\"    --+--+123\\r4dd\" )                 = %d\n",ft_atoi("    --+--+0123\r4dd"));
	printf("ft_atoi(\"    --+--+12\\n34dd\" )                 = %d\n",ft_atoi("    --+--+12\n34dd"));
	printf("ft_atoi(\"\\f \\t \\r   \\n--+--+1234dd\" )                 = %d\n",ft_atoi(" \f \t \r   \n--+--+01234dd"));
	printf("ft_atoi(\"\\f \\t \\r   \\n--+\t--+1234dd\" )                 = %d\n",ft_atoi(" \f \t \r   \n--+\t--+01234dd"));

	print_ex(4);
	for(int i =-100; i < 100; i += 4)
	{
		ft_putnbr(i);
		ft_putstr("-> binary:               ");
		ft_putnbr_base(i,"");
		printf("\n");

		ft_putnbr(i);
		ft_putstr("-> quartenary:           ");
		ft_putnbr_base(i,"0123");
		printf("\n");

		ft_putnbr(i);
		ft_putstr("-> octal                 ");
		ft_putnbr_base(i,"poneyvif");
		printf("\n");

		ft_putnbr(i);
		ft_putstr("-> hexadecimal           ");
		ft_putnbr_base(i,"0123456789ABCDEF");
		printf("\n");

		ft_putnbr(i);
		ft_putstr("-> duotrigesimal         ");
		ft_putnbr_base(i,"0123456789ABCDEFGHIJKLMNOPQRSTUV");
		printf("\n");

		ft_putnbr(i);
		ft_putstr("-> qwrt56&0)/?           ");
		ft_putnbr_base(i,"qwrt56&0)/?");
		printf("\n");

		ft_putnbr(i);
		ft_putstr("-> abcdefghij            ");
		ft_putnbr_base(i,"abcdefghij");
		printf("\n");

		ft_putnbr(i);
		ft_putstr("-> abcdef9876543210      ");
		ft_putnbr_base(i,"abcdef9876543210");
		printf("\n");
		printf("\n");

	}

	int i = -2147483648;
	ft_putnbr(i);
	ft_putstr("-> binary:               ");
	ft_putnbr_base(i,"01");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> quartenary:           ");
	ft_putnbr_base(i,"0123");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> octal                 ");
	ft_putnbr_base(i,"poneyvif");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> hexadecimal           ");
	ft_putnbr_base(i,"0123456789ABCDEF");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> duotrigesimal         ");
	ft_putnbr_base(i,"0123456789ABCDEFGHIJKLMNOPQRSTUV");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("->01234567               ");
	ft_putnbr_base(i,"012345678");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> qwrt56&0)/?           ");
	ft_putnbr_base(i,"qwrt56&0)/?");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> abcdefghij            ");
	ft_putnbr_base(i,"abcdefghij");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> abcdef9876543210      ");
	ft_putnbr_base(i,"abcdef9876543210");
	printf("\n");
	printf("\n");



	i = __INT_MAX__;
	ft_putnbr(i);
	ft_putstr("-> binary:               ");
	ft_putnbr_base(i,"01");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> quartenary:           ");
	ft_putnbr_base(i,"0123");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> octal                 ");
	ft_putnbr_base(i,"poneyvif");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> hexadecimal           ");
	ft_putnbr_base(i,"0123456789ABCDEF");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> duotrigesimal         ");
	ft_putnbr_base(i,"0123456789ABCDEFGHIJKLMNOPQRSTUV");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("->01234567               ");
	ft_putnbr_base(i,"012345678");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> qwrt56&0)/?           ");
	ft_putnbr_base(i,"qwrt56&0)/?");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> abcdefghij            ");
	ft_putnbr_base(i,"abcdefghij");
	printf("\n");

	ft_putnbr(i);
	ft_putstr("-> abcdef9876543210      ");
	ft_putnbr_base(i,"abcdef9876543210");
	printf("\n");
	printf("\n");

	return 0;
}
