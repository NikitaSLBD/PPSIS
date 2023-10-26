#include "TicTacToe.hpp"
#include <stdio.h>

using namespace std;

int main()
{
    
    int x,y;
    char play = ' ';

    printf("\t\t\tTic Tac Toe!\nMain menu\n\t\t\tStart(s)\n\t\t\tExit(e)\nYour decision: ");
    scanf_s("%c", &play);

    while ((play != 'S' && play != 's') && (play != 'E' && play != 'e')) 
    {
        rewind(stdin);
        printf("\nInvalid input. Please try again: ");
        scanf_s("%c", &play);
        
    }
    
    while (play == 'S' || play == 's')
    {
        TicTacToe Game;

        do
        {

            printf("\n%s %d %s", "Player", Game.get_player(), "turn: ");

            while (!scanf_s("%d %d", &x, &y) || (x > 3 || x <= 0) || (y > 3 || y < 0))
            {
                rewind(stdin);
                printf("\nInvalid input. Please try again: ");
            }

            try
            {
                Game[3 * (x - 1) + y - 1];
            }

            catch (...)
            {
                printf("\nThis cell is filled! Your turn goes to another player!\n");
                continue;
            }


            for (int i = 0; i < 8; i += 3)
            {
                printf("\n\t\t%c %c %c", Game.get_content(i), Game.get_content(i + 1), Game.get_content(i + 2));
            }

            Game.switch_player();

            printf("\n");

        } while (!Game.is_win() && !Game.is_dry());

        if (Game.is_win())
        {
            printf("\n%s %d %s", "Player", Game.get_player(), "wins!");
        }
        else
        {
            printf("\n%s\n", "This is dry!");
        }

        play = ' ';

        printf("\n\t\t\tRestart (s)\n\t\t\tExit (e)\nYour decision: ");
        rewind(stdin);

        scanf_s("%c", &play);

        while ((play != 'S' && play != 's') && (play != 'E' && play != 'e'))
        {
            rewind(stdin);
            printf("\nInvalid input. Please try again: ");
            scanf_s("%c", &play);
        }
    }

    return 0;
}
