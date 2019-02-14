// ��ϰ� ���� ��ϴ� Ŭ����
#pragma once

#include "Header.h"
#include "GameMgr.h"

class Block
{
private:
	int B_level;
public:
	// ������ �� �Ҹ���
	Block();
	Block(int level);
	~Block();
	// ��ϰ� �� ���� - �ٸ� Ŭ���������� ����� �������̹Ƿ� public���� ����
	static char block[7][4][4][4];
	static char total_block[21][14];
	// ��Ͽ - ������ �ʱ�ȭ, ����, �浹üũ, 
	int B_block_start(int shape, int* angle, int* x, int* y);
	int B_make_new_block();
	int B_merge_block(int shape, int angle, int x, int y);
	int B_strike_check(int shape, int angle, int x, int y);
	void Makeupblock();
	void Makeupblock2();
	void Makeupblock3();
	void Makeupblock4();
};
