//A program entab that replaces strings of blanks by the minimum number of tabs and blanks to acheive the same spacing.
//Use the same tab stops as for detab. 
//When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

#include <stdio.h>
#include "get_line.h"

#define TABSTOPS 8

void entab(char line[MAXSIZE],char entabbedline[MAXSIZE],int len){
  int i,j; i = j = 0;
  int consecutive_spaces = 0;
  while(i < len && j < len){
    if(line[i] == ' '){// count the number of consecutive spaces
      consecutive_spaces++;
      ++i;
    }
    if(consecutive_spaces >= TABSTOPS){//if consecutive spaces are greater than the number of TABSTOPS then replace with tab
      j -= consecutive_spaces;
      printf("hello I am being executed\n");
      entabbedline[j] = 'l';
      ++j;
    }
    else{
      consecutive_spaces = 0;
      entabbedline[j] = line[i];
      ++j; ++i;
    }
    printf("(%d,%d,%d)\n",i,j,consecutive_spaces);
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
