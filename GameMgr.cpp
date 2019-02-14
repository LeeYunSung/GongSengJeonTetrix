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
				cout << "��";
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
				cout << "��";
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
				cout << "��";
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
		cout << "���������";

		GM_gotoxy(33, 9);
		cout << "��            ��";

		GM_gotoxy(33, 10);
		cout << "�� STAGE";

		GM_gotoxy(33, 11);
		cout << "��            ��";

		GM_gotoxy(33, 12);
		cout << "�� SCORE      ��";

		GM_gotoxy(33, 14);
		cout << "��            ��";

		GM_gotoxy(33, 15);
		cout << "�� LINES      ��";

		GM_gotoxy(33, 17);
		cout << "��            ��";

		GM_gotoxy(33, 18);
		cout << "���������";
	}
	GM_gotoxy(42, 10);
	cout << level + 1 << "    ��";
	GM_gotoxy(33, 13);
	cout << "��";
	GM_gotoxy(42, 13);
	cout << player[0].getPRscores();
	GM_gotoxy(45, 13);
	cout << "  ��";
	GM_gotoxy(33, 16);
	cout << "��\t  " << clearlines - player[0].getPRlines() << "    ��";

	if (pcnt == 2) {
		GM_SetColor(13);
		if (printed_text == 0)
		{
			GM_gotoxy(50, 8);
			cout << "���������";

			GM_gotoxy(50, 9);
			cout << "��            ��";

			GM_gotoxy(50, 10);
			cout << "�� STAGE";

			GM_gotoxy(50, 11);
			cout << "��            ��";

			GM_gotoxy(50, 12);
			cout << "�� SCORE      ��";

			GM_gotoxy(50, 14);
			cout << "��            ��";

			GM_gotoxy(50, 15);
			cout << "�� LINES      ��";

			GM_gotoxy(50, 17);
			cout << "��            ��";

			GM_gotoxy(50, 18);
			cout << "���������";
		}
		GM_gotoxy(59, 10);
		cout << level + 1 << "    ��";
		GM_gotoxy(50, 13);
		cout << "��";
		GM_gotoxy(59, 13);
		cout << player[1].getPRscores();
		GM_gotoxy(62, 13);
		cout << "  ��";
		GM_gotoxy(50, 16);
		cout << "��\t   " << clearlines - player[1].getPRlines() << "    ��";
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
	sndPlaySoundA("C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\opening1.wav", SND_ASYNC | SND_LOOP);//�뷡

	////�̹��� ��� �κ�//
	system("mode con:cols=100 lines=38");
	char keyInput[10] = "";
	GdiplusStartupInput gdiplusStartupInput;//
	ULONG_PTR gdiplusToken = NULL;//
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);//

	Graphics *pGraphics = new Graphics(GetDC(GetConsoleWindow()));
	Image *pImage = pGraphics ? new Image(L"C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\main.bmp") : NULL;

	if (pImage)
	{
		pGraphics->DrawImage(pImage, 95, 40);//0,0��ǥ�� �׸��׸���
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
	cout << "��������������������������������������������������������������������������������������" << endl;
	GM_gotoxy(11, 4);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 5); 
	cout << "��                         ������ ���ӿ� ���Ű��� ȯ���մϴ�!                       ��" << endl;
	GM_gotoxy(11, 6);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 7);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 8);
	cout << "��      ������ �� 'ARES' ������ ��¡�� Ȳ�ݻ���� ������ ���� ������ �����մϴ�.    ��" << endl;
	GM_gotoxy(11, 9);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 10);
	cout << "��             ARES�� ������� �������� ������ ����ϴ� 'BELLONA'�� ��,             ��" << endl;
	GM_gotoxy(11, 12);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 13);
	cout << "�������� �Բ� ����� �ϴ� ��ο��� �����ϰ� ����ϴ� 'ATHENA'�� ���� 'HESTIA'�� ����" << endl;
	GM_gotoxy(11, 14);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 15);
	cout << "��      ���������� ������ ������ ������ �� �ִ� �ɷ��� ���� 'HERA'�� ������!      ��" << endl;
	GM_gotoxy(11, 11);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 16);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 17);
	cout << "��   �ŵ��� ������ �� ���� �⼼�� ������ 'ARES'�� 'BELLONA'�� ã�ư��µ�....  ��" << endl;
	GM_gotoxy(11, 18);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 19);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 20);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 21);
	cout << "��                         ������ ������ ���� ��Ű�� �ŵ��                         ��" << endl;
	GM_gotoxy(11, 22);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 23);
	cout << "��                  �� ������ ���ʶ߸��� Ȳ�ݻ���� �����Ϸ��� 'ARES'!              ��" << endl;
	GM_gotoxy(11, 24);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 25);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 26);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 27);
	cout << "��         ����, ����� ��� ���� �Զ���Ű�� Ȳ�ݻ���� ���� �� ���� ���ΰ�!        ��" << endl;
	GM_gotoxy(11, 28);
	cout << "��                                                                                  ��" << endl;
	GM_gotoxy(11, 29);
	cout << "��������������������������������������������������������������������������������������" << endl;
	_getch();
	system("cls");
}

