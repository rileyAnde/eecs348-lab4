#include <stdio.h>

void findCombinations(int score) {
    printf("possible combinations of scoring plays if a team’s score is %d:\n", score);
    for (int td2pt = 0; td2pt <= score / 8; td2pt++) {
        for (int td1pt = 0; td1pt <= (score - td2pt * 8) / 7; td1pt++) {
            for (int td = 0; td <= (score - td2pt * 8 - td1pt * 7) / 6; td++) {
                for (int fg = 0; fg <= (score - td2pt * 8 - td1pt * 7 - td * 6) / 3; fg++) {
                    int remaining = score - (td2pt * 8 + td1pt * 7 + td * 6 + fg * 3);
                    if (remaining % 2 == 0) {
                        int safety = remaining / 2;
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, td1pt, td, fg, safety);
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        findCombinations(score);
    }
    return 0;
}

