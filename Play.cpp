#include "Play.h"

Play::Play() {
	srand((unsigned)time(NULL));
	
	P_Block = NULL;
	P_player = NULL;
	keytemp = NULL;
	P_is_gameover = 0;
	P_level = 0;
	P_cnt = 0;
	P_turn = 0;
}

Play::~Play() {
	if (P_Block != NULL) {
		delete P_Block;
	}
	if (P_player != NULL) {
		delete P_player;
	}
}

int gotoxy(int x, int y, GameMgr& GM) {
	GM.GM_gotoxy(x, y);
	return 0;
}
void SetColor(int color, GameMgr& GM) {
	GM.GM_SetColor(color);	
}
				

void Play::playGame() {
	fflush(stdin);
	P_init();
	P_GM.GM_showLogo();
	//P_level = P_GM.GM_input_data();
	P_GM.GM_showStory();//게임 줄거리 보여주기
	P_cnt = P_GM.GM_setPcnt();//play 인원수 받기
	//stage그림 보여주기
	showStage(P_level);
	
	P_Block = new Block(P_level);
	P_GM.GM_setStage(P_level);
	P_create_player(P_cnt);//1인, 2인인지에 따라 player구성하기

	P_GM.GM_setPlayer(P_player);
	P_player[0].setPRturn(true);
	
	while (1) {
		system("mode  con: lines=25   cols=70");

		P_GM.GM_show_total_block(P_level);
		block_shape = P_Block->B_make_new_block();
		next_block_shape= P_Block->B_make_new_block();
		P_GM.GM_show_next_block(next_block_shape, P_level);
		P_Block->B_block_start(block_shape, &block_angle, &block_x, &block_y);
		P_GM.GM_show_gamestat(P_cnt, P_level, P_player, P_GM.GM_getStage().getStclearlines());

		for (int i = 1; 1; i++)
		{
			fflush(stdin);
			// 키입력받기
			if (kbhit())
			{
				keytemp = _getch();
				if (P_turn == 0) {
					if (keytemp == EXT_KEY)
					{
						keytemp = _getch();
						switch (keytemp)	// 1p 차례
						{
						case KEY_UP:
							keyUp();
							break;
						case KEY_DOWN:
							keyDown();
							break;
						case KEY_LEFT:
							keyLeft();
							break;
						case KEY_RIGHT:
							keyRight();
							break;
						default:
							break;
						}
					}
				}
				else if (P_turn == 1) {		// 2p 차례
					switch (keytemp)
					{
					case 'W':
						keyUp();
						break;
					case 'S':
						keyDown();
						break;
					case 'A':
						keyLeft();
						break;
					case 'D':
						keyRight();
						break;
					default:
						break;
					}
				}
 				if (keytemp == 32)	
				{
					keySpace();
				}
			}
			if (P_level == 0) {
				if (i % (P_GM.GM_getStage().getStspeed() * 15) == 0) // 10을 변수로 줘서 레벨 올라갈때마다 벽쌓이는 속도 빠르게..
				{
					makeupBlock();
				}
			}

			else if (P_level == 1) {
				if (i % (P_GM.GM_getStage().getStspeed() * 17) == 0) // 2*2 칸 네모가 일정시간마다 생긴다
				{
					makeupBlock2();
				}
				if (i % (P_GM.GM_getStage().getStspeed() * 13) == 0) // 10을 변수로 줘서 레벨 올라갈때마다 벽쌓이는 속도 빠르게..
				{
					makeupBlock();
				}				
			}

			else if (P_level == 2) {

				if (i % (P_GM.GM_getStage().getStspeed() * 29) == 0) // 1*4 칸 네모가 일정시간마다 생긴다
				{
					makeupBlock4();
				}
				if (i % (P_GM.GM_getStage().getStspeed() * 21) == 0) // 2*2 칸 네모가 일정시간마다 생긴다
				{
					makeupBlock2();
				}
				if (i % (P_GM.GM_getStage().getStspeed() * 23) == 0) // 3*3 칸 네모가 일정시간마다 생긴다
				{
					makeupBlock3();
				}
				if (i % (P_GM.GM_getStage().getStspeed() * 26) == 0) // 10을 변수로 줘서 레벨 올라갈때마다 벽쌓이는 속도 빠르게..
				{
					makeupBlock();
				}
			}

			if (i%P_GM.GM_getStage().getStspeed() == 0)	// 속도에 맞춰 블록이 떨어짐
			{
				moveAutoBlock();
			}


			if (P_cnt == 2) {
				if (P_GM.GM_getStage().getStclearlines() <= (P_player[0].getPRlines() + P_player[1].getPRlines()))
					break;
			}
			else if (P_GM.GM_getStage().getStclearlines() <= P_player->getPRlines())	// 레벨업
			{
				break;
			}
			if (P_is_gameover == 1)	// 게임오버표시
			{
				P_GM.GM_show_gameover();
				SetColor(7, P_GM);
				break;
			}

			gotoxy(77, 23, P_GM);
			Sleep(15);
		}

		P_init();

		if (P_is_gameover == 1) {	// 게임오버일때
			P_is_gameover = 0;
	
			P_level = 0;//초기화해서 실행
			P_cnt = P_GM.GM_setPcnt();
			//P_create_player(P_cnt);
			showStage(P_level);

			delete P_Block;
			P_Block = new Block(P_level);
			P_GM.GM_setStage(P_level);
			P_create_player(P_cnt);//1인, 2인인지에 따라 player구성하기

			P_GM.GM_setPlayer(P_player);
			//P_player[0].setPRturn(true);

		}
		else {	// 레벨업일때
			changeTurn(P_turn);
			for (int num = 0; num < P_cnt; num++) {
				if (num == P_turn) {
					P_player[num].setPRlines(0);
					continue;
				} 
				else {
					P_player[num].setPRscores(0);
					P_player[num].setPRlines(0);
				}
			}
			int score = P_player[P_turn].getPRscores();

			P_level++;
			
			P_GM.GM_setStage(P_level);
			P_player[P_turn].setPRscores(score);
			system("cls");
			if (P_level == 1) {
				showStage(P_level);
			}
			else if (P_level == 2) {
				showStage(P_level);	
			}
			else if (P_level == 3) {
				showStage(P_level);
			}
			//level이 5가 되면 다 끝낸거니까 Ending 보여주고 끝내기
			else if (P_level == 4) {
				showEnd();
				Sleep(3000);
			}
		}
	}
}

