//A program entab that replaces strings of blanks by the minimum number of tabs and blanks to acheive the same spacing.
//Use the same tab stops as for detab. 
//When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

#include <stdio.h>
#include "get_line.h"

#define TABSTOPS 8

void entab(char line[MAXSIZE],char entabbedline[MAXSIZE],int len){
	int i,j; j = i = 0;int concurrent_spaces = 0;
	while(i < len){
    if(line[i] == ' '){
      ++concurrent_spaces;
    }
    if(concurrent_spaces > TABSTOPS){
      entabbedline[j] == '\t';
    }
    else{
      concurrent_spaces = 0;
      entabbedline[j] = line[i];
    }
    ++i; ++j;
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
