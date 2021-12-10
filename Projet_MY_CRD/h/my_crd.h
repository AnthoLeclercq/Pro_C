/*
** ETNA PROJECT, 05/11/2021 by Anthony LECLERCQ
** [...]
** File description:
**      [...]
*/

#ifndef MyCrd_H
#define MyCrd_H





typedef struct linked_list
{
    char *key;
    char *value;
    struct linked_list *next; //next link

} linked_list_t;





linked_list_t *add_keyval(char *k, char *v, linked_list_t *list);
void del_keyval(char *k, linked_list_t **list_val);
char* find_keyval(char *k, linked_list_t *list);
linked_list_t *parse(char *list, linked_list_t *my_list);
void my_main_fonction(void);


int my_strlen(const char *str);
char *my_strcat_n(char *dest, const char *src, int n);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);



#endif
