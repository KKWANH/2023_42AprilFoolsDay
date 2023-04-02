#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_line(int len) {
	for (int i = 0; i < len + 4; i++)
        printf("*");
	printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        return 0;
    }
		for (int str = 0; str < argc; str++) {
		char **words = malloc((argc-1) * sizeof(char *));
		int word_count = 0;
		for (int i = 1; i < argc; i++) {
			char* token = strtok(argv[i], " ");
			while (token != NULL) {
				words[word_count++] = token;
				token = strtok(NULL, " ");
			}
		}

		int max_length = 0;
		for (int i = 0; i < word_count; i++) {
			int length = strlen(words[i]);
			if (length > max_length) {
				max_length = length;
			}
		}

		print_line(max_length);
		for (int i = 0; i < word_count; i++)
			printf("* %-*s *\n", max_length, words[i]);
		print_line(max_length);

		free(words);
	}

    return 0;
}
