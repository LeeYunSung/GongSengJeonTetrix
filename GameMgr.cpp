#include "GameMgr.h"

GameMgr::GameMgr() : ab_x(5), ab_y(1), GM_Stage(0)
{
}

GameMgr::~GameMgr() {
	if (GM_Stage != 0)
		delete GM_Stage;
}

int GameMgr::GM_show_cur_block(int shape, int angle, int x, int y) {
	int i, j;

	switch (shape)
	{
	case 0:
		GM_SetColor(12);	// red
		break; 
	case 1:
		GM_SetColor(9);	// blue
		break;
	case 2:
		GM_SetColor(11);	// sky blue
		break;
	case 3:
		GM_SetColor(15);	// white
		break;
	case 4:
		GM_SetColor(14);	// yellow
		break;
	case 5:
		GM_SetColor(13);	// violet
		break;
	case 6:
		GM_SetColor(10);	// green
		break;
	}

	for (i = 0; i<4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if ((j + y) < 0)
				continue;

			if (Block::block[shape][angle][j][i] == 1)
			{
				GM_gotoxy((i + x) * 2 + ab_x, j + y + ab_y);
				cout << "■";
			}
		}
	}
	GM_SetColor(0);
	GM_gotoxy(77, 23);
	return 0;
}

int GameMgr::GM_erase_cur_block(int shape, int angle, int x, int y) {
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (Block::block[shape][angle][j][i] == 1)
			{
				GM_gotoxy((i + x) * 2 + ab_x, j + y + ab_y);
				cout << "  ";
				//break;
			}
		}
	}
	return 0;
}

int GameMgr::GM_show_total_block(int level) {
	int i, j;
	GM_SetColor(8);
	for (i = 0; i<21; i++)
	{
		for (j = 0; j<14; j++)
		{
			if (j == 0 || j == 13 || i == 20)		
			{
				GM_SetColor((level % 4) + 1);

			}
			else {
				GM_SetColor(8);
			}
			GM_gotoxy((j * 2) + ab_x, i + ab_y);
			if (Block::total_block[i][j] == 1)
			{
				cout << "■";
			}
			else {
				cout << "  ";
			}
		}
	}
	GM_SetColor(0);
	GM_gotoxy(77, 23);
	return 0;
}

int GameMgr::GM_show_next_block(int shape, int level) {
	int i, j;
	GM_SetColor((level + 1) % 6 + 1);
	for (i = 1; i<7; i++)
	{
		GM_gotoxy(33, i);
		for (j = 0; j<6; j++)
		{
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				cout << "■";
			}
			else {
				cout << "  ";
			}
		}
	}
	GM_show_cur_block(shape, 0, 15, 1);
	return 0;
}

int GameMgr::GM_show_gamestat(int pcnt, int level, Player* player, int clearlines) {
	static int printed_text = 0;
	GM_SetColor(11);
	if (printed_text == 0)
	{
		GM_gotoxy(33, 8);
		cout << "■■■■■■■■";

		GM_gotoxy(33, 9);
		cout << "■            ■";

		GM_gotoxy(33, 10);
		cout << "■ STAGE";

		GM_gotoxy(33, 11);
		cout << "■            ■";

		GM_gotoxy(33, 12);
		cout << "■ SCORE      ■";

		GM_gotoxy(33, 14);
		cout << "■            ■";

		GM_gotoxy(33, 15);
		cout << "■ LINES      ■";

		GM_gotoxy(33, 17);
		cout << "■            ■";

		GM_gotoxy(33, 18);
		cout << "■■■■■■■■";
	}
	GM_gotoxy(42, 10);
	cout << level + 1 << "    ■";
	GM_gotoxy(33, 13);
	cout << "■";
	GM_gotoxy(42, 13);
	cout << player[0].getPRscores();
	GM_gotoxy(45, 13);
	cout << "  ■";
	GM_gotoxy(33, 16);
	cout << "■\t  " << clearlines - player[0].getPRlines() << "    ■";

	if (pcnt == 2) {
		GM_SetColor(13);
		if (printed_text == 0)
		{
			GM_gotoxy(50, 8);
			cout << "■■■■■■■■";

			GM_gotoxy(50, 9);
			cout << "■            ■";

			GM_gotoxy(50, 10);
			cout << "■ STAGE";

			GM_gotoxy(50, 11);
			cout << "■            ■";

			GM_gotoxy(50, 12);
			cout << "■ SCORE      ■";

			GM_gotoxy(50, 14);
			cout << "■            ■";

			GM_gotoxy(50, 15);
			cout << "■ LINES      ■";

			GM_gotoxy(50, 17);
			cout << "■            ■";

			GM_gotoxy(50, 18);
			cout << "■■■■■■■■";
		}
		GM_gotoxy(59, 10);
		cout << level + 1 << "    ■";
		GM_gotoxy(50, 13);
		cout << "■";
		GM_gotoxy(59, 13);
		cout << player[1].getPRscores();
		GM_gotoxy(62, 13);
		cout << "  ■";
		GM_gotoxy(50, 16);
		cout << "■\t   " << clearlines - player[1].getPRlines() << "    ■";
	}
	return 0;
}

