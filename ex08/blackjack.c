#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char* cards = argv[1];
    int sum = 0;
    int aces = 0;

    for (int i = 0; i < strlen(cards); i++) {
        char c = cards[i];

        if (c >= '2' && c <= '9') {
            sum += c - '0';
        } else if (c == 'J' || c == 'Q' || c == 'K') {
            sum += 10;
        } else if (c == 'A') {
            aces++;
            sum += 11;
        }
    }

    while (aces > 0 && sum > 21) {
        sum -= 10;
        aces--;
    }

    if (sum == 21)	printf("Blackjack!\n");
	else			printf("%d\n", sum);

    return 0;
}
