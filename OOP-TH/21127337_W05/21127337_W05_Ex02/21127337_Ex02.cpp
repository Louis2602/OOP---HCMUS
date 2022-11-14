#include "TriviaGame.h"

int main()
{
    // srand is used to initialize random number generators, we seed the time as null so the rand() function will output different numbers.
    srand(time(NULL));
    Question q[5];
    fstream fs("questions.txt", ios::in);
    string ques, tmp, ans;
    int correct_ans;
    int user_input;
    int n = 0;
    while (!fs.eof())
    {
        getline(fs, ques);
        q[n].setTriviaQuestion(ques);
        getline(fs, tmp);
        stringstream ss(tmp);
        getline(ss, ans, ' ');
        q[n].setAnswerOne(ans);
        getline(ss, ans, ' ');
        q[n].setAnswerTwo(ans);
        getline(ss, ans, ' ');
        q[n].setAnswerThree(ans);
        getline(ss, ans);
        q[n].setAnswerFour(ans);
        fs >> correct_ans;
        fs.ignore();
        q[n].setCorrectAnswer(correct_ans);
        n++;
    }
    fs.close();
    int prev, randNum;
    prev = randNum = 0;
    int point = 0;
    for (int i = 0; i < n; i++)
    {
        while (prev == randNum)
            randNum = rand() % n;
        cout << q[randNum].getTriviaQuestion() << endl;
        cout << q[randNum].getAnswerOne() << " " << q[randNum].getAnswerTwo() << " " << q[randNum].getAnswerThree() << " " << q[randNum].getAnswerFour() << endl;
        cout << "Enter answer (A:1, B:2, C:3, D:4): ";
        cin >> user_input;
        if (q[randNum].checkGivenAnswer(user_input))
            point++;
        prev = randNum;
    }
    if (point >= n / 2)
    {
        cout << "Congratulations! You have won the trivia game." << endl;
        cout << "Your point is: " << point << endl;
    }
    else
        cout << "Maybe try again next time :))";
    return 0;
}