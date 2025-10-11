#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    void setColor(int color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }
#else
    void setColor(int color) { printf("\033[1;%dm", color); }
#endif

int main() {
    int number, guess, tries = 0, maxTries, level;
    srand(time(0));

    setColor(36); // Cyan
    printf("====================================\n");
    printf("🎯  WELCOME TO NUMBER GUESSING GAME 🎯\n");
    printf("====================================\n\n");

    printf("Choose difficulty:\n");
    printf("1. Easy (10 tries)\n");
    printf("2. Medium (7 tries)\n");
    printf("3. Hard (5 tries)\n");
    printf("Enter choice: ");
    scanf("%d", &level);

    switch(level) {
        case 1: maxTries = 10; break;
        case 2: maxTries = 7; break;
        case 3: maxTries = 5; break;
        default: maxTries = 10;
    }

    number = rand() % 100 + 1;

    setColor(33);
    printf("\nI have chosen a number between 1 and 100.\nCan you guess it? 🤔\n\n");

    do {
        setColor(37);
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > number) {
            setColor(31);
            printf("Too high! Try again.\n");
        } else if (guess < number) {
            setColor(34);
            printf("Too low! Try again.\n");
        } else {
            setColor(32);
            printf("🎉 Congratulations! You guessed it in %d tries!\n", tries);
            int score = (maxTries - tries + 1) * 10;
            printf("Your score: %d/100\n", score > 0 ? score : 0);
            break;
        }

        if (tries >= maxTries) {
            setColor(31);
            printf("\n💀 Game Over! The number was %d.\n", number);
            break;
        }
    } while (guess != number);

    setColor(36);
    printf("\nThanks for playing! 👋\n");
    return 0;
}
