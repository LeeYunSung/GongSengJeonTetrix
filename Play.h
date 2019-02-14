#pragma once

#include "Header.h"
#include "GameMgr.h"
#include "Player.h"
#include "Stage.h"

class Play : public Stage
{
private:
	int P_is_gameover;			//���� ���� ���� üũ
	int P_level;
	int P_cnt;
	GameMgr P_GM;
	Block *P_Block;
	Player* P_player;

	//game�� ���� ����
	char keytemp;		//Ű�Է�
	int next_block_shape;		//���� ���
	int block_shape;			//���� ���
	int block_angle;			//����� ȸ����

	int block_x;				//x��ǥ
	int block_y;				//y��ǥ

	int P_turn;
	int shadowB[2][4];

public:
	Play();
	~Play();

	friend int gotoxy(int x, int y, GameMgr& GM);	//Ŀ���ű��
	friend void SetColor(int color, GameMgr& GM);	//��ǥ��
	
	// ��ǻ� main�Լ�
	void playGame();

	void P_init();
	void P_create_player(int cnt);
	
	// �̵�Ű
	void keyUp();
	void keyDown();
	void keyLeft();
	void keyRight();
	void keySpace();

	// ����̵�
	int P_move_block(int* shape, int* angle, int* x, int* y, int* next_shape);
	void moveAutoBlock();
	void P_show_shadow();

	//�ڵ����� �� �ö����
	void makeupBlock();
	void makeupBlock2();
	void makeupBlock3();
	void makeupBlock4();
	void changeTurn(int turn);

	void showEnd();

};