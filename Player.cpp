#include "Player.h"



Player::Player() : PR_turn(false), PR_lines(0), PR_scores(0)
{
}


Player::~Player()
{
}

void Player::setPRturn(int turn) { PR_turn = turn; }
void Player::setPRlines(int lines) { PR_lines = lines; }
void Player::setPRscores(int scores) { PR_scores = scores; }

int Player::getPRturn() { return PR_turn; }
int Player::getPRlines() { return PR_lines; }
int Player::getPRscores() { return PR_scores; }