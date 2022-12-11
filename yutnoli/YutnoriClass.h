#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


class YutnoriClass
{
private:
	
protected:
	int roll_m; //�� ���� Ƚ��
	int player1[4]; //�÷��̾� ��
	int player2[4];
	int board[65]; //���� (21~25 == ����)
	int dice[4]; //��
	int moveNum[32]; //�� ����
	int b_len; //����迭 ����
	bool playing;
	bool turn;
	bool ready;
	int choPl;
	bool moveT;
	bool diceT;
	int choVa;
public:
	YutnoriClass(); //�ʱ�ȭ��
	int roll(); //�� ������
	void move(int player); //�̵�
	bool randT(); //���� ����
	bool bonusT(); //�߰��� Ȯ��
	bool catchs(int num); //�� ���or ����
	bool goal(); //���� Ȯ��
	bool win(); //�¸� Ȯ��
	void showPlayer();
};