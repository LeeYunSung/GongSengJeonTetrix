// ������ ����, �, ȭ������� ����ϴ� Ŭ����
#pragma once

#include "Header.h"
#include "Block.h"
#include "Stage.h"
#include "Player.h"
#include <conio.h>
class GameMgr
{
private:
	// ȭ���� ������ǥ
	const int ab_x;
	const int ab_y;
	int GM_level;
	Stage *GM_Stage;
	Player* GM_Player;
public:
	// ������ �� �Ҹ���
	GameMgr();
	~GameMgr();
	// ���� ���� �� ������ �Լ�
	int GM_gotoxy(int x, int y);
	void GM_SetColor(int color);
	void GM_removeCursor(void);

	// ȭ����� �Լ�
	int GM_show_cur_block(int shape, int angle, int x, int y);
	int GM_erase_cur_block(int shape, int angle, int x, int y);
	int GM_show_total_block(int level);
	int GM_show_next_block(int shape, int level);
	int GM_show_gamestat(int pcnt, int level, Player* player, int clearlines);
	void GM_showLogo();
	void GM_showStory();
	void GM_show_gameover();

	//int GM_input_data();
	int GM_setPcnt();
	void GM_setPlayer(Player* player);
	void GM_setStage(int level);
	Stage& GM_getStage();
	int GM_check_full_line(int pcnt, int turn);

};