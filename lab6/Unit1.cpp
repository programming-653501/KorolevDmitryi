#include <tchar.h>
#include <stdlib.h>
#include <ctype.h>
#include "Unit1.h"

inline char toupper(char s){
	if(s>-33&&s<0){
		return (char)(s-32);
	}
	if(s>=97&&s<=122){
		return (char)(s-32);
	}
	return s;
}

int compare(char *a, char *b){
	int i=0;
	while(a[i]==b[i]&&i<strlen(a)&&i<strlen(b)){
		i++;
		}
	if(a[i]>b[i]||(strlen(a)>strlen(b)&&b[i]==a[i])){
		return 1;
	}
	if(a[i]<b[i]||(strlen(a)<strlen(b)&&b[i]==a[i])){
		return -1;
	}
	return 0;
}

bool nice(char *s){
	if(strlen(s)==0){
		return false;
	}
	if(s[0]==s[strlen(s)-1]){
		return true;
	}
	return false;
}
