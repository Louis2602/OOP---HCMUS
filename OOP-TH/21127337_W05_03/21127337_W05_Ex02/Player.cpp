#include "Player.h"

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