#include "TriviaGame.h"

Question::Question(string question, string one, string two, string three,
                   string four, int answer)
{
    setTriviaQuestion(question);
    setAnswerOne(one);
    setAnswerTwo(two);
    setAnswerThree(three);
    setAnswerFour(four);
    setCorrectAnswer(answer);
}
void Question::setTriviaQuestion(string question)
{
    triviaQuestion = question;
}
void Question::setAnswerOne(string one)
{
    answerOne = one;
}
void Question::setAnswerTwo(string two)
{
    answerTwo = two;
}
void Question::setAnswerThree(string three)
{
    answerThree = three;
}
void Question::setAnswerFour(string four)
{
    answerFour = four;
}
void Question::setCorrectAnswer(int answer)
{
    correctAnswer = answer;
}
string Question::getTriviaQuestion()
{
    return triviaQuestion;
}
int Question::getCorrectAnswer()
{
    return correctAnswer;
}
string Question::getAnswerOne()
{
    return answerOne;
}
string Question::getAnswerTwo()
{
    return answerTwo;
}
string Question::getAnswerThree()
{
    return answerThree;
}
string Question::getAnswerFour()
{
    return answerFour;
}
bool Question::checkGivenAnswer(int chosenNumber)
{
    return chosenNumber == correctAnswer;
}