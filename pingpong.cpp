#include "pingpong.h"

PingPongGame::PingPongGame() {
  button1Pin = 2;
  button2Pin = 3;
  ledPins[0] = 4;
  ledPins[1] = 5;
  ledPins[2] = 6;
  ledPins[3] = 7;
  ledPins[4] = 8;
  player1Score = 0;
  player2Score = 0;
  highscoreThreshold = 5;
}

void PingPongGame::setup() {
  // pin og LCD
}

void PingPongGame::loop() {
  buttonCheck();
  ledLoop();
}

bool PingPongGame::checkState(int buttonPin, int player) {

}

void PingPongGame::buttonCheck() {

}

void PingPongGame::ledLoop() {
 
  highscore(player1Score);
  highscore(player2Score);
}

void PingPongGame::highscore(int &playerScore) {

}

void PingPongGame::playerDisplay(int playerScore) {

