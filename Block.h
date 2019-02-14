// 블록과 맵을 운영하는 클래스
#pragma once

#include "Header.h"
#include "GameMgr.h"

class Block
{
private:
	int B_level;
public:
	// 생성자 및 소멸자
	Block();
	Block(int level);
	~Block();
	// 블록과 맵 정보 - 다른 클래스에서도 사용할 변수들이므로 public으로 선언
	static char block[7][4][4][4];
	static char total_block[21][14];
	// 블록운영 - 생성및 초기화, 병합, 충돌체크, 
	int B_block_start(int shape, int* angle, int* x, int* y);
	int B_make_new_block();
	int B_merge_block(int shape, int angle, int x, int y);
	int B_strike_check(int shape, int angle, int x, int y);
	void Makeupblock();
	void Makeupblock2();
	void Makeupblock3();
	void Makeupblock4();
};
