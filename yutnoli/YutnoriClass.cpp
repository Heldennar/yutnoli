// #define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "YutnoriClass.h"
#include "yutnoli.h"
#include "yutnoliDlg.h"
#include <random>


YutnoriClass::YutnoriClass()
{
	b_len = sizeof(board) / sizeof(int);
	for (int i = 0; i < 4; i++) { player1[i] = 0; } //말 리셋
	for (int i = 0; i < 4; i++) { player2[i] = 0; }
	for (int i = 0; i < b_len; i++) { board[i] = 0; } //보드 리셋
	for (int i = 0; i < 4; i++) { dice[i] = 0; }
	playing = NULL;
	turn = NULL;
	ready = NULL;
	roll_m = 0;
	for (int i = 0; i < 32; i++) { moveNum[i] = 0; }
	choPl = -1;
	moveT = NULL;
	diceT = NULL;
	choVa = 0;
}
