#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "flag.h"

int main() {
	puts("Want to look at my array?");
	static char vals[] = {1,2,3,4};
	for(int i=0;i<4;i++) {
		printf("%d ", vals[i]);
	}
	printf("\n");
	puts("Since you seem nice, you can even change one of the values");
	int index;
	char value;
	scanf("%d", &index);
	scanf("%hhd", &value);
	vals[index] = value;
	puts("I'll give you the flag now");
	char* string = get_flag_v1();
	printf("%s", string);
	return 0;
}

