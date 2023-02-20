//A program entab that replaces strings of blanks by the minimum number of tabs and blanks to acheive the same spacing.
//Use the same tab stops as for detab. 
//When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

#include <stdio.h>
#include "get_line.h"

#define TABSTOPS 8

void entab(char line[MAXSIZE],char entabbedline[MAXSIZE],int len){
	int i;int no_of_consecutive_spaces = 0;int offset = 0;
	for(i = 0;i < len; ++i){
		if (line[i] == ' '){
			++no_of_consecutive_spaces;
		}
		if (no_of_consecutive_spaces == TABSTOPS){
			i -= no_of_consecutive_spaces;
			entabbedline[i] = '\t';
		}
		else{
			entabbedline[i] = line[i];
		}
	}
}

int main(){
	char line[MAXSIZE];int i;char entabbedline[MAXSIZE];
	while((i = get_line(line)) != -1){
		entab(line,entabbedline,i);
		printf("%s\n",line);
	}
	return 0;
}
