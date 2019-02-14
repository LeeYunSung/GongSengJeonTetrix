// 스테이지의 정보들을 초기화하고 저장,반환하는 클래스
#pragma once

#include "Header.h"
#include "Player.h"

class Stage
{
private:
	// 스테이지 정보
	int st_level;
	int st_speed;
	int st_clearlines;

public:
	// 생성자 및 소멸자
	Stage();
	Stage(int level);
	~Stage();

	// 멤버변수의 값을 설정하고 반화할 getter/setter
	int getStlevel();
	int getStspeed();
	int getStclearlines();
	
	void setStlevel(int level);
	void setStspeed(int speed);
	void setStclearlines(int clearlines);

	void showStage(int level);
	
};