void GameMgr::GM_show_gameover() {
	GM_SetColor(12);
	GM_gotoxy(15, 8);
	cout << "������������������������������" << endl;
	GM_gotoxy(15, 9);
	cout << "��**************************��" << endl;
	GM_gotoxy(15, 10);
	cout << "�� ���� �������� ���߽��ϴ� ��" << endl;
	GM_gotoxy(15, 11);   
	cout << "��                          ��" << endl;
	GM_gotoxy(15, 12);
	cout << "��                          ��" << endl;
	GM_gotoxy(15, 13);
	cout << "��**************************��" << endl;
	GM_gotoxy(15, 14);
	cout << "������������������������������" << endl;
	//GM_gotoxy(1, 25);
	fflush(stdin);
	//Sleep(2000);
	

//	����Ұ��� �׸��Ұ��� ����ó��
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
			cout << "�ٽ� �Է��ϼ���" << endl;
		}
	}
	system("cls");
}

//���̵��� �ȹް� 1~4���� ���� ���°ɷ� ������...
/*
int GameMgr::GM_input_data() {
	int i = 0;
	GM_SetColor(7);

	while (i<1 || i>8)
	{
		GM_gotoxy(10, 3);
		cout << "�� �Զ���ų ���� ���̵�[1-4]:       \b\b\b\b\b\b\b" ;
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
	cout << "����������������������������<��� KEY>����������������������������" << endl;
	GM_gotoxy(10, 8);
	cout << "��                                                              ��" << endl;
	GM_gotoxy(10, 9);
	cout << "�� [1p ��]                      ��  [2p ��]                     ��" << endl;
	GM_gotoxy(10, 10);
	cout << "�� UP(��)   : Rotate Block      ��  UP(w)   : Rotate Block      ��" << endl;
	GM_gotoxy(10, 11);
	cout << "�� DOWN(��) : Move One-Step Down��  DOWN(s) : Move One-Step Down��" << endl;
	GM_gotoxy(10, 12);
	cout << "�� SPACE : Move Bottom Down     ��  SPACE : Move Bottom Down    ��" << endl;
	GM_gotoxy(10, 13);
	cout << "�� LEFT(��) : Move Left         ��  LEFT(a) : Move Left         ��" << endl;
	GM_gotoxy(10, 14);
	cout << "�� RIGHT(��) : Move Right       ��  RIGHT(d) : Move Right       ��" << endl;
	GM_gotoxy(10, 15);
	cout << "��                                                              ��" << endl;
	Sleep(10);
	GM_gotoxy(10, 16);
	cout << "������������������������������������������������������������������" << endl;


	while (i<1 || i>2)
	{
		GM_gotoxy(10, 3);
		cout << "�� ���￡ ������ �ο�[1-2]:       \b\b\b\b\b\b\b";
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
				cout << "��";
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