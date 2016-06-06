#include "Tic Tac Toe.h"


bool turn;
string option;
string posiciones [3][3] = {{"1", "2", "3"},{"4", "5", "6"},{"7", "8", "9"}};
struct jugadores{
    string XO;
    string name;
    int won;
}player1, player2;


void init(){
   while(true){
        if(welcomeToGame()){
            welcomePlayers();
            while(searchWinner()){
                switchPlayers();
            }
        }else{
            howToPlay();
        }
   }
}

bool cambiarPosicion(string posicion, string XO){
    for(int i = 0; i < 3; i++){
        for(int y = 0; y < 3; y++){
            if(posiciones[i][y] == posicion){
                posiciones[i][y] = XO;
                return true;
            }
        }
    }
    return false;
}

bool searchWinner(){
      display();
      if((posiciones[0][0] == posiciones[0][1] && posiciones[0][0]  == posiciones[0][2]) || (posiciones[1][0] == posiciones[1][1] && posiciones[1][0]  == posiciones[1][2])|| (posiciones[2][0] == posiciones[2][1] && posiciones[2][0]  == posiciones[2][2])){
            cout << "\nWe have a winner, congratulation " + (turn ? player2.name : player1.name) + " you finalize a horizontal line."<<endl;
            return gameOver();
      }
      else if ((posiciones[0][0] == posiciones[1][0] && posiciones[0][0]  == posiciones[2][0]) || (posiciones[0][1] == posiciones[1][1] && posiciones[0][1]  == posiciones[2][1])|| (posiciones[0][2] == posiciones[1][2] && posiciones[0][2]  == posiciones[2][2])){
             cout << "\nWe have a winner, congratulation " + (turn ? player2.name : player1.name) + " you finalize a vertical line."<<endl;
            return gameOver();
      }
      else if ((posiciones[0][0] == posiciones[1][1] && posiciones[0][0]  == posiciones[2][2]) || (posiciones[0][2] == posiciones[1][1] && posiciones[0][2]  == posiciones[2][0])){
             cout << "\nWe have a winner, congratulation " + (turn ? player2.name : player1.name) + " you finalize a diagonal line."<<endl;
            return gameOver();
      }else{
          return isTie();
      }

}

bool gameOver(){
    turn ? player2.won++ : player1.won++;
    cout << "\nDo you want to try again ?\n"<<endl;
    cout << "\t\t1. Yes"<<endl;
    cout << "\t\t2. No \n\nType your option: ";
    cin >> option;
    return verifyOption("1", "2", "", "gameOver");
}

bool isTie(){
    for(int i = 0; i < 3; i++){
        for(int y = 0; y < 3; y++){
            if(!(posiciones[i][y] == "X" || posiciones[i][y] == "O")){
                return true;
            }
        }
     }
    cout << "\nIt is a tie, the game is locked, both are good players, you would like to try again? "<<endl;
    cout << "\t\t1. Yes"<<endl;
    cout << "\t\t2. No \n\nType your option: ";
    cin >> option;
    return verifyOption("1", "2", "", "isTie");
}

void restartGame(){
    for(int i = 0; i < 3; i++){
        for(int y = 0; y < 3; y++){
            switch(i){
                case 0:posiciones[i][y] = IntToString(y+1); break;
                case 1:posiciones[i][y] = IntToString(y+4); break;
                case 2:posiciones[i][y] = IntToString(y+7); break;
            }
        }
    }
}

void switchPlayers(){
    string posicion;
    if(turn){
        cout << "\nIt's your turn "+ player1.name + " plays ["+ player1.XO + "]: ";
        cin >> posicion;
        while(!cambiarPosicion(posicion, player1.XO)){
           display();
           cout << "\nTry again "+ player1.name + " this isn't a valid position.";
           cout << "\nIt's your turn "+ player1.name + " plays ["+ player1.XO + "]: ";
           cin >> posicion;
        }
       turn = false;

    }else{
        cout << "\nIt's your turn "+ player2.name + " plays ["+ player2.XO + "]: ";
        cin >> posicion;
        while(!cambiarPosicion(posicion, player2.XO)){
           display();
           cout << "\nTry again "+ player2.name + " this isn't a valid position.";
           cout << "\nIt's your turn "+ player2.name + " plays ["+ player2.XO + "]: ";
           cin >> posicion;
        }
        turn = true;
    }
}

