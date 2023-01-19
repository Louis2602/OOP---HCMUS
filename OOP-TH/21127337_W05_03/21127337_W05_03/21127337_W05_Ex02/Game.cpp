#include "Game.h"

int Game::getNum()
{
    return numQuestion;
}
void Game::setNum(int _num)
{
    numQuestion = _num;
}
void Game::loadQuestions(string filename)
{
    fstream fs(filename, ios::in);
    string ques, tmp, ans;
    int correct_ans;
    int n = 0;
    Question q;
    while (!fs.eof())
    {
        getline(fs, ques);
        question[n].setTriviaQuestion(ques);
        getline(fs, tmp);
        stringstream ss(tmp);
        getline(ss, ans, ' ');
        question[n].setAnswerOne(ans);
        getline(ss, ans, ' ');
        question[n].setAnswerTwo(ans);
        getline(ss, ans, ' ');
        question[n].setAnswerThree(ans);
        getline(ss, ans);
        question[n].setAnswerFour(ans);
        fs >> correct_ans;
        fs.ignore();
        question[n].setCorrectAnswer(correct_ans);
        n++;
    }
    setNum(n);
    fs.close();
}
void Game::playGame()
{
    loadQuestions("questions.txt");
    int user_input;
    int prev, randNum;
    prev = randNum = 0;
    Player p[2];
    for (int i = 0; i < numQuestion; i++)
    {
        while (prev == randNum)
            randNum = rand() % numQuestion;
        cout << question[randNum].getTriviaQuestion() << endl;
        cout << question[randNum].getAnswerOne() << " " << question[randNum].getAnswerTwo() << " " << question[randNum].getAnswerThree() << " " << question[randNum].getAnswerFour() << endl;
        // cout << "Enter answer (A:1, B:2, C:3, D:4): ";
        // cin >> user_input;
        cout << "Player 1 (A:1, B:2, C:3, D:4): ";
        cin >> user_input;
        p[0].setAns(user_input);
        cout << "Player 2 (A:1, B:2, C:3, D:4): ";
        cin >> user_input;
        p[1].setAns(user_input);
        if (question[randNum].checkGivenAnswer(p[0].getAns()))
            p[0].updateScore();
        if (question[randNum].checkGivenAnswer(p[1].getAns()))
            p[1].updateScore();
        prev = randNum;
    }
    checkWin(p);
}
void Game::checkWin(Player p[])
{
    for (int i = 0; i < 2; i++)
    {

        if (p[i].getScore() > numQuestion / 2)
        {
            cout << "Congratulations! You have won the trivia game." << endl;
            cout << "Your point is: " << p[i].getScore() << endl;
        }
        else
            cout << "Maybe try again next time :))";
    }
}