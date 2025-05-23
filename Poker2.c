#include <stdio.h>
#include <ctype.h>

// Define struct and declare variables
struct card {
    int rank;
    int suit;
} hand[5], *cardptr;

// Function Prototypes
void poker(struct card *cSptr, int count[]);
int isStraight(int count[]);
void printInstructions(void);
void displayCard(struct card *hand);
void displaySingleCard(struct card *h, int index);
int valCheck(void);
char suitCheck(void);
int againCheck(void);
int exitCheck(void);

int main() {
    int i, again, exit;
    int count[15] = {0};
    cardptr = hand;

    printInstructions();

    do {
        for (i = 0; i < 15; i++) count[i] = 0;

        for (i = 0; i < 5; i++) {
            printf("\nCard %d:\n", i + 1);
            (cardptr + i)->rank = valCheck();
            (cardptr + i)->suit = suitCheck();   
            count[(cardptr + i)->rank]++;
        }

        displayCard(cardptr);         // structure pointer
        poker(cardptr, count);        // array of structures as pointer

        while (1) {
            again = againCheck();
            if (again == 1) break;
            else {
                exit = exitCheck();
                if (exit == 1) {
                    printf("\nThank you for using the program!\n");
                    return 0;
                }
            }
        }

    } while (1);

    return 0;
}

// Instruction panel
void printInstructions(void) {
    printf("========================================\n");
    printf("        POKER HAND EVALUATOR\n");
    printf("========================================\n");
    printf("Instructions:\n");
    printf("You will enter 5 cards to evaluate your poker hand.\n");
    printf("For each card, you need to enter:\n");
    printf("   - The RANK of the card (1 to 13):\n");
    printf("     1 = Ace, 11 = Jack, 12 = Queen, 13 = King\n\n");
    printf("   - The SUIT of the card:\n");
    printf("     H = Hearts, D = Diamonds, S = Spades, C = Clubs\n\n");
    printf("After entering all 5 cards, your hand will be evaluated.\n");
    printf("You can choose to try again or exit the program.\n\n");
    printf("Possible Results:\n");
    printf(" - Nothing\n - One Pair\n - Two Pairs\n");
    printf(" - Three of a Kind\n - Straight\n - Flush\n");
    printf(" - Full House\n - Four of a Kind\n - Straight Flush\n");
    printf("========================================\n");
}

// Evaluation logic
void poker(struct card *cSptr, int count[]) {
    int i, one = 0, three = 0, four = 0, flush = 1;
    int straight;
    char check_suit = (cSptr + 0)->suit;

    for (i = 0; i < 5; i++) {
        if ((cSptr + i)->suit != check_suit) {
            flush = 0;
            break;
        }
    }

    for (i = 0; i <= 13; i++) {
        if (count[i] == 2) one++;
        else if (count[i] == 3) three++;
        else if (count[i] == 4) four++;
    }

    count[14] = count[1];  // Ace can be low
    straight = isStraight(count);

    if (straight && flush) printf("Straight Flush\n");
    else if (four) printf("Four of a Kind\n");
    else if (three && one) printf("Full House\n");
    else if (flush) printf("Flush\n");
    else if (straight) printf("Straight\n");
    else if (three) printf("Three of a Kind\n");
    else if (one == 2) printf("Two Pairs\n");
    else if (one) printf("One Pair\n");
    else printf("Nothing\n");
}

// Straight checker
int isStraight(int count[]) {
    int i;
    if (count[14] && count[2] && count[3] && count[4] && count[5]) return 1;
    for (i = 1; i <= 10; i++) {
        if (count[i] && count[i + 1] && count[i + 2] && count[i + 3] && count[i + 4])
            return 1;
    }
    return 0;
}

// Card display
void displayCard(struct card *hand) {
    for (int i = 0; i < 5; i++)
        displaySingleCard(hand + i, i);
}

// Single card display
void displaySingleCard(struct card *h, int index) {
    printf("Card %d: %d%c\n", index + 1, h->rank, h->suit);
}

// Input and validation
int valCheck(void) {
    int x;
    char term;
    do {
        printf("\nEnter Rank of Card (1-13): ");
        if (scanf("%d%c", &x, &term) == 2 && term == '\n') {
            if (x >= 1 && x <= 13) return x;
            else printf("Error! Rank must be 1-13.\n");
        } else {
            printf("Error! Enter only a number.\n");
            while ((term = getchar()) != '\n' && term != EOF);
        }
    } while (1);
}

char suitCheck(void) {
    char x, c;
    do {
        printf("Enter a Suit (H, D, S, C): ");
        scanf(" %c", &x);
        while ((c = getchar()) != '\n' && c != EOF);
        if (x == 'H' || x == 'D' || x == 'S' || x == 'C') return x;
        printf("Error! Enter a valid suit (H, D, S, C).\n");
    } while (1);
}

int againCheck(void) {
    int x;
    char c;
    while (1) {
        printf("\nDo you want to try again? 1(Yes)/0(No): ");
        if (scanf("%d", &x) == 1 && (x == 0 || x == 1)) {
            while ((c = getchar()) != '\n' && c != EOF);
            return x;
        }
        printf("Invalid input. Use 1 or 0.\n");
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

int exitCheck(void) {
    int x;
    char c;
    while (1) {
        printf("Are you sure you want to exit? 1(Yes)/0(No): ");
        if (scanf("%d", &x) == 1 && (x == 0 || x == 1)) {
            while ((c = getchar()) != '\n' && c != EOF);
            return x;
        }
        printf("Invalid input. Use 1 or 0.\n");
        while ((c = getchar()) != '\n' && c != EOF);
    }
}
