/*********************************************************************
** Program Name: Project 3
** Author: Adil Chaudhry
** Date: 2/4/2019
** Description: This is part 1 of a project where we develop a fantasy combat game
*********************************************************************/

#include <iostream>
#include "Character.h"
#include "Vampire.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"

#include "Menu.h"

#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::vector;

void startGame();


int main() {

    startGame();

    return 0;
}


/*********************************************************************
** Function to start the Game
*********************************************************************/
void startGame() {

    //Keeps track of if the user wants to continue to keep playing
    bool keepPlaying = true;

    //Keeps track of if the game has ended
    bool gameOver = false;

    //Keeps track of the number of rounds
    int counter = 1;

    //Keeps track of the players menu choice
    int menuChoice;

    //Pointer of type Character for each player
    Character *player1;
    Character *player2;

    //While the user wants to keep playing, we run a loop where the users pick their characters and battle it out
    while (keepPlaying == true) {

        vector<string> myMenu = {"Vampire", "Barbarian", "Blue Men", "Medusa", "Harry Potter"};
        Menu characterMenu("", myMenu);
        cout << "Player 1, select your character to battle" << std::endl;
        menuChoice = characterMenu.displayMenu();
        switch (menuChoice) {
            case 1:
                player1 = new Vampire;
                break;
            case 2:
                player1 = new Barbarian;
                break;
            case 3:
                player1 = new BlueMen;
                break;
            case 4:
                player1 = new Medusa;
                break;
            case 5:
                player1 = new HarryPotter;
                break;
        }

        cout << "Player 2, select your character to battle" << std::endl;
        menuChoice = characterMenu.displayMenu();
        switch (menuChoice) {
            case 1:
                player2 = new Vampire;
                break;
            case 2:
                player2 = new Barbarian;
                break;
            case 3:
                player2 = new BlueMen;
                break;
            case 4:
                player2 = new Medusa;
                break;
            case 5:
                player2 = new HarryPotter;
                break;
        }

        //Appends Player 1 and Player 2 names to the selected enemy types to make it easier to identify who's turn it is
        player1->setEnemyType("Player 1 [" + player1->getEnemyType() + "]");
        player2->setEnemyType("Player 2 [" + player2->getEnemyType() + "]");

        //While the battle is not over, keep battling
        while (gameOver == false) {

            //If Player 1 loses, the game is over
            if (player1->getStrength() <= 0 || gameOver == true) {
                gameOver = true;
            } else {
                cout << "-----------------------" << std::endl;
                cout << "         ROUND " << counter << " " << std::endl;
                cout << "-----------------------" << std::endl;

                //Player 1 attackts Player 2
                cout << "Player 1 turn - attack!" << std::endl;
                player2->defence(player1->attack());
                cout << "" << std::endl;
            }

            //If Player 2 loses, the game is over
            if (player2->getStrength() <= 0 || gameOver == true) {
                gameOver = true;
            } else {

                //Player 2 attacks Player 1
                cout << "Player 2 turn - attack!" << std::endl;
                player1->defence(player2->attack());
            }

            cout << "" << std::endl;
            counter++;
        }

        //Asks if the user would like to play again at the end of the round
        vector<string> quitMenuOptions = {"Yes", "No"};
        Menu quitMenu("", quitMenuOptions);
        cout << "Would you like to play again?" << std::endl;
        menuChoice = quitMenu.displayMenu();
        switch (menuChoice) {
            case 1:
                keepPlaying = true;
                gameOver = false;
                counter = 1;
                delete player1;
                player1 = nullptr;
                delete player2;
                player2 = nullptr;
                break;
            case 2:
                keepPlaying = false;

                //memory cleanup
                delete player1;
                player1 = nullptr;
                delete player2;
                player2 = nullptr;
                return;
                break;
        }

    }


}