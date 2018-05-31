#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 16

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
	
int main(void){
  char t[17];
  FILE *fp;
  char *fname = "dictionary.txt";
  char s[16], p[16];
  scanf("%s", t);
  mojisort(t);
  fp = fopen(fname, "r");
  if(fp == NULL){
    printf("%s error\n", fname);
    return -1;
  }
  while(fgets(s, 17, fp) != NULL){
    strtok(s, "\n\0");
    strcpy(p, s);
    mojisort(s);
    if(!strcmp(t, s)){
      printf("%s", p);
    }
  }
  fclose(fp);
  return 0;
}
