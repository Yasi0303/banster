#ifndef PINGPONGGAME_H
#define PINGPONGGAME_H

class PingPongGame {
public:
  PingPongGame();

  void setup();
  void loop();

private:
  int button1Pin;
  int button2Pin;
  int ledPins[5];  // Assuming 5 LEDs
  int player1Score;
  int player2Score;
  int highscoreThreshold;

  bool checkState(int buttonPin, int player);
  void buttonCheck();
  void ledLoop();
  void highscore(int &playerScore);
  void playerDisplay(int playerScore);
};

#endif
