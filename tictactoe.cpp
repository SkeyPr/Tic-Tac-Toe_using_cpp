#include<iostream>
#include<ctime>
#include<stdlib.h>

void drawboard(char *spaces);
void playermove(char *spaces, char player);
void cpumove(char *spaces, char cpu);
bool checkwinner(char *spaces, char player, char cpu);
bool checkTie(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char cpu = 'O';
    bool running = true;

    drawboard(spaces);

    while (running)
    {
        playermove(spaces, player);
        drawboard(spaces);
        if (checkwinner(spaces, player, cpu))
        {
            running = false;
            break;
        }

        else if (checkTie(spaces))
        {
            running = false;
            break;
        }
        

        cpumove(spaces, cpu);
        if (checkwinner(spaces, player, cpu))
        {
            running = false;
            break;
        }

        else if (checkTie(spaces))
        {
            running = false;
            break;
        }
    }

    std::cout << "Thanks for playing ";
}

void drawboard(char *spaces)
{
    std::cout << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << spaces[0] << "  |  "<< spaces[1] <<"  |  "<< spaces[2] <<"  " << "\n";
    std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << spaces[3] << "  |  "<< spaces[4] <<"  |  "<< spaces[5] <<"  " << "\n";
    std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << spaces[6] << "  |  "<< spaces[7] <<"  |  "<< spaces[8] <<"  " << "\n";
    std::cout << "     |     |     " << "\n\n";
}

void playermove(char *spaces, char player)
{
    int number;
    do
    {
        std::cout << "Enter the position you want to enter your character in (1-9): ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }
    } while (!(number > 0 && number < 8));
    
    
}

void cpumove(char *spaces, char cpu)
{
    int number;
    srand(time(NULL));

    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = cpu;
            break;
        }
        
    }
    
}

bool checkwinner(char *spaces, char player, char cpu)
{
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
    {
        spaces[0] == player ? std::cout << "The player wins \n" : std::cout << "The Computer Wins";
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
    {
        spaces[3] == player ? std::cout << "The player wins \n" : std::cout << "The Computer Wins";
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
    {
        spaces[6] == player ? std::cout << "The player wins \n" : std::cout << "The Computer Wins";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
    {
        spaces[0] == player ? std::cout << "The player wins \n" : std::cout << "The Computer Wins";
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
    {
        spaces[1] == player ? std::cout << "The player wins \n" : std::cout << "The Computer Wins";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
    {
        spaces[2] == player ? std::cout << "The player wins \n" : std::cout << "The Computer Wins";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
    {
        spaces[0] == player ? std::cout << "The player wins \n" : std::cout << "The Computer Wins";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
    {
        spaces[2] == player ? std::cout << "The player wins \n" : std::cout << "The Computer Wins";
    }
    else
    {
        return false;
    }
    return true;
}

bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }   
    }

    std::cout << "Tie " << '\n';
    return true; 
}