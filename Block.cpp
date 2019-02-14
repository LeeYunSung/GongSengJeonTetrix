#include "Block.h"
#include <cstdlib>

Block::Block() {
}

Block::Block(int level) {
	//level = 0;
	B_level = level;
}

Block::~Block() {
}

char Block::block[7][4][4][4] = {
	1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,   1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,   1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,

	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,

	0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,   1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,   0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,

	1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,   1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,   0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,

	1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,   1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,   1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,

	1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,   1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,

	0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,   0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,

};

char Block::total_block[21][14] = {
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

void Block::Makeupblock()
{

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 14; j++) {
			total_block[i][j] = total_block[i + 1][j];
		}
	}

	/*for (int i = 0; i < 14; i++) {
	total_block[20][i]=1;
	}*/
	//srand((unsigned)time(NULL));
	total_block[19][rand() % 12 + 1] = 0;
}
void Block::Makeupblock2() // 2*2 네모모양 씩만 벽으로 올라온다
{
	//srand((unsigned)time(NULL));

	int num1;
	//for (int i = 0; i < 18; i++)
	//{
	//   num1 = (rand() % 11) + 1;
	//   total_block[i][num1] = total_block[i + 2][num1];
	//   total_block[i][num1 + 1] = total_block[i + 2][num1 + 1];

	//}
	//for (int i = 19; i > 17; i--) {

	//   total_block[i][num1] = total_block[20][0];
	//   total_block[i][num1 + 1] = total_block[20][0];
	//}
	num1 = (rand() % 11) + 1;
	for (int i = 19; i > 1; i--) {

		if (total_block[i][num1] != total_block[20][0]
			&& total_block[i][num1 + 1] != total_block[20][0]
			&& total_block[i - 1][num1] != total_block[20][0]
			&& total_block[i - 1][num1 + 1] != total_block[20][0]) {
			total_block[i][num1] = total_block[20][0];
			total_block[i][num1 + 1] = total_block[20][0];
			total_block[i - 1][num1] = total_block[20][0];
			total_block[i - 1][num1 + 1] = total_block[20][0];
			break;
		}
	}

}
void Block::Makeupblock3() // 이건 3*3 네모모양 씩만 벽으로 올라온다
{
	//srand((unsigned)time(NULL));

	int num1;
	/*for (int i = 0; i < 17; i++)
	{
	num1 = (rand() % 10) + 1;
	total_block[i][num1] = total_block[i + 3][num1];
	total_block[i][num1 + 1] = total_block[i + 3][num1 + 1];
	total_block[i][num1 + 2] = total_block[i + 3][num1 + 2];

	}
	for (int i = 18; i > 15; i--) {

	total_block[i][num1] = total_block[20][0];
	total_block[i][num1 + 1] = total_block[20][0];
	total_block[i][num1 + 2] = total_block[20][0];
	}*/
	num1 = (rand() % 10) + 1;
	for (int i = 19; i > 2; i--) {

		if (total_block[i][num1] != total_block[20][0] &&
			total_block[i][num1 + 1] != total_block[20][0] &&
			total_block[i - 1][num1] != total_block[20][0] &&
			total_block[i - 1][num1 + 1] != total_block[20][0] &&
			total_block[i][num1 + 2] != total_block[20][0] &&
			total_block[i - 1][num1 + 2] != total_block[20][0] &&
			total_block[i - 2][num1 + 2] != total_block[20][0] &&
			total_block[i - 2][num1 + 1] != total_block[20][0] &&
			total_block[i - 2][num1 + 0] != total_block[20][0])
		{
			total_block[i][num1] = total_block[20][0];
			total_block[i][num1 + 1] = total_block[20][0];
			total_block[i - 1][num1] = total_block[20][0];
			total_block[i - 1][num1 + 1] = total_block[20][0];
			total_block[i][num1 + 2] = total_block[20][0];
			total_block[i - 1][num1 + 2] = total_block[20][0];
			total_block[i - 2][num1 + 2] = total_block[20][0];
			total_block[i - 2][num1 + 1] = total_block[20][0];
			total_block[i - 2][num1 + 0] = total_block[20][0];
			break;
		}
	}

}
void Block::Makeupblock4()
{
	//srand((unsigned)time(NULL));
	int i, j;
	int num1;
	/*for (int i = 0; i < 16; i++)
	{
	num1 = (rand() % 12) + 1;
	total_block[i][num1] = total_block[i + 4][num1];
	}
	for (int i = 19; i > 15; i--) {

	total_block[i][num1] = total_block[20][0];
	}*/
	num1 = (rand() % 12) + 1;
	for (int i = 19; i > 4; i--) {

		if (total_block[i][num1] != total_block[20][0]
			&& total_block[i - 1][num1] != total_block[20][0]
			&& total_block[i - 2][num1] != total_block[20][0]
			&& total_block[i - 3][num1] != total_block[20][0])
		{
			total_block[i][num1] = total_block[20][0];
			total_block[i - 1][num1] = total_block[20][0];
			total_block[i - 2][num1] = total_block[20][0];
			total_block[i - 3][num1] = total_block[20][0];
			break;
		}
	}

}

int Block::B_merge_block(int shape, int angle, int x, int y) {
	int i, j;
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			total_block[y + i][x + j] |= block[shape][angle][i][j];
		}
	}
	return 0;
}

int Block::B_make_new_block() {
	int i = rand() % 100;
	if (i <= (20 - B_level))      //막대기 나올확률 계산
		return 0;
	int shape = (rand() % 6) + 1;
	return shape;
}

int Block::B_strike_check(int shape, int angle, int x, int y) {
	int i, j;
	int block_dat;

	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			if (((x + j) == 0) || ((x + j) == 13))
				block_dat = 1;
			else
				block_dat = total_block[y + i][x + j];

			if ((block_dat == 1) && (block[shape][angle][i][j] == 1))
			{
				return 1;
			}
		}
	}
	return 0;
}

int Block::B_block_start(int shape, int* angle, int* x, int* y) {
	*x = 5;
	switch (shape) {
	case 0:
		*y = -2;
		break;
	case 1:
		*y = 0;
		break;
	case 2:
		*y = -1;
		break;
	case 3:
		*y = -1;
		break;
	case 4:
		*y = -1;
		break;
	case 5:
		*y = 0;
		break;
	case 6:
		*y = 0;
		break;
	}
	*angle = 0;
	return 0;
}