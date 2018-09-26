#include <stdio.h>
#define LONGLINE 30
#define MAXLINE 1000

void fold(char l[],int m);
int getLine(char l[],int m);

int main(){
	char line[MAXLINE];
	int len;
	while ((len = getLine(line,MAXLINE)) > 0){
		fold(line,len);
		printf("%s",line);
	}
}

int getLine(char line[], int max){
	int c,i;
	for (i = 0;i < max - 1 && (c = getchar()) != EOF && c != '\n';++i)
		line[i] = c;
	if (c == '\n'){
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void fold(char line[], int len){	
	if (len > LONGLINE){	
		int ccounter = LONGLINE - 1;
		int lcounter = 0;
		int temp;
		while (ccounter < len){
			temp = line[ccounter];
			if ( temp == ' ' || temp == '\t'){
				line[ccounter] = '\n';
				lcounter = ccounter;
				ccounter = ccounter + LONGLINE - 1;
			}else
				--ccounter;
			if (ccounter == lcounter)
				ccounter = len;	
 		}
	}	
}
