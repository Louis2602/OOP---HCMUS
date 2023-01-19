#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

class Question
{
private:
    string triviaQuestion;
    string answerOne;
    string answerTwo;
    string answerThree;
    string answerFour;
    int correctAnswer;

public:
    Question() = default;
    Question(string question, string one, string two, string three,
             string four, int answer);

    void setTriviaQuestion(string question);
    void setAnswerOne(string one);
    void setAnswerTwo(string two);
    void setAnswerThree(string three);
    void setAnswerFour(string four);
    void setCorrectAnswer(int answer);

    string getTriviaQuestion();
    string getAnswerOne();
    string getAnswerTwo();
    string getAnswerThree();
    string getAnswerFour();
    int getCorrectAnswer();

    bool checkGivenAnswer(int chosenNumber);
};