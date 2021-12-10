/*
** ETNA PROJECT, 05/11/2021 by Anthony LECLERCQ
** [...]
** File description:
**      [...]
*/


int my_strlen(const char *str)
{
    int i;
    i=0;
    while (str[i] != '\0')
        {
            i=i+1;
        }
    return i;

}


char *my_strcat_n(char *dest, const char *src, int n)
{

    int i;
    int j;
    i=0;
    j=my_strlen(dest);

    while(src[i] != '\0' && i <= n)
    dest[j++] = src[i++];


    dest[j] = '\0';

    return dest;

}

char *my_strcat(char *dest, const char *src)
{

    int i;
    int j;
    i=0;
    j=my_strlen(dest);

    while(src[i] != '\0')
    dest[j++] = src[i++];


    dest[j] = '\0';

    return dest;

}
