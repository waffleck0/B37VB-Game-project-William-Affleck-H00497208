#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

typedef struct {
    int rank;
    int suit;
} Card;

void createDeck(Card deck[]) {
    int index = 0;
    for (int s = 0; s < 4; s++) {
        for (int r = 2; r <= 14; r++) {
            deck[index].rank = r;
            deck[index].suit = s;
            index++;
        }
    }
}

void shuffle(Card deck[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

const char* rankName(int r) {
    static char buf[3];
    switch (r) {
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        case 14: return "A";
        default:
            sprintf(buf, "%d", r);
            return buf;
    }
}

const char* suitName(int s) {
    switch (s) {
        case 0: return "S"; // Spades
        case 1: return "H"; // Hearts
        case 2: return "D"; // Diamonds
        case 3: return "C";  // Clubs
        default: return "?";
    }
}


void printCard(Card c) {
    const char* colour = (c.suit == 1 || c.suit == 2) ? RED : WHITE;
    printf("%s%s%s%s", colour, rankName(c.rank), suitName(c.suit), RESET);
}

int war(Card deck[], int *index) {
    printf(YELLOW "\nWAR! Cards are equal!\n" RESET);

    int cardsUsed = 2; // initial two cards

    while (1) {
        if (*index + 4 >= 52) {
            printf(RED "Not enough cards left for full war.\n" RESET);
            return 0;
        }

        *index += 3; // skip 3 face-down cards
        cardsUsed += 3;

        Card p = deck[*index];
        Card c = deck[*index + 1];
        cardsUsed += 2;

        printf("War draw -> You: ");
        printCard(p);
        printf(" | Enemy: ");
        printCard(c);
        printf("\n");

        if (p.rank > c.rank) {
            printf(GREEN "Player wins the war!\n" RESET);
            return 1;
        } else if (c.rank > p.rank) {
            printf(RED "The enemy wins the war!\n" RESET);
            return -1;
        }

        printf(YELLOW "Another tie! War continues...\n" RESET);
        *index += 2;
    }
}

int main() {
    srand(time(NULL));

    Card deck[52];
    createDeck(deck);
    shuffle(deck, 52);

    int playerScore = 0;
    int cpuScore = 0;

    printf("=== WAR CARD GAME ===\n\n");

    int round = 0;

    for (int i = 0; i < 52; i += 2) {
        round++;

        // Special 26th round
        if (round == 26) {
            printf(YELLOW "\n=== FINAL SPECIAL BOSS FIGHT ===\n" RESET);
        }

        Card p = deck[i];
        Card c = deck[i + 1];

        printf("\nRound %d\nYou: ", round);
        printCard(p);
        printf(" | Enemy: ");
        printCard(c);

        if (round == 26) {
    // FINAL ROUND BONUS
    if (p.rank > c.rank) {
        printf(GREEN "  -> You wins FINAL Battle (+3)\n" RESET);
        playerScore += 3;
    } else if (c.rank > p.rank) {
        printf(RED "  -> Enemy wins FINAL Battle (+3)\n" RESET);
        cpuScore += 3;
    } else {
        printf(YELLOW "  -> Tie on final Battle (no bonus)\n" RESET);
    }
} else {
    // NORMAL ROUNDS
    if (p.rank > c.rank) {
        printf(GREEN "  -> You wins\n" RESET);
        playerScore++;
    } else if (c.rank > p.rank) {
        printf(RED "  -> Enemy wins\n" RESET);
        cpuScore++;
    }
}


        // Pause every 5 rounds for the player to press enter to take their next turn
        if (round % 5 == 0 && round != 26) {
            printf("\nPress ENTER to continue...");
            getchar();
        }
    }

    printf("\n=== FINAL SCORE ===\n");
    printf("You: %d\nEnemy: %d\n", playerScore, cpuScore);

    if (playerScore > cpuScore) printf(GREEN "You have won the war!\n" RESET);
    else if (cpuScore > playerScore) printf(RED "Enemy wins the war!\n" RESET);
    else printf(YELLOW "It's a tie!\n" RESET);

    return 0;
}

