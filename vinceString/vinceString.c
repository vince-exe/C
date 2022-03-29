#include <stdio.h>

#include "vinceString.h"

int strlen_(const char* string) {
	int i = 0;
	const char *p = string;

	while(*p != '\0') {
		p += 1;
		i += 1;
	}
	return i;
}
    
int strcmpy_(char* string1, char* string2) {
    char *p1 = string1, *p2 = string2;
    int cnt = 0;

    while(*p1 != '\0' && *p2 != '\0') {
        if(*p1 == *p2) {
            cnt++;
        }
        p1+=1;
        p2+=1;
    }

    if(cnt == strlen_(string1))
        return 1;
    return 0;
}

int strcpy_(char* dest, char* src) {
    char *p1 = dest, *p2 = src;
    int i;

    for(i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    dest[i] = '\0';

    dest = p1;
    src = p2;

    return i;
}

char* strsrc_(char* src, char c) {
    char *p = src;

	while(*p != '\0') {
		if(*p == c) {
			return p;
		}
		p+=1;
	}
    
	return NULL;
}

int ischar_(char* string, char c) {
    char *p = string;
    while(*p != '\0') {
        if(*p == c) {
            return 1;
        }
        p+=1;
    }
    return 0;
}

int cntchar_(char* string, const char* c) {
    int cnt = 0;
    char *p = string;
    const char *c1 = c;

    while(*p != '\0') {
        if(*p == *c) {
            cnt++;
        }
        p+=1;
    }
    return cnt;
}

int isString(char* dest, const char* src) {
    char *p1 = dest;
    const char *p2 = src;

    int cnt;
    while(*p1 != '\0') {
        cnt = 0;
        while(*p1 == *p2) {
            cnt += 1;

            if(cnt == strlen_(src))  {
                return 1;
            }
            p1+=1;
            p2+=1;
        }
        p2 = src;
        p1+=1;
    }
    return 0;
}

int readString(char* string, int buffer) {
    int i = 0;
    char c;

    while((c = getchar()) != '\n') {
        if(i < buffer) {
            string[i] = c;
            i++;
        }
    }
    string[i] = '\0';

    return i;
}

char* strct_(char* dest, char* src) {
    char *p1 = dest, *p2 = src;

    char* tmp = &dest[strlen_(dest)];
    
    while(*p2 != '\0') {
        *tmp = *p2;
        tmp+=1;
        p2+=1;
    }

    *tmp = '\0';
    dest = p1;

    return dest;
}

char* strct2_(char* dest, char* src) {
    char* nw = malloc((strlen_(dest) - 1) + (strlen_(src) - 1) + 1);
    strcpy_(nw, dest);
    strcpy_(&nw[strlen_(nw)], src);

    nw[strlen_(nw)] = '\0';

    return nw;
}

char* strnset_(char* string, const char* sm, int count) {
    char* p = string;
    int i = 0;

    while(*p != '\0' && i < count) {
        *p = *sm;
        i++;
        p+=1;
    }
    
    return string;
}

char* strset_(char* string, const char* sm) {
    char *p = string;
    while(*p != '\0') {
        *p = *sm;
        p+=1;
    }

    return string;
}

char* strset1_(char* string, const char* sm, int start, int count) {
    char* p = &string[start];
    int i = 0;

    while(*p != '\0' && i < count) {
        *p = *sm;
        p+=1;
        i++;
    }

    return string;
}

char* strrev_(char* string) {
    int i;
    char c;
    for(i = 0; i < (strlen_(string) - i) - 1; i++) {
        c = string[i];
        string[i] = string[(strlen_(string) - i) - 1];
        string[(strlen_(string) - i) - 1] = c;
    }

    return string;
}