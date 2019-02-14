#include <Windows.h>
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <ctime>
#include <gdiplus.h>//이미지
#include<MMSystem.h>//소리
#pragma comment(lib,"Winmm.lib")//소리
#pragma comment(lib, "gdiplus") //이미지

#define EXT_KEY			0xffffffe0
#define KEY_LEFT		0x4b
#define KEY_RIGHT		0x4d
#define KEY_UP			0x48
#define KEY_DOWN		0x50
#define ESC				27

using namespace std;
using namespace Gdiplus;//이미지
