/*
Given an integer representing a score in a National Football League (NFL) game, write a program
to determine all possible combinations of scoring plays that can result in that score.
A scoring plays in an NFL game can be the following:
• Touchdown (TD) worth 6 points
• Field goal (FG) worth 3 points
• Safety worth 2 points
• Touchdown (TD) + 2-point conversion worth 8 points
• Touchdown (TD) + 1-point field goal worth 7 points
The program should continue to prompt the user for a score until a value less than or equal to
1 is entered, at which point the program should terminate. For each score entered, the program
should display all possible combinations of scoring plays that result in that score.
*/

#include <stdio.h>

// Function to calculate and print all possible combinations of scoring plays
void generateScoreCombinations(int score) {
     for (int touchdowns = 0; touchdowns <= score / 6; ++touchdowns) {
        for (int fieldGoals = 0; fieldGoals <= score / 3; ++fieldGoals) {
            for (int safeties = 0; safeties <= score / 2; ++safeties) {
                for (int touchdowns_2 = 0; touchdowns_2 <= touchdowns; ++touchdowns_2) {
                    for (int touchdowns_1 = 0; touchdowns_1 <= touchdowns - touchdowns_2; ++touchdowns_1) {
                        if (6 * touchdowns + 3 * fieldGoals + 2 * safeties + 8 * touchdowns_2 + 7 * touchdowns_1 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   touchdowns_2, touchdowns_1, touchdowns - touchdowns_2 - touchdowns_1, fieldGoals, safeties);
                        }
                    }
                }
            }
        }
    }

    printf("\n");
}

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("Program terminated.\n");
            break;
        }

        generateScoreCombinations(score);
    }

    return 0;
}
