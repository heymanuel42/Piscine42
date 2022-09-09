#include "utils.h"

char	*ft_strdup(char *s1);
int		*ft_range(int min, int max);

int main()
{
	char *s1 = "Hello world";
	char *cpy = ft_strdup(s1);
	printf("%s\n",cpy);
	free(cpy);

	int *range = ft_range(40,100);
	for(int i = 0; i <= 60; i++)
	{
		printf("%d ,",range[i]);
	}
	printf("\n");
	free(range);

	return 0;
}
