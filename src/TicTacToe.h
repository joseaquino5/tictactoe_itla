#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#define cls system("cls");

using namespace std;
bool cambiarPosicion(string posicion, string XO);
bool searchWinner();
bool isTie();
bool gameOver();
bool welcomeToGame();
bool verifyOption(string fist, string second, string third, string method);
void display ();
void restartGame();
void welcomePlayers();
void howToPlay();
void switchPlayers();
void init();
string IntToString (int a);