int GameMgr::GM_gotoxy(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void GameMgr::GM_SetColor(int color) {
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color);
}

void GameMgr::GM_removeCursor(void) {
	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	cur.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}

void GameMgr::GM_showLogo() {
	int i, j;
	
	GM_removeCursor();
	sndPlaySoundA("C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\opening1.wav", SND_ASYNC | SND_LOOP);//노래

	////이미지 출력 부분//
	system("mode con:cols=100 lines=38");
	char keyInput[10] = "";
	GdiplusStartupInput gdiplusStartupInput;//
	ULONG_PTR gdiplusToken = NULL;//
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);//

	Graphics *pGraphics = new Graphics(GetDC(GetConsoleWindow()));
	Image *pImage = pGraphics ? new Image(L"C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\main.bmp") : NULL;

	if (pImage)
	{
		pGraphics->DrawImage(pImage, 95, 40);//0,0좌표에 그림그리기
	}
	else
	{
		printf("Error\n");
	}
	
	delete pImage;
	delete pGraphics;
	GdiplusShutdown(gdiplusToken);
	
	_getch();
	system("cls");
}

void GameMgr::GM_showStory() {
	system("mode con:cols=105 lines=35 ");

	GM_gotoxy(11, 3);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
	GM_gotoxy(11, 4);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 5); 
	cout << "┃                         공선전 게임에 오신것을 환영합니다!                       ┃" << endl;
	GM_gotoxy(11, 6);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 7);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 8);
	cout << "┃      전쟁의 신 'ARES' 권위의 상징인 황금사과를 가지기 위해 전쟁을 시작합니다.    ┃" << endl;
	GM_gotoxy(11, 9);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 10);
	cout << "┃             ARES는 병사들이 한줄한줄 차분히 방어하는 'BELLONA'의 성,             ┃" << endl;
	GM_gotoxy(11, 12);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 13);
	cout << "┃병사들과 함께 지상과 하늘 모두에서 강력하게 방어하는 'ATHENA'의 성과 'HESTIA'의 성┃" << endl;
	GM_gotoxy(11, 14);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 15);
	cout << "┃      마지막으로 상대방의 공격을 예지할 수 있는 능력을 지닌 'HERA'의 성까지!      ┃" << endl;
	GM_gotoxy(11, 11);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 16);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 17);
	cout << "┃   신들의 강력한 방어에 점점 기세가 기울어진 'ARES'는 'BELLONA'를 찾아가는데....  ┃" << endl;
	GM_gotoxy(11, 18);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 19);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 20);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 21);
	cout << "┃                         성벽을 쌓으며 성을 지키는 신들과                         ┃" << endl;
	GM_gotoxy(11, 22);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 23);
	cout << "┃                  그 성벽을 무너뜨리고 황금사과를 정복하려는 'ARES'!              ┃" << endl;
	GM_gotoxy(11, 24);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 25);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 26);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 27);
	cout << "┃         과연, 당신은 모든 성을 함락시키고 황금사과를 얻을 수 있을 것인가!        ┃" << endl;
	GM_gotoxy(11, 28);
	cout << "┃                                                                                  ┃" << endl;
	GM_gotoxy(11, 29);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	_getch();
	system("cls");
}

