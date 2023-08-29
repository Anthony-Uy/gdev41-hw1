#include <iostream>
#include <fstream>

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
        cell = newCell;
        if(cell > 99)
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

        move(cell + diceRoll);
    }

    int startTurn()
    {
        std::cout << "\n----------\n";
        std::cout << "Player " << playerNum << "'s turn:\n";
        std::cout << "Current cell position: " << cell << "\n";
        
        rollDice();
        
        std::cout << "Landed on cell " << cell;
        return cell;
    }
};

struct Board
{
    int cells[100] = {};

    void playerMove(Player *player)
    {
        
    }
};


int main()
{

    Player player1 = Player(1);

    while(player1.cell < 99)
    {
        player1.startTurn();
    }


    return 0;
}