#pragma once

#include "Question.h"
#include <vector>
#include "Player.h"

class Game
{
private:
    Question question[5];
    int numQuestion;

public:
    int getNum();
    void setNum(int);
    void loadQuestions(string);
    void playGame();
    void checkWin(Player p[]);
};