int Play::P_move_block(int* shape, int* angle, int* x, int* y, int* next_shape) {
   P_GM.GM_erase_cur_block(*shape, *angle, *x, *y);

   (*y)++;

   if (P_Block->B_strike_check(*shape, *angle, *x, *y) == 1)
    {
      if (*y<0)   
      {
         return 1;
      }
      (*y)--;

      P_Block->B_merge_block(*shape, *angle, *x, *y);
      P_GM.GM_check_full_line(P_cnt, P_turn); 
      
      P_GM.GM_show_total_block(P_level);

      if (*y< 0) {
         return 1;
      }

      *shape = *next_shape;
      *next_shape = P_Block->B_make_new_block();

      P_Block->B_block_start(*shape, angle, x, y);   
      P_GM.GM_show_next_block(*next_shape, P_level);
	  changeTurn(P_turn);	// 차례를 바꿔준다
      return 2;
   }
   return 0;
}
void Play::P_init() {
	next_block_shape = 0;
	block_shape = 0;
	block_angle = 0;
	block_x = 0;
	block_y = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			shadowB[i][j] = 0;
		}
	}
	
	int i, j;

	for (i = 0; i<20; i++)
	{
		for (j = 0; j<14; j++)
		{
			if ((j == 0) || (j == 13))
			{
				P_Block->total_block[i][j] = 1;
			}
			else {
				P_Block->total_block[i][j] = 0;
			}
		}
	}
	for (j = 0; j<14; j++)			
		P_Block->total_block[20][j] = 1;
}

void Play::moveAutoBlock() {
	P_is_gameover = P_move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
	P_GM.GM_show_cur_block(block_shape, block_angle, block_x, block_y);
}

void Play::P_show_shadow()  //미리보기 출력
{
	int count = 0;
	for (int i = 0; i < 4; i++) {   // 예전 그림자를 지워준다 
		P_GM.GM_gotoxy(shadowB[0][i], shadowB[1][i]);
		P_GM.GM_SetColor(0);
		cout << "□";
	}

	int temp = block_y;
	int shadow_y = -3;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (temp = block_y;; temp++)
			{
				if (P_Block->B_strike_check(block_shape, block_angle, block_x, temp + 1) == 0) // 다른 블록이나 벽에 부딪히지 않고
				{
					if (shadow_y < temp)   // temp가 천장보다 밑에있다면
					{
						shadow_y = temp;   // shadow_y에 temp값을 넣어준다. temp는 떨어질 블록의 그림자 위치
					}
				}
				else
				{
					break;   // 어딘가 부딪히면 탈출
				}
			}
		}
	}
	// 위에서 그림자의 위치를 지정해줌. 아래에선 그림자를 그려줄것
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((j + block_y) < -3)      // 블록이 아직 떨어지지 않았다면
				continue;               // 무시하고 계속진행

			if (Block::block[block_shape][block_angle][j][i] == 1)   //만약 현위치가 블록의 일부가 있다면
			{
				if (block_y < shadow_y) {   // 그리고 블록이 그림자보다 높이있다면
					P_GM.GM_gotoxy((i + block_x) * 2 + 5, j + shadow_y + 2);   // 그림자위치에 그림자를 찍어준다
					if (P_turn == 0) {
						P_GM.GM_SetColor(11);
					}
					else {
						P_GM.GM_SetColor(13);
					}
					cout << "□";
					shadowB[0][count] = (i + block_x) * 2 + 5;
					shadowB[1][count++] = j + shadow_y + 2;
				}
				else
					continue;
			}
		}
	}
	P_GM.GM_gotoxy(77, 23);
}

