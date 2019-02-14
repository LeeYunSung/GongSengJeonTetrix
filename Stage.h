// ���������� �������� �ʱ�ȭ�ϰ� ����,��ȯ�ϴ� Ŭ����
#pragma once

#include "Header.h"
#include "Player.h"

class Stage
{
private:
	// �������� ����
	int st_level;
	int st_speed;
	int st_clearlines;

public:
	// ������ �� �Ҹ���
	Stage();
	Stage(int level);
	~Stage();

	// ��������� ���� �����ϰ� ��ȭ�� getter/setter
	int getStlevel();
	int getStspeed();
	int getStclearlines();
	
	void setStlevel(int level);
	void setStspeed(int speed);
	void setStclearlines(int clearlines);

	void showStage(int level);
	
};
