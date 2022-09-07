#include "utils.h"

int	ft_strcmp(char *s1, char *s2);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int n);
char	*ft_strstr(char *str, char *to_find);
int	ft_strlcat(char* dest, char *src, unsigned int n);


void check_strstr(char* str, char *to_find)
{
	printf("strstr    - Phrase = \"%s\" look for \"%s\" returns :\"%s\"\n",str,to_find,strstr(str,to_find));
	printf("ft_strstr - Phrase = \"%s\" look for \"%s\" returns :\"%s\"\n\n",str,to_find,ft_strstr(str,to_find));
	
}

int main()
{

	print_ex(0);
	printf("strcmp\n");
	printf("%d\n",strcmp("Hello","Hello"));
	printf("%d\n",strcmp("Hello","Hellx"));
	printf("%d\n",strcmp("Hello","Hllo"));
	printf("%d\n",strcmp("Hellox","Hello"));


	printf("ft_strcmp\n");
	printf("%d\n",ft_strcmp("Hello","Hello"));
	printf("%d\n",ft_strcmp("Hello","Hellx"));
	printf("%d\n",ft_strcmp("Hello","Hllo"));
	printf("%d\n",ft_strcmp("Hellox","Hello"));

	print_ex(1);
	printf("strncmp\n");
	   char str1[] = "salut";
    char str2[] = "salut";
    char str3[] = "salut";
    char str4[] = "salut";
    char str5[] = "";
    char str6[] = "salut";
    char str7[] = "";
    char str8[] = "";
    char str9[] = "sa79";
    char str10[] = "saab";
    char str11[] = "sagnr";
    char str12[] = "ggdhn";
    char str13[] = "sagnr";
    char str14[] = "ggdhn";

    printf("%d\n", ft_strncmp(str1, str2, 2));
    printf("%d\n", strncmp(str1, str2, 2));
    printf("%s\n", "--------------------");
    printf("%d\n", ft_strncmp(str3, str4, 5));
    printf("%d\n", strncmp(str3, str4, 2));
    printf("%s\n", "--------------------");
    printf("%d\n", ft_strncmp(str5, str6, 2));
    printf("%d\n", strncmp(str5, str6, 2));
    printf("%s\n", "--------------------");
    printf("%d\n", ft_strncmp(str7, str8, 20));
    printf("%d\n", strncmp(str7, str8, 20));
    printf("%s\n", "--------------------");
    printf("%d\n", ft_strncmp(str9, str10, 2));
    printf("%d\n", strncmp(str9, str10, 2));
    printf("%s\n", "--------------------");
    printf("%d\n", ft_strncmp(str11, str12, 5));
    printf("%d\n", strncmp(str11, str12, 5));
    printf("%s\n", "--------------------");
    printf("%d\n", ft_strncmp(str13, str14, 0));
    printf("%d\n", strncmp(str13, str14, 0));
    printf("%s\n", "--------------------");
	
	printf("%d == %d\n",strncmp("hel","Hello",10),ft_strncmp("hel","Hello",10));
	printf("%d == %d\n",strncmp("Hello","Hello",3),ft_strncmp("Hello","Hello",3));
	printf("%d == %d\n",strncmp("banana","Hell",4),ft_strncmp("banana","Hell",4));
	printf("%d == %d\n",strncmp("HEllo","Hello",1),ft_strncmp("HEllo","Hello",1));
	printf("%d == %d\n",strncmp("","Hello",1),ft_strncmp("","Hello",1));
	printf("%d == %d\n",strncmp("HEllo","",1),ft_strncmp("HEllo","",1));

	printf("%d == %d\n",strncmp("","",1),ft_strncmp("","",1));
	printf("%d == %d\n",strncmp("'\\)0@#'","'\\)0'",2),ft_strncmp("'\\)0@#'","'\\)0'",2));
	printf("%d == %d\n",strncmp("'\\)0@#'","'\\)0'",10),ft_strncmp("'\\)0@#'","'\\)0'",10));
	printf("%d == %d\n",strncmp("'\\)0@#'","'\\)0'",10),ft_strncmp("'\\)0@#'","'\\)0'",10));

	print_ex(2);

	char dest[512] = "World";
	char src[] = "Hello";
	printf("%s\n",ft_strcat(dest,src));
	char dest3[512] = "World"; 
	printf("%s\n",strcat(dest3,src));
	print_ex(3);
	char dest4[512] = "World";
	printf("%s\n",ft_strncat(dest4,src,3));
	char dest2[512] = "World";
	char src2[] = "Hello";
	printf("%s\n",ft_strncat(dest2,src2,3));
	
	print_ex(4);
	check_strstr("It's going to be okey","o ");
	check_strstr("Hello ","lo");
	check_strstr("Vive la bolo ","la");
	check_strstr("*fsda\\$ds&h*l)(d) ","h*");
	check_strstr("*fff\\$ds&h*l)(d) ","\\");
	check_strstr("///\\$ds&h*l)(d) ","lo");
	check_strstr("   . . "," . ");
	check_strstr("  \0a  ","a");
	
	print_ex(5);
	char s51[512] = "Good Bye";
	char s53[512] = "Salut";
	char s55[512] = "Good Bye,";
	char s57[512] = "Good Bye,";
	char s511[512] = "Good Bye ";
	char s533[512] = "Salut";
	char s555[512] = "Good Bye,";
	char s577[512] = "Good Bye,";
	char s52[] = "Hello World";
	char s56[] = "Hello World";
	char s54[] = "Le monde";	
	char s58[] = "Hello World";

	printf("strlcat       - Tried to copy %lu characters %s\n", strlcat(s51,s52,2),s51);
	printf("strlcat       - Tried to copy %lu characters %s\n", strlcat(s53,s54,10),s53);
	printf("strlcat       - Tried to copy %lu characters %s\n", strlcat(s55,s56,14),s55);
	printf("strlcat       - Tried to copy %lu characters %s\n\n", strlcat(s57,s58,4),s57);


	printf("strlcat       - Tried to copy %d characters %s\n", ft_strlcat(s511,s52,2),s511);
	printf("strlcat       - Tried to copy %d characters %s\n", ft_strlcat(s533,s54,10),s533);
	printf("strlcat       - Tried to copy %d characters %s\n", ft_strlcat(s555,s56,14),s555);
	printf("strlcat       - Tried to copy %d characters %s\n", ft_strlcat(s577,s58,4),s577);
	return 0;
}