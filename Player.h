#pragma once
class Player
{
private:
	int PR_turn;
	int PR_lines;
	int PR_scores;
public:
	Player();
	~Player();

	void setPRturn(int turn);
	void setPRlines(int lines);
	void setPRscores(int scores);

	int getPRturn();
	int getPRlines();
	int getPRscores();
};

