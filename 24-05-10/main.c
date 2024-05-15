#include <stdio.h>
#include <string.h>

int main() {
	char str[20] = "etstlk-sflskf";
	scanf("%s", str);
	printf("%s\n", str);
	const char de[2] = "-";
	char* token;
	
	token = strtok(str, de);
	while (token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, de);
	}

	return 0;
}
