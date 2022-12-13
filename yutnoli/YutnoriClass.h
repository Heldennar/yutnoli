#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


class YutnoriClass
{
private:
	
protected:
	int roll_m; //윷 나온 횟수
	int player1[4]; //플레이어 말
	int player2[4];
	int board[65]; //보드 (21~25 == 골인)
	int dice[4]; //윷
	int moveNum[32]; //윷 저장
	int b_len; //보드배열 길이
	bool playing;
	bool turn;
	bool ready;
	int choPl;
	bool moveT;
	bool diceT;
	int choVa;
public:
	YutnoriClass(); //초기화용
};