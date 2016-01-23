#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <ctime>        /* note code didn't break when this wasn't included ***/

using namespace std;

enum Status { WON, LOST, CONTINUE };
//StatusNames[0] = WON etc. create an array with the enums in order
//for us to print values as strings and not their integer value
const char StatusNames[][10] = { "WON", "LOST", "CONTINUE" };

//Helper method: prints out the enums as string
void getGameStatus(Status gameStatus){
  if(gameStatus == WON){
      cout << " 2 --- INFO gameStatus: " << StatusNames[gameStatus] << endl;
    }else if(gameStatus == LOST){
      cout << " 2 --- INFO gameStatus: " << StatusNames[gameStatus]<< endl;
    }else{
      cout << " 2 --- INFO gameStatus: " << StatusNames[gameStatus] << endl;
  }
}

/**
* Method to caluclate the sums of two dice rolled.
* dice numbers are 1,2,3,4,5,6
* number = shiftingValue + rand() % scalingFactor;
**/
unsigned int rollDice(){
  unsigned int diceOne = 1 + rand() % 6;
  unsigned int diceTwo = 1 + rand() % 6;
  unsigned int sum = diceOne + diceTwo;
  cout << "dice one = " << diceOne << endl
  << "dice two = " << diceTwo << endl << "sum = " << sum << endl;
  return sum;
}

/**
* Method to display messages to player
* If the sums of two dice rolled is greater than one
* then the method execute
**/
Status displayMessage(int sum){
  Status gameStatus;
  string op;
  if (sum >= 1) {
    switch(sum){
      case 7  : //sum is 7 or 11 on first roll player wins
      case 11 :
        cout << "Player rolled " << sum << " on first roll and won!" << endl;
        cout << "PASSWORD is : hehe" << endl;
        gameStatus = WON;
        op = string("open ").append("http://dewitjin.com/for-neal/");
        system(op.c_str());
        return gameStatus;
      case 2  :   //sum is 2, 3, 12 on first roll player gets "crap" and loses
      case 3  :
      case 12 :
        cout << "Player rolled " << sum << " on first roll and lose, CRAP" << endl;
        gameStatus = LOST;
        return gameStatus;
      default :
        // sum is 4,5,6,8,9,10 - then this sum becomes players points
        //after the first roll player
        cout << "Player points is " << sum << " points." << endl;
        gameStatus = CONTINUE;
        return gameStatus;
    }//end of switch
  }//end of if
  return gameStatus;
}//end of displayMessage(sum)

/**
* Note: playerPoints are the players TOTAL points
* i.e. After game one, points = sum then game two and so forth,
* playerPoints = sum + playerPoints
**/
int main(){
  unsigned int sum = 0;
  unsigned int playerPoints = 0;
  Status gameStatus;

  srand (time(NULL)); //ensures rand() is starts from different a different seed
  cout << "Press ENTER to start the game" << endl;
   if(cin.get() == '\n'){
        sum = rollDice();
        gameStatus = displayMessage(sum);
        playerPoints = sum; //keeps track of points
        cout << " 1 --- INFO sum: " << sum << endl;
        getGameStatus(gameStatus);
        cout << endl;
        //if the first game ends with CONTINUE status then the player
        //will be asked to play the game again
        if(gameStatus == CONTINUE){
          cout << "Press ENTER to play the game one more time : )" << endl;
          if(cin.get() == '\n'){
            //then play the game again, BUT if the player rolls 7 on second game then he loses
            playerPoints = rollDice(); // assign new points to playerPoints variable so we can still use value of sum
            if(playerPoints == 7){
              cout << " 3 --- INFO Player rolled " << playerPoints << " on second roll, which means player LOST" << endl;
              gameStatus = LOST;
              getGameStatus(gameStatus);
            }else{
              //cout << " 4 --- debug player points " << playerPoints << endl;
              //cout << " 5 --- debug new sum " << sum << endl;
              //cout << " 6 --- debug past player point + new sum " << playerPoints + sum << endl;
              //getGameStatus(gameStatus);
              cout << " 7 --- INFO --- SUCCESS! You played and won. Thank-you for playing." << endl;
              cout << "PASSWORD is : hehe" << endl;
              string op = string("open ").append("http://dewitjin.com/for-neal/");
              system(op.c_str());
            }
          }else{
            cout << "Good bye" << endl;
            return 0;
          }//end  if(cin.get() == '\n')
      }//end if(gameStatus == CONTINUE)
  }//end if

  return 0;
}


