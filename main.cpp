#include <iostream>
#include <fstream>
#include <string>

struct Player
{
    int playerNum;
    int cell = 0;

    Player(int pN)
    {
        playerNum = pN;
    }

    void move(int newCell)
    {
        cell += newCell;
        if (cell > 99)
        {
            cell = 99;
        }
    }

    void rollDice()
    {
        // D = 1 + (((N + 1) / 2 * 10 + 41) % 6)
        int N, diceRoll;
        std::cout << "Enter a number from 1 to 1000: ";
        std::cin >> N;

        diceRoll = 1 + (((N + 1) / 2 * 10 + 41) % 6);
        std::cout << "Dice roll: " << diceRoll << "\n";

        move(diceRoll);
    }

    void startTurn()
    {
        std::cout << "\n----------\n";
        std::cout << "Player " << playerNum << "'s turn:\n";
        std::cout << "Current cell position: " << cell << "\n";
        
        rollDice();
    }
};

struct Board
{
    int cells[100] = {};
    bool completed = false;

    void checkPlayerCell(Player *player)
    {
        if (player->cell == 99)
        {
            std::cout << "Player " << player->playerNum << " passed the finished the line. They win!";
            completed = true;
            return;
        }

        std::cout << "Landed on cell " << player->cell << ". ";
        if( cells[player->cell - 1] > 0 ) // positive
        {
            player->move(cells[player->cell - 1]);
            std::cout << "However, it was a ladder! Forward to cell " << player->cell << ".";
        }
        else if( cells[player->cell - 1] < 0 ) // negative
        {
            player->move(cells[player->cell - 1]);
            std::cout << "However, it was a snake! Moving back to cell " << player->cell << ".";
        }
        else
        {
            std::cout << "Which is a normal cell.";
        }

    }
};


int main()
{

    struct Player players[2] = {
        Player(1),
        Player(2)
    };

    std::ifstream file("board.txt");
    Board board = Board();
    for(int i = 1; i < 98; i++)
    {
        file >> board.cells[i];
    }


    while(!board.completed)
    {
        for(int i = 0; i < 2; i++)
        {
            if(!board.completed)
            {
                players[i].startTurn();
                board.checkPlayerCell(&players[i]);
            }
        }
    }


    return 0;
}