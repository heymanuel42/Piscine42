#include "utils.h"


int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int i);
int		ft_atoi(char* str);
void	ft_putnbr_base(int nb, char* base);

int main()
{

	print_ex(0);
	printf("%d \n",ft_strlen("Salut"));
	printf("%d \n",ft_strlen(""));
	printf("%d \n",ft_strlen(" Salut"));
	printf("%d \n",ft_strlen(" Salut"));
	printf("%lu \n",strlen(" Salut"));

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
	ft_putnbr(34593245);
	printf("\n");
	ft_putnbr(-1);

	printf("\n");
	print_ex(3);

	printf("%d\n",ft_atoi("    --+---+1234dd"));
	printf("%d\n",ft_atoi("    --+---+5346d%d45"));
	printf("%d\n",ft_atoi("--+--+1234dd"));
	printf("%d\n",ft_atoi("                   --+++-+1234dd"));
	printf("%d\n",ft_atoi("    ++++---+12#34dd"));
	printf("%d\n",ft_atoi("    --+---+1234dd"));

	print_ex(4);
	printf("hex\n");
	ft_putnbr_base(20, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(2, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(456, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(123456, "0123456789ABCDEF");
	printf("\n");
	printf("bin\n");
	ft_putnbr_base(20, "01");
	printf("\n");
	ft_putnbr_base(-20, "01");
	printf("\n");
	ft_putnbr_base(2, "01");
	printf("\n");
	ft_putnbr_base(456, "01");
	printf("\n");
	ft_putnbr_base(123456, "01");
	printf("\n");
	ft_putnbr_base(-123456, "01");

	printf("\n");
	printf("oc\n");
	ft_putnbr_base(20, "poneyvif");
	printf("\n");
	ft_putnbr_base(2, "poneyvif");
	printf("\n");
	ft_putnbr_base(456, "poneyvif");
	printf("\n");
	ft_putnbr_base(123456, "poneyvif");
	return 0;
}