void GameMgr::GM_show_gameover() {
	GM_SetColor(12);
	GM_gotoxy(15, 8);
	cout << "┏━━━━━━━━━━━━━┓" << endl;
	GM_gotoxy(15, 9);
	cout << "┃**************************┃" << endl;
	GM_gotoxy(15, 10);
	cout << "┃ 성을 정복하지 못했습니다 ┃" << endl;
	GM_gotoxy(15, 11);   
	cout << "┃                          ┃" << endl;
	GM_gotoxy(15, 12);
	cout << "┃                          ┃" << endl;
	GM_gotoxy(15, 13);
	cout << "┃**************************┃" << endl;
	GM_gotoxy(15, 14);
	cout << "┗━━━━━━━━━━━━━┛" << endl;
	//GM_gotoxy(1, 25);
	fflush(stdin);
	//Sleep(2000);
	

//	계속할건지 그만할건지 예외처리
	while (1) {
		char ch = getch();
		if (ch == 'Y') {
			break;
		}
		else if (ch == 'N') {
			GM_gotoxy(1, 25);
			exit(0);
		}
		else {
			GM_gotoxy(1, 25);
			cout << "다시 입력하세요" << endl;
		}
	}
	system("cls");
}

//난이도를 안받고 1~4까지 쭉쭉 깨는걸로 갔으면...
/*
int GameMgr::GM_input_data() {
	int i = 0;
	GM_SetColor(7);

	while (i<1 || i>8)
	{
		GM_gotoxy(10, 3);
		cout << "◈ 함락시킬 성의 난이도[1-4]:       \b\b\b\b\b\b\b" ;
		cin >> i;
	}
	GM_level = i - 1;

	system("cls");
	return i - 1;
}
*/

int GameMgr::GM_setPcnt() {
	int i = 0;
	system(" mode  con: lines=25   cols=90 ");

	GM_gotoxy(10, 7);
	cout << "┏━━━━━━━━━━━━━<장비 KEY>━━━━━━━━━━━━━┓" << endl;
	GM_gotoxy(10, 8);
	cout << "┃                                                              ┃" << endl;
	GM_gotoxy(10, 9);
	cout << "┃ [1p 신]                      ┃  [2p 신]                     ┃" << endl;
	GM_gotoxy(10, 10);
	cout << "┃ UP(↑)   : Rotate Block      ┃  UP(w)   : Rotate Block      ┃" << endl;
	GM_gotoxy(10, 11);
	cout << "┃ DOWN(↓) : Move One-Step Down┃  DOWN(s) : Move One-Step Down┃" << endl;
	GM_gotoxy(10, 12);
	cout << "┃ SPACE : Move Bottom Down     ┃  SPACE : Move Bottom Down    ┃" << endl;
	GM_gotoxy(10, 13);
	cout << "┃ LEFT(←) : Move Left         ┃  LEFT(a) : Move Left         ┃" << endl;
	GM_gotoxy(10, 14);
	cout << "┃ RIGHT(→) : Move Right       ┃  RIGHT(d) : Move Right       ┃" << endl;
	GM_gotoxy(10, 15);
	cout << "┃                                                              ┃" << endl;
	Sleep(10);
	GM_gotoxy(10, 16);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;


	while (i<1 || i>2)
	{
		GM_gotoxy(10, 3);
		cout << "◈ 전쟁에 참가할 인원[1-2]:       \b\b\b\b\b\b\b";
		cin >> i;
	}
	system("cls");
	return i;
}

void GameMgr::GM_setPlayer(Player* player) {
	GM_Player = player;
}


void GameMgr::GM_setStage(int level) {
	GM_level = level;
	if (GM_Stage != NULL) {
		delete GM_Stage;
	}
	GM_Stage = new Stage(level);		
}

Stage& GameMgr::GM_getStage() {
	return *GM_Stage;
}

int GameMgr::GM_check_full_line(int pcnt, int turn) {
	int i, j, k;
	for (i = 0; i<20; i++)
	{
		for (j = 1; j<13; j++)
		{
			if (Block::total_block[i][j] == 0)
				break;
		}
		if (j == 13)	
		{
			int lines = GM_Player[turn].getPRlines();
			lines++;
	
			GM_Player[turn].setPRlines(lines);
//			GM_Player[turn].setPRlines(1);
			GM_show_total_block(GM_level);
			GM_SetColor(9);
			GM_gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j < 13; j++)
			{
				cout << "□";
				Sleep(10);
			}
			GM_gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j < 13; j++)
			{
				cout << "  ";
				Sleep(10);
			}

			for (k = i; k > 0; k--)
			{
				for (j = 1; j < 13; j++)
					Block::total_block[k][j] = Block::total_block[k - 1][j];
			}
			for (j = 1; j < 13; j++)
				Block::total_block[0][j] = 0;

			GM_Player[turn].setPRscores(GM_Player[turn].getPRscores() + 100 + (GM_level * 10) + (rand() % 10));
			GM_show_gamestat(pcnt, GM_level, GM_Player, GM_getStage().getStclearlines());
			break;
		}
	}
	return 0;
}