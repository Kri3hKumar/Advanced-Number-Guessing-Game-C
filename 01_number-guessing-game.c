#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int invalid_difficulty(int num)
{
    if (num > 4 || num < 1)
    {
        printf("Invalid Difficulty..\nPlease enter again..\n");
        printf("\n\n");
        return 0;
    }
    return 1;
}

void guess_feedback(int random, int guess)
{
    int diff = abs(guess - random);
    if (diff >= 1 && diff <= 3)
    {
        printf("So close! You're almost there!\n\n");
    }
    else if (diff > 3 && diff <= 7)
    {
        printf("Very close...\n\n");
    }
    else if (diff > 7 && diff <= 15)
    {
        printf("Not bad! Keep going\n\n");
    }
    else if (diff > 15 && diff <= 25)
    {
        printf("You're getting warmer\n\n");
    }
    else if (diff > 25 && diff <= 40)
    {
        printf("You're quite far\n\n");
    }
    else if (diff > 40 && diff <= 60)
    {
        printf("Cold... very cold\n\n");
    }
    else if (diff > 60)
    {
        printf("You should give up... just kidding\n\n");
    }
}
void out_of_range(int guess, int diff)
{
    if (diff == 1 && (guess > 50 || guess < 1))
    {
        printf("Out of range...\n\n");
    }
    else if (diff == 2 && (guess > 100 || guess < 1))
    {
        printf("Out of range...\n\n");
    }
    else if (diff == 3 && (guess > 500 || guess < 1))
    {
        printf("Out of range...\n\n");
    }
    else if (diff == 4 && (guess > 500 || guess < 1))
    {
        printf("Out of range...\n\n");
    }
}
int main(int argc, char const *argv[])
{
    int random, guess;
    int no_guess;
    int difficulty;
    int play_again;
    int chance_left;
    srand(time(NULL));
start:
    no_guess = 0;
    chance_left = 10;

    printf("Welcome to the world of guessing numbers\n");
    printf("Choose Difficulty\n1. Easy(1-50)\n2. Medium(1-100)\n3. Hard(1-500)\n4. Insanity(Limited attempts + (1-500)\n");
    scanf("%d", &difficulty);

    // Invalid Dificulty:
    if (invalid_difficulty(difficulty) == 0)
    {
        goto start;
    }

    if (difficulty == 1)
    {

        random = rand() % 50 + 1;
        printf("Guess a number between 1 and 50.\n");
    }
    else if (difficulty == 2)
    {
        random = rand() % 100 + 1;
        printf("Guess a number between 1 and 100.\n");
    }
    else if (difficulty == 3)
    {
        random = rand() % 500 + 1;
        printf("Guess a number between 1 and 500.\n");
    }

    // This is for insanity
    else
    {
        random = rand() % 500 + 1;
        printf("Guess a number between 1 and 500. But this time you have only 10 chances\n");
        do
        {
            if (chance_left == 0)
            {
                printf("\n\n");
                printf("Sorry! You lost!!..\nBetter luck next time\n");
                printf("The correct number was %d",random);
                printf("\n\n");

                break;
            }

            scanf("%d", &guess);
            out_of_range(guess,difficulty);
            guess_feedback(random, guess);

            chance_left--;
            printf("%d chances left..\n", chance_left);
            no_guess++;
            if (guess < random)
            {
                printf("Larger number please...\n");
            }
            else if (guess > random)
            {
                printf("Smaller number please...\n");
            }
            else
            {
                printf("Congratulations!!! You have successfully guessed the number in %d attempts\n", no_guess);
            }

        } while (guess != random);

        printf("Do you want to play this game again?\nPress 1 for yes!!, 2 for no!!\n");
        scanf("%d", &play_again);
        if (play_again == 1)
        {
            goto start;
        }
        else
        {
            goto end;
        }
    }

    do
    {
        scanf("%d", &guess);
        out_of_range(guess,difficulty);
        guess_feedback(random, guess);

        no_guess++;
        if (guess < random)
        {
            printf("Larger number please...\n");
        }
        else if (guess > random)
        {
            printf("Smaller number please...\n");
        }
        else
        {
            printf("Congratulations!!! You have successfully guessed the number in %d attempts\n", no_guess);
            printf("Do you want to play this game again?\nPress 1 for yes!!, 2 for no!!\n");
            scanf("%d", &play_again);
            if (play_again == 1)
            {
                goto start;
            }
            else
            {
                goto end;
            }
        }

    } while (guess != random);

end:
    printf("Thanks for playing\n");
    return 0;
}