void welcomePlayers(){
    cout << "\n\t\t\t\tTic Tac Toe Game" <<endl;
    cout << "\nWelcome players in this step you only need write your name and choose \nwho play first"<<endl;
    cout << "\nWrite the name of player 1, the player one would be the [X]: ";
    cin >>player1.name;
    player1.XO = "X";
    player1.won = 0;
    cout << "Write the name of player 2, the player two would be the [O]: ";
    cin >>player2.name;
    player2.XO = "O";
    player2.won = 0;
    cout << "\nWho would like to play first: \n"<<endl;
    cout << "\t1. " + player1.name<<endl;
    cout << "\t2. " + player2.name<<endl;
    cout << "\t3. Random \n\nType your option: ";
    cin >>option;
    verifyOption("1", "2", "3", "welcomePlayers");
}

bool welcomeToGame(){
      cls;
      cout << "\n\t\t\tWelcome to Tic Tac Toe Game\n" <<endl;
      cout << "You have to choose an option to start (Type the number of the option do you want to execute): " <<endl;
      cout << "\t\t1. Star with the game." <<endl;
      cout << "\t\t2. How to play ?"<<endl;
      cout << "\t\t3. Exit \n\nType your option: ";
      cin >> option;
     return verifyOption("1", "2", "3", "welcomeToGame");

}

void howToPlay(){
    cout << "\n\t\t\t\t Tic Tac Toe Game\n" <<endl;
    cout << "To play in Tic Tac Toe Game is very easy you only need to follow \nthe next steps: \n" <<endl;
    cout << "1. First in the main option you need to choose the option 1 (Star with the game)"<<endl;
    cout << "2. Second you have to give us the names of the players how are going to play and choose who would like to play first.\n"<<endl;
    cout << "3. And finally start with the battle.\n\n" <<endl;
    cout << "Press the enter key to continue...";
    cin.ignore();
    cin.get();
}

void display(){
      cls;
      cout << "\n\t\t\t\t Tic Tac Toe Game\n" <<endl;
      cout <<  player1.name + " : " + IntToString (player1.won)  + "\n" + player2.name + " : " + IntToString (player2.won)<<endl;
      cout << "\t\t\t         "+posiciones[0][0] +"  |   "+posiciones[0][1] +"   |   "+posiciones[0][2] +"  " <<endl;
      cout << "\t\t\t       ------------------- " <<endl;
      cout << "\t\t\t         "+posiciones[1][0] +"  |   "+posiciones[1][1] +"   |   "+posiciones[1][2] +"  " <<endl;
      cout << "\t\t\t       ------------------- " <<endl;
      cout << "\t\t\t         "+posiciones[2][0] +"  |   "+posiciones[2][1] +"   |   "+posiciones[2][2] +"  " <<endl;

}

bool verifyOption(string fist, string second, string third, string method){

    if(method == "welcomeToGame"  || method == "welcomePlayers"){
         while(!(option == fist || option == second || option == third)){
             cout << "Try again please you type an invalid option: ";
             cin >> option;
         }

         if(method == "welcomeToGame"){
           if(option == "1"){
             cls;
             option = "";
             return true;
           }
           else if(option == "2"){
             cls;
             option = "";
             return false;
           }
           else if(option == "3"){
               exit(EXIT_SUCCESS);
           }
         }
         else if(method == "welcomePlayers"){
             if(option == "1"){
                turn = true;
             }
             else if(option == "2"){
                turn = false;
             }
             else if(option == "3"){
                srand(time(NULL)); turn = rand() % 2;
             }
             option = "";
         }
    }else{
        while(!(option == fist || option == second)){
             cout << "Try again please you type an invalid option: ";
             cin >> option;
         }
        if(option == "1"){
            restartGame();
            display();
            option = "";
            return true;
         }
         else if(option == "2"){
            restartGame();
            option = "";
            return false;
         }
    }
}

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}
