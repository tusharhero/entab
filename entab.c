//A program entab that replaces strings of blanks by the minimum number of tabs and blanks to acheive the same spacing.
//Use the same tab stops as for detab. 
//When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

#include <stdio.h>
#include "get_line.h"

#define TABSTOPS 8

void entab(char line[MAXSIZE],char entabbedline[MAXSIZE],int len){
  int i,j,k; i = j = k = 0;
  int spaces = 0;
  while(i < len && j < len){
    for(k = j;k < len && k < TABSTOPS;k++){
      if (line[k] == ' '){
        spaces++;
      }
    }
    if (TABSTOPS == spaces){
      entabbedline[j] = '\t';
      i += k;++j;
    }
    else{
      entabbedline[j] = line[i];
      ++i;++j;
    }
  }
  entabbedline[j] = 0;
}

int main(){
	char line[MAXSIZE];int i;char entabbedline[MAXSIZE];
	while((i = get_line(line)) != -1){
		entab(line,entabbedline,i);
		printf("%s\n",entabbedline);
	}
	return 0;
}
