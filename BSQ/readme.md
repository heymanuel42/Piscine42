# BSQ
Super projet
# TODO
> struct coordinates (x,y)

typedef coordinates size;

> struct square (coordinate,size)

- trouver si un point est dans le carre
> struct cases (char,coordinats)

```c
typedef struct s_case{
	char c;
	coordinates c;
} t_case;
/*typedef t_case obstacle;
typedef t_case vide;
typedef t_case remplis;*/
```
* typedef case obstacle
* typedef case vide
* typedef case rempli

> struct map (t_case**, size)

- read_from_file return map
- get next line -> lit jusqu' au prochain \n
- display
- free_map

> typedef square* list
- add -> ajoute deja trie
- ?remove?
- swap
- sort?
- free_list

> calculer la distance entre deux obstacles
