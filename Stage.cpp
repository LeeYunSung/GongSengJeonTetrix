#include "Stage.h"

Stage::Stage(){
}

Stage::Stage(int level) 
{
	//단계로 구성
	switch (level) {
	case 0:
		st_speed = 40;
		break;
	case 1:
		st_speed = 30;
		break;
	case 2:
		st_speed = 20;
		break;
	case 3:
		st_speed = 10;
		break;
/*
	case 4:
		st_speed = 25;
		break;
	case 5:
		st_speed = 20;
		break;
	case 6:
		st_speed = 15;
		break;
	case 7:
		st_speed = 10;
		break;
	case 8:
		st_speed = 6;
		break;
	case 9:
		st_speed = 4;
		break;
*/
	}
	st_clearlines = 1;
}

Stage::~Stage(){
}

int Stage::getStlevel() { return st_level; }
int Stage::getStspeed() { return st_speed; }
int Stage::getStclearlines() { return st_clearlines; }

void Stage::setStlevel(int level) { st_level = level; }
void Stage::setStspeed(int speed) { st_speed = speed; }
void Stage::setStclearlines(int clearlines) { st_clearlines = clearlines; }

void Stage::showStage(int level) {
	if (level == 0) {
		system("mode con:cols=100 lines=38");
		sndPlaySoundA("C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\Stage1.wav", SND_ASYNC | SND_LOOP);//노래
		
		char keyInput[10] = "";
		GdiplusStartupInput gdiplusStartupInput;//
		ULONG_PTR gdiplusToken = NULL;//
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);//

		Graphics *pGraphics = new Graphics(GetDC(GetConsoleWindow()));
		Image *pImage = pGraphics ? new Image(L"C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\stage1.bmp") : NULL;

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
		
		Sleep(2000);
		_getch();
		system("cls");
	}
	else if (level == 1) {
		system("mode con:cols=100 lines=38");
		sndPlaySoundA("C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\Stage2.wav", SND_ASYNC | SND_LOOP);//노래
		char keyInput[10] = "";
		GdiplusStartupInput gdiplusStartupInput;//
		ULONG_PTR gdiplusToken = NULL;//
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);//

		Graphics *pGraphics = new Graphics(GetDC(GetConsoleWindow()));
		Image *pImage = pGraphics ? new Image(L"C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\stage2.bmp") : NULL;

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
		Sleep(2000);
		_getch();
		system("cls");
	}
	else if (level == 2) {
		system("mode con:cols=100 lines=38");
		sndPlaySoundA("C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\Stage3.wav", SND_ASYNC | SND_LOOP);//노래

		char keyInput[10] = "";
		GdiplusStartupInput gdiplusStartupInput;//
		ULONG_PTR gdiplusToken = NULL;//
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);//

		Graphics *pGraphics = new Graphics(GetDC(GetConsoleWindow()));
		Image *pImage = pGraphics ? new Image(L"C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\stage3.bmp") : NULL;

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
		Sleep(2000);
		_getch();
		system("cls");
	}
	else if (level == 3) {
		system("mode con:cols=100 lines=38");
		sndPlaySoundA("C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\Boss.wav", SND_ASYNC | SND_LOOP);//노래

		char keyInput[10] = "";
		GdiplusStartupInput gdiplusStartupInput;//
		ULONG_PTR gdiplusToken = NULL;//
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);//

		Graphics *pGraphics = new Graphics(GetDC(GetConsoleWindow()));
		Image *pImage = pGraphics ? new Image(L"C:\\Users\\samsung\\Documents\\Visual Studio 2015\\Projects\\tetrix\\stage4.bmp") : NULL;

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
		system("cls");
	}
}