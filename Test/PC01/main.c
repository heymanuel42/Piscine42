#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_ft(int *nbr);
void ft_ultimate_ft(int *********nbr);
void ft_swap(int *a, int *b);
void ft_div_mod(int a, int b, int *div, int *mod);
void ft_ultimate_div_mod(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
void ft_rev_int_tab(int *tab, int size);
void ft_sort_int_tab(int *tab, int size);


void sep(int i){
	printf("\nex 0%d ----------------------------------\n",i);
}

int main(void)
{

	sep(0);
	int t1;

	t1 = 0;
	ft_ft(&t1);
	printf("%d\n",t1);

	sep(1);
	int t2 = 0;
	int *tt1 = &t2;
	int **tt2 = &tt1;
	int ***tt3 = &tt2;
	int ****tt4 = &tt3;
	int *****tt5 = &tt4;
	int ******tt6 = &tt5;
	int *******tt7 = &tt6;
	int ********tt8 = &tt7;

 	ft_ultimate_ft(&tt8);
	printf("%d\n",t2);

	sep(2);
	int sw1 = 10;
	int sw2 = 20;
	printf("%d %d\n",sw1,sw2);
	ft_swap(&sw1,&sw2);
	printf("%d %d\n",sw1,sw2);
	sep(3);

	int a = 15;
	int b = 7;
	int div = 0;
	int mod = 0;

	ft_div_mod(a,b,&div,&mod);

	printf("%d %d\n",div,mod);
	sep(4);

	int ua = 15;
	int ub = 7;

	ft_ultimate_div_mod(&ua,&ub);
	printf("%d %d\n",ua,ub);

	sep(5);

	ft_putstr("Hello world\n");
	sep(6);

	printf("%d\n",ft_strlen("Hello"));
	sep(7);

	int tab[6] = {1,2,3,4,5,6};

	ft_rev_int_tab(tab,6);
	int x = 0;
	printf("pair\n");
	while(x < 6){
		printf("%d",tab[x]);
		x++;
	}

	int tab2[5] = {1,2,3,4,5};
	ft_rev_int_tab(tab2,5);
	int x2 = 0;
	printf("\nimpair\n");
	while(x2 < 5){
		printf("%d",tab2[x2]);
		x2++;
	}

	int tabl[100];
	for(int i = 0; i < 100; i++){
		tabl[i] = i;
	}
	printf("\nlong\n");
	ft_rev_int_tab(tabl,100);	
	for(int i = 0; i < 100; i++){
		printf("%d ",tabl[i]);
	}
	sep(8);

	int tab3 [5] = {1,5,2,7,0};
	ft_sort_int_tab(tab3,5);	
	for(int i = 0; i < 5; i++){
		printf("%d ",tab3[i]);
	}
	int randAr[40];
	for(int i = 0; i < 40; i++){
		randAr[i] = rand()%100;
	}
	printf("random\n");
	ft_sort_int_tab(randAr,40);	
	for(int i = 0; i < 40; i++){
		printf("%d ",randAr[i]);
	}
	return 0;
}