void Play::makeupBlock() {
	P_Block->Makeupblock();
	P_GM.GM_show_total_block(P_level);
}
void Play::makeupBlock2() {
	P_Block->Makeupblock2();
	P_GM.GM_show_total_block(P_level);
}
void Play::makeupBlock3() {
	P_Block->Makeupblock3();
	P_GM.GM_show_total_block(P_level);
}
void Play::makeupBlock4() {
	P_Block->Makeupblock4();
	P_GM.GM_show_total_block(P_level);
}

void Play::keyUp()
{
	if (P_Block->B_strike_check(block_shape, (block_angle + 1) % 4, block_x, block_y) == 0)
	{
		P_GM.GM_erase_cur_block(block_shape, block_angle, block_x, block_y);
		block_angle = (block_angle + 1) % 4;
		P_GM.GM_show_cur_block(block_shape, block_angle, block_x, block_y);
		if (P_level == 3) {
			P_show_shadow();
		}
		
	}
	else if (block_shape == 0) {
		P_GM.GM_erase_cur_block(block_shape, block_angle, block_x, block_y);
		block_x = block_x - 3;
		block_angle = (block_angle + 1) % 4;
		P_GM.GM_show_cur_block(block_shape, block_angle, block_x, block_y);
	}
	else {
		P_GM.GM_erase_cur_block(block_shape, block_angle, block_x, block_y);
		block_x--;
		block_angle = (block_angle + 1) % 4;
		P_GM.GM_show_cur_block(block_shape, block_angle, block_x, block_y);
	}
}
void Play::keyDown()
{
	P_is_gameover = P_move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
	P_GM.GM_show_cur_block(block_shape, block_angle, block_x, block_y);
	if (P_level == 3) {
		P_show_shadow();
	}
}
void Play::keyLeft()
{
	if (block_x > 1)
	{
		P_GM.GM_erase_cur_block(block_shape, block_angle, block_x, block_y);
		block_x--;
		if (P_Block->B_strike_check(block_shape, block_angle, block_x, block_y) == 1)
			block_x++;

		P_GM.GM_show_cur_block(block_shape, block_angle, block_x, block_y);
		if (P_level == 3) {
			P_show_shadow();
		}
	}
}
void Play::keyRight()
{
	if (block_x < 14)
	{
		P_GM.GM_erase_cur_block(block_shape, block_angle, block_x, block_y);
		block_x++;
		if (P_Block->B_strike_check(block_shape, block_angle, block_x, block_y) == 1)
			block_x--;
		P_GM.GM_show_cur_block(block_shape, block_angle, block_x, block_y);
		if (P_level == 3) {
			P_show_shadow();
		}
	}
}

void Play::keySpace()
{
	while (P_is_gameover == 0)
	{
		P_is_gameover = P_move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
	}
	P_GM.GM_show_cur_block(block_shape, block_angle, block_x, block_y);
	if (P_level == 3) {
		P_show_shadow();
	}
}

void Play::P_create_player(int cnt) {
	if (P_player != NULL) {
		delete[] P_player;
	}
	P_player = new Player[cnt];

	for (int num = 0; num < cnt; num++) {
		P_player[num].setPRscores(0);
		P_player[num].setPRlines(0);
	}
}

void Play::changeTurn(int turn) {
	if (turn == 0) {
		if (P_cnt == 1) {
			P_turn = 0;
		}
		else if (P_cnt == 2) {
			P_turn = 1;
		}
	}
	else if (turn == 1) {
		P_turn = 0;
	}
}

void Play::showEnd() {
	system("cls");
	system("mode con: cols=100 lines=38");
	sndPlaySoundA("C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\ending.wav", SND_ASYNC | SND_LOOP);//노래

	char keyInput[10] = "";
	GdiplusStartupInput gdiplusStartupInput;//
	ULONG_PTR gdiplusToken = NULL;//
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);//

	Graphics *pGraphics = new Graphics(GetDC(GetConsoleWindow()));
	Image *pImage = pGraphics ? new Image(L"C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\end.bmp") : NULL;

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

	Sleep(3000);
	_getch();
	exit(0);
}