#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum
{
    ROCK,
    PAPER,
    SCISSORS
} GameChoices;
const char *choiceNames[] = {"ROCK", "PAPER", "SCISSORS"};

GameChoices getPlayerChose(char *input)
{
    if (strcmp(input, "ROCK") == 0)
    {
        return ROCK;
    }
    else if (strcmp(input, "SCISSORS") == 0)
    {
        return SCISSORS;
    }
    else if (strcmp(input, "PAPER") == 0)
    {
        return PAPER;
    }
    else
    {
        printf("Invalid choice! Please choose ROCK, PAPER or SCISSORS.\n");
        exit(1);
    }
}

void determineWinner(GameChoices playerChose, GameChoices computerChose)
{
    if (playerChose == computerChose)
    {
        printf("Its a tie. \n");
    }
    else if ((playerChose == ROCK && computerChose == SCISSORS) || (playerChose == PAPER && computerChose == ROCK) || (playerChose == SCISSORS && computerChose == PAPER))
    {
        printf("Player wins. \n");
    }
    else
    {
        printf("Computer wins.\n");
    }
}

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        printf("Usage: %s < ROCK | PAPER | SCISSORS >\n", argv[0]);
        return 1;
    }

    GameChoices playerChose = getPlayerChose(argv[1]);

    srand(time(NULL));

    GameChoices computerChose = rand() % 3;

    printf("Player chose %s.\n", choiceNames[playerChose]);
    printf("Computer chose %s.\n", choiceNames[computerChose]);

    determineWinner(playerChose, computerChose);

    return 0;
}
