/*
** ETNA PROJECT, 05/11/2021 by Anthony LECLERCQ 
** [...]
** File description:
**      [...]
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "my_crd.h"



linked_list_t *add_keyval(char *k, char *v, linked_list_t *list)
{
    //si ma liste est nulle alors je le créer 
    if(list == NULL)
        {
            linked_list_t *new = malloc(sizeof(linked_list_t));
            new->key = k;
            new->value = v;
            new->next = NULL;
            
            list = new;
            printf("%s\n", list->key);
            return list;
        }
    linked_list_t *first = list;
    
    while(list != NULL)
    
        {

            if(my_strcmp(list->key, k) == 0) //if key exist !! les comparer avec my_str_cmp                                  
                {
                    //maj value                                                                                                                              
                    list->value = v;
                 
                    printf("%s\n", k);
                    return first;
                }
            
            list = list->next;
        }


    //else created            
                                                                                                                      
    linked_list_t *new = malloc(sizeof(linked_list_t));
    new->key = k;
    new->value = v;
    new->next = NULL;


    
    //sinon, je rajoute new à la fin
    list = new;

   
    printf("%s\n", k);
    return first;
    
}




//Je n'ai pas trouvé comment retourner quelque chose que l'on supprime
//mais on peut l'afficher avan de le supprimer
void del_keyval(char *k, linked_list_t **list_val)
{

    int cpt = 0;
    
    linked_list_t *l = *list_val;

       
    while(l != NULL)
        {
            //si la clé qu'on veut supprimer est égale à la clé dans la liste (qu'elle existe)
            if(my_strcmp(l->key, k) == 0)
                {

                    printf("%s", (*list_val)->value);
                    *list_val = l->next;
                    cpt = cpt+1;
                            
                }
                        
            l = l->next;
        }
    
    if(cpt == 0)
        printf("-1\n");
}



char* find_keyval(char *k, linked_list_t *list)
{


    while(list != NULL)
        {
            if(my_strcmp(list->key, k) == 0)
                {
                    printf("%s", list->value);
                    return (list->value);
                }

            list = list->next;
        }

    
    printf("-1\n");
    
    return NULL;

}




linked_list_t *parse(char *list, linked_list_t *my_list)
{

    //parse une ligne
    
    char *key = malloc(sizeof(char) * (50 + 1));
    char *value = malloc(sizeof(char) * (50 + 1));

    
    int i = 0;
    
    //key
    while((list[i] != ' ') && (list[i] != '\n')) 
        {
            
            key = my_strcat_n(key, &list[i], 0);
            i = i + 1;           
        }
    
    

    if(list[i] == '\n')
        {
            //no value
                       
            value = NULL;
           
        }
    
    else
        {
            
            //value
            while(list[i] != '\n')
                {
                    
                    i = i + 1;
                    value = my_strcat_n(value, &list[i], 0);
                                        
                }
            
            //printf("key : %s val : %s", key, value);

        }


    

    if(value == NULL)
        {
            //find_node                                                                                                                                                    
            find_keyval(key, my_list);
        }

    
    
    else if(value[0] >= 48 && value[0] <= 57) //si la première valeur est un chiffre entre 0 et 9
        {

            
            //add key_value
            my_list = add_keyval(key, value, my_list); //renvoie un char*
            
        }

    else if(value[0] == 'D') //si D
        {
          
            del_keyval(key, &my_list);
            
        }
    
   
       
    return my_list;
}



void my_main_fonction(void)
{
  int i = 0, error;
  
  char *catline = malloc(sizeof(char) * (50 + 1));
  char *buff = malloc(sizeof(char) * (50 + 1)); //alloue de la mémoire pour stocker la ligne (max 50 carac)

  
  linked_list_t *list = NULL;
  
  

  //test : si NULL, y'a R à lire
  if (buff == NULL)
      printf("NULL");


  
  //read until EOF line by line
  while ((error = read(0, buff, 1)) > 0)
      {
                    
          if(buff[i] == '\n')
              {                  
                  //ici je vais faire le pars des keys/values                  
                  catline = my_strcat(catline, buff); //rajout \n
                  list = parse(catline, list);  
                  catline = malloc(sizeof(char*) * (50 + 1));
              }

          else
              {
                  catline = my_strcat(catline, buff);
              }
      }

  
  
  
  free(catline);
  free(buff);
}
