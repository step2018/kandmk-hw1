#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 16
#define N 256

void mojisort(char *h){
  int i, j;
  char a;
  for(i=0; h[i] != 0; i++){
    for(j=i+1; h[j] != 0; j++){
      if(h[i]>h[j]){
	a = h[i];
	h[i] = h[j];
	h[j] = a;
      }
    }
  }
}
	

/*void compare(char *s,char *t){
  if(memcmp(s, t, 16)==0){
    return s;
  }
}
*/
int main(void){
  char t[17];
  FILE *fp;
  char *fname = "dictionary.txt";
  char *fname_cpy = "dictinary.txt";
  char s[N];
  scanf("%s", t);
  int len = strlen(t);
  t[len] = \n;
  mojisort ( fp = fopen(fname, "r");
  if(fp == NULL){
    printf("%s error\n", fname);
    return -1;
  }
  while(fgets(s, N, fp) != NULL){
    mojisort(s);
    if(!strcmp(s, t)){
      printf("%s ", s);
    }
  }
  fclose(fp);
  return 0;
}
