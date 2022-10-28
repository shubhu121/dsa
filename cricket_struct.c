#include <stdio.h>
#include <conio.h>

// Declaration of structure name cricket
struct cricket
{

    // Declaration of structure member variables
    char player_name[30], team_name[30];
    int bat_avg;
} player[50];

void main()
{
    int i, n;

    // To store information of as much players as much required
    printf("\nEnter the number of players you want to include:");
    scanf("%d", &n);

    // To store information of players
    printf("\nEnter the following information related to players");
    for (i = 0; i < n; i++)
    {
        printf("\nPlayer %d Name:", i + 1);
        scanf("%s", &player[i].player_name);
        printf("\nTeam Name:");
        scanf("%s", &player[i].team_name);
        printf("\nBatting average:");
        scanf("%d", &player[i].bat_avg);
    }

    // To print information of players
    printf("\nEntered Information:");
    printf("\n|| S.No. ||  Player Name      ||    Team Name    ||   Batting Average  ||");
    for (i = 0; i < n; i++)
        printf("\n||  %d    ||          %s             ||       %s        ||          %d     ||", i + 1, player[i].player_name, player[i].team_name, player[i].bat_avg);
    getch();
}