#include "Player.h"

Player::Player()
{
    score = 0;
    ans = -1;
}
int Player::getAns()
{
    return ans;
}

void Player::setAns(int _ans)
{
    ans = _ans;
}
int Player::getScore()
{
    return score;
}
void Player::updateScore()
{
    score++;
}