

#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstdlib>
using namespace std;

short randnum(int from, int to)
{
    return rand() % (to - from + 1) + from;
}
short readnum(string massege,short time)
{
    short num;
    do
    {
        cout << massege;
        cin >> num;
    } while (num > time || num <= 0);
    return num;
}
enum enpl{Rock=1 , Paper=2 ,Scissor=3};
struct stall
{
    enpl user;
    enpl comp;
    int plcount;
    int compcount;
    int drawcount;
};
enpl choice(short num)
{
    return (enpl)num;
}
void printchoice(short num)
{
    if (num == 1)
        cout << "Rock";
    else if (num == 2)
        cout << "Paper";
    else if (num == 3)
        cout << "Scissor";
}
bool whowins(stall en)
{
    if (en.user == Rock)
    {
        if (en.comp == Paper)
        {
            return false;
        }
        if (en.comp == Scissor)
        {
            return true;
        }
    }
    else if (en.user == Paper)
    {
        if (en.comp == Rock)
        {
            return true;
        }
        if (en.comp == Scissor)
        {
            return false;
        }
    }
    else if (en.user == Scissor)
    {
        if (en.comp == Rock)
        {
            return false;
        }
        if (en.comp == Paper)
        {

            return true;
        }
    }
    return false;
}
void printwinner(stall en)
{
    if (en.comp == en.user)
    {
        cout << "No Winner";
        system("color 6f");
    }
    else if (whowins(en) == true)
    {
        cout << "Player1";
        system("color 2f");
    }
    else
    {
        cout << "Computer\a";
        system("color 4f");

    }
}
string finalwinner(stall en)
{
    if (en.compcount > en.plcount)
    {
        system("color 4f");
        return "Computer\a";
    }
    else if (en.plcount > en.compcount)
    {
        system("color 2f");
        return "Player1";
    }
    else if (en.compcount==en.plcount)
    {
        system("color 6f");
        return "No One";
    }
}
bool gameover(stall all, short rounds)
{
    cout << "\n"
    <<string(20, ' ');
    for (int i = 0; i < 50; i++)
    {
        cout << "_";
    }
    cout << "\n"
    <<string(32, ' ')
    << "+++  G a m e  O v e r  +++\n"
    <<string(20, ' ');
    for (int i = 0; i < 50; i++)
    {
        cout << "_";
    }
    cout << "\n"
    <<string(20, ' ');
    for (int i = 0; i < 17; i++)
    {
        cout << "_";
    }
    cout << " [Game Over] ";
    for (int i = 0; i < 20; i++)
    {
        cout << "_";
    }
    cout << "\n"
    <<string(20, ' ')
    << "Game Rounds             :" << rounds << "\n"
    << string(20, ' ')
    << "Player1 won times       :" << all.plcount << "\n"
    <<string(20, ' ')
    << "Computer won times      :" << all.compcount << "\n"
    <<string(20, ' ')
    << "Draw times              :" <<all.drawcount <<"\n"
    <<string(20, ' ')
    << "Final winner            :" << finalwinner(all) << "\n"
    <<string(20, ' ');
    for (int i = 0; i < 50; i++)
    {
        cout << "_";
    }
    cout << "\n";
    char yorn;
    cout <<string(20, ' ');
    cout << "Do you want to play again? Y/N? ";
    cin >> yorn;
    if (yorn == 'Y' || yorn == 'y')
        return true;
    else if (yorn == 'N' || yorn == 'n')
        return false;
}
void thegame(stall &game)
{

    bool gameoverscreen = true;
    do
    {
  
        game.compcount = 0; game.drawcount = 0; game.plcount = 0;
        short rounds = readnum("How Many Rounds 1 To 10 ?\n", 10);
        for (int i = 0; i < rounds; i++)
        {
            cout << "\n\nRound [" << i + 1 << "] begins:\n\n";
            game.user = choice(readnum("Your choice: [1]:Rock, [2]:Paper, [3]:Scissor? ", 3));
            game.comp = choice(randnum(1, 3));
            cout << "\n";
            for (int j = 0; j < 12; j++)
            {
                cout << "_";
            }
            cout << "Round ["<<i+1<<"]";
            for (int j = 0; j < 12; j++)
            {
                cout << "_";
            }
            cout << "\n\nPlayer1 Choice :  ";  printchoice(game.user);
            cout << "\nComputer choice:   "; printchoice(game.comp);
            cout << "\nRound winner   :   ["; printwinner(game); cout << "]\n";
            if (game.comp ==game.user)
            {
                game.drawcount++;
            }
            else if (whowins(game))
            {
                game.plcount++;
            }
            else 
            {
                 game.compcount++;
            }
            for (int j = 0; j < 33; j++)
            {
                cout << "_";
            }
        }
        gameoverscreen = gameover(game, rounds);
    } while (gameoverscreen);
}


int main()
{
    srand((unsigned)time(NULL));
    stall game;
    thegame(game);

    
}


