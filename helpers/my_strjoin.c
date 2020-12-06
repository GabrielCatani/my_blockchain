#include "../includes/my_blockchain.h"

 
 char *my_strjoin(char *s1, char *s2)
 {
     int i = 0;
     char *result;
 
     result = (char *)malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2)) + 1);
     if (!result || !s1 || !s2)
       return NULL;
 
     while (*s1)
       result[i++] = *s1++;
 
 	while (*s2)
 		result[i++] = *s2++;
 
 	result[i] = '\0';
 
 	return result;
 }