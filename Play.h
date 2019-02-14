#pragma once

#include "Header.h"
#include "GameMgr.h"
#include "Player.h"
#include "Stage.h"

class Play : public Stage
{
private:
	int P_is_gameover;			//게임 종료 여부 체크
	int P_level;
	int P_cnt;
	GameMgr P_GM;
	Block *P_Block;
	Player* P_player;

	//game을 위한 정보
	char keytemp;		//키입력
	int next_block_shape;		//다음 블록
	int block_shape;			//지금 블록
	int block_angle;			//블록의 회전값

	int block_x;				//x좌표
	int block_y;				//y좌표

	int P_turn;
	int shadowB[2][4];

public:
	Play();
	~Play();

	friend int gotoxy(int x, int y, GameMgr& GM);	//커서옮기기
	friend void SetColor(int color, GameMgr& GM);	//색표현
	
	// 사실상 main함수
	void playGame();

	void P_init();
	void P_create_player(int cnt);
	
	// 이동키
	void keyUp();
	void keyDown();
	void keyLeft();
	void keyRight();
	void keySpace();

	// 블록이동
	int P_move_block(int* shape, int* angle, int* x, int* y, int* next_shape);
	void moveAutoBlock();
	void P_show_shadow();

	//자동으로 줄 올라오기
	void makeupBlock();
	void makeupBlock2();
	void makeupBlock3();
	void makeupBlock4();
	void changeTurn(int turn);

	void showEnd();

};