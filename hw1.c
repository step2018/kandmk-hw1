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
  char s[17], p[17];
  int sum = 0;
  scanf("%s", t);
  mojisort(t);
  fp = fopen(fname, "r");
  if(fp == NULL){
    printf("%s error\n", fname);
    return -1;
  }
  while(fgets(s, 16, fp) != NULL){ // fgetsは指定した16個まで文字を入力するけど、その後'\0'を加えるので、17個分のcharのメモリーが必要です。
    strcpy(p, s);
    if(strlen(s)<16 || s[15] == '\n'){
      s[strlen(s)-1] = '\0';
    }
    mojisort(s);
    if(strncmp(t, s, strlen(t))==0){  // ここは多分思った通りにうごいていないです（例えば「lampe」を入れると「maple」も「samples」も出ています。
      printf("%s", p);
    }
  }
  fclose(fp);
  return 0;
}
