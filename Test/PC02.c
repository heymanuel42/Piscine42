#include "utils.h"

char	*ft_strcpy(char* dest, char* src);
char	*ft_strncpy(char* dest, char* src, unsigned int n);
int		ft_str_is_alpha(char *str);
int		ft_str_is_numeric(char* str);
int		ft_str_is_lowercase(char *str);
int		ft_str_is_uppercase(char *str);
int		ft_str_is_printable(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);
void	ft_putstr_with_non_printable(char *str);
void	*ft_print_memory(void *addr, unsigned int size);

int main(int argc, char **argv)
{
	argc--;
	char *ex = argv[1];
	if(!strcmp(ex,"00"))
	{
		print_ex(0);
		char buff[512] = "World";
		char *to_copy;
		to_copy = "Hello";
		printf("copying %s into buffer\n",to_copy);
		printf("Before copy: %s\n",buff);
		ft_strcpy(buff,to_copy);
		printf("After copy: %s\n",buff);
	}
	else if(!strcmp(ex,"01"))
	{
		print_ex(1);
		char buff2[512] = "World";
		char *to_copy2;
		to_copy2 = "Hello";

		printf("Before copy: %s\n",buff2);
		ft_strncpy(buff2,to_copy2,20);
		printf("After copying 2 characters: %s\n",buff2);
	}else if(!strcmp(ex,"02"))
	{
		print_ex(2);
		printf("abcdef is alpha? : %d\n", ft_str_is_alpha("abcedf"));
		printf("zbcdef is alpha? : %d\n", ft_str_is_alpha("zbcdef"));
		printf("ab4def is alpha? : %d\n", ft_str_is_alpha("ab4edf"));
		printf("abbb\\ is alpha? : %d\n", ft_str_is_alpha("abbb\\"));
	}else if(!strcmp(ex,"03"))
	{
		print_ex(3);
		printf("12345 is numeric? : %d\n", ft_str_is_numeric("12345"));
		printf("333r is numeric? : %d\n", ft_str_is_numeric("333r"));
		printf("444O is numeric? : %d\n", ft_str_is_numeric("444O"));
	}else if(!strcmp(ex,"04"))
	{
		print_ex(4);
		printf("hello is lowercase? : %d\n", ft_str_is_lowercase("hello"));
		printf("Hello is lowercase? : %d\n", ft_str_is_lowercase("Hello"));
	}else if(!strcmp(ex,"05"))
	{
		print_ex(5);
		printf("HELLO is uppercase? : %d\n", ft_str_is_uppercase("HELLO"));
		printf("HELLo is uppercase? : %d\n", ft_str_is_uppercase("HELLo"));
	}else if (!strcmp(ex,"06"))
	{
		print_ex(6);
		
		printf("HELLo&^*(&^_)\\'` is printable? : %d\n", ft_str_is_printable("HELLo&^*(&^_)\\'`"));
		printf("? is printable? : %d\n", ft_str_is_printable("?"));
	}else if(!strcmp(ex,"07"))
	{
		print_ex(7);
		char s[] = "hello";
		char s2[] = "h3ll0";
		printf("hello to uppercase : %s\n", ft_strupcase(s));
		printf("h3ll0 to uppercase : %s\n", ft_strupcase(s2));
	}
	else if(!strcmp(ex,"08"))
	{
		print_ex(8);
		char s3[] = "HELLO";
		char s4[] = "H3LL0";
		printf("HELLO to lowercase : %s\n", ft_strlowcase(s3));
		printf("H3LL0 to lowercase : %s\n", ft_strlowcase(s4));
	}
	else if(!strcmp(ex,"09"))
	{
		print_ex(9);
		char s5[] = "X^:_5mzY{3yEv{11B5%5'1UMbOu	9";
		char s51[] = "HW/3_0n{H";
		char s52[] = "ReKt17+LOl -DR Mdr 4242l42";
		char s53[] = "`,2Ex [(+7x3QM2f9jJh^%93rN2ks;5,^";
		char s54[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

		printf("- %s\n",s5);
		printf("+ %s\n",ft_strcapitalize(s5));
		printf("- %s\n",s51);
		printf("+ %s\n",ft_strcapitalize(s51));
		printf("- %s\n",s52);
		printf("+ %s\n",ft_strcapitalize(s52));	
		printf("- %s\n",s53);
		printf("+ %s\n",ft_strcapitalize(s53));
		printf("- %s\n",s54);
		printf("+ %s\n",ft_strcapitalize(s54));
	}
	else if(!strcmp(ex,"10"))
	{
		print_ex(10);
		char s6[512] = "Hello";
		char *s7 = "Gwkki World";
		char *s8 = "oafgh98";
		char *s9 = "12345678";
		char *s10 = "jjjpppj.,/'=[";
		char *s11 = "&^%5987][#987\\";

		printf("Before copy: %s\n",s6);
		printf("length 2 - tried to copy string(%s) length(%d) end res = %s\n",s7,ft_strlcpy(s6,s7,2),s6);
		printf("length 4 - tried to copy string(%s) length(%d) end res = %s\n",s8,ft_strlcpy(s6,s8,4),s6);

		printf("length 6 - tried to copy string(%s) length(%d) end res = %s\n",s9,ft_strlcpy(s6,s9,6),s6);
		printf("length 8 - tried to copy string(%s) length(%d) end res = %s\n",s10,ft_strlcpy(s6,s10,8),s6);
		printf("length 8 - tried to copy string(%s) length(%d) end res = %s\n",s11,ft_strlcpy(s6,s11,8),s6);
		printf("length 20 - tried to copy string(%s) length(%d) end res = %s\n",s8,ft_strlcpy(s6,s8,20),s6);
		printf("length 20 - tried to copy string(%s) length(%d) end res = %s\n",s11,ft_strlcpy(s6,s11,20),s6);


	}
	else if(!strcmp(ex,"11"))
	{
		print_ex(11);
		char s8[512] = "Coucou, \n  tu vas bien ?  Â ~ \n";
		ft_putstr_with_non_printable(s8);
		printf("\n");
	}
	else if(!strcmp(ex,"12"))
	{
		print_ex(12);
		char s9[] =  "Hello world";
		for(int i = 0; i  < 24; i++){
			ft_print_memory(s9,i);
		}

	}
	return (0);
}