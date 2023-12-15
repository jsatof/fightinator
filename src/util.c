#include <util.h>

#include <stdio.h>

char *StringBool(bool b) {
	return b ? "true" : "false";
}

void PrintStringArray(const char **s, size_t len) {
	printf("[");
	for (size_t i = 0; i < len; ++i) {
		if (i > 0) {
			printf(", ");
		}
		printf("\"%s\"", s[i]);
	}
	printf("]\n");
}
