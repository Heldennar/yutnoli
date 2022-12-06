// #define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "YutnoriClass.h"
#include "yutnoli.h"
#include "yutnoliDlg.h"
#include <random>


YutnoriClass::YutnoriClass()
{
	b_len = sizeof(board) / sizeof(int);
	for (int i = 0; i < 4; i++) { player1[i] = 0; } //�� ����
	for (int i = 0; i < 4; i++) { player2[i] = 0; }
	for (int i = 0; i < b_len; i++) { board[i] = 0; } //���� ����
	for (int i = 0; i < 4; i++) { dice[i] = 0; }
	playing = true;
	turn = NULL;
	roll_m = 0;
}
int YutnoriClass::roll(int i)
{
	int roll = 0;
	bool temp = true;

	moveNum = new int[i + 1];
	
	if (i > 0) {
		int* tempNum = new int[i + 1];
		for (int r = 0; r < i; r++)
			tempNum[r] = moveNum[r];
		delete[] moveNum;
		moveNum = tempNum;
		delete[] tempNum;
		tempNum = NULL;
	}
	for (int j = 0; j < 4; j++) {
		// �õ尪�� ��� ���� random_device ����.
		std::random_device rd;

		// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
		std::mt19937 gen(rd());

		// 0 ���� 99 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
		std::uniform_int_distribution<int> dis(0, 1);
		dice[j] = dis(gen);
		roll += dice[j];
	}
	moveNum[i] = roll;
	return moveNum[i];
}
void YutnoriClass::move(int player)
{
	int num = 0;
	while (moveNum[0] != NULL) {
		printf("�̵� ������ �� :");
		for (int i = 0; i < _msize(moveNum) / sizeof(int); i++)
			printf("%d / ", moveNum[i]);
		printf("�̵� : ");
		//scanf("%d", &num);
		int whereami = player1[player];
		int checknum = player1[player] + moveNum[num];
		printf("���õ� ���� %d�Դϴ�. ���� ���� ��ġ�� %d�Դϴ�. �̵��� ���� ��ġ�� %d�Դϴ�.\n", moveNum[num], player1[player], checknum);
		if (checknum != 0 && board[checknum] != 0) // �̵���ų �ڸ��� ���� �ٸ������� ���� ���
		{
			if (catchs(checknum))
				printf("����� ���� ��ҽ��ϴ�.");
			else
				printf("���� �������ϴ�.");
		}
		for (int i = 0; i < 4; i++) {			//���� ������ ��� �ѹ��� �̵�
			if ((whereami > 0) && (whereami == player1[i]))
				player1[i] = checknum;
		}
		if (player1[player] == 0)
			player1[player] = checknum;
		printf("%d������ %d������ �̵� �߽��ϴ�.\n", player, player1[player]);
		moveNum[num] = NULL;
		for (int i = num; i < (_msize(moveNum) / sizeof(int)) - 1; i++) {
			moveNum[i] = moveNum[i + 1];
			moveNum[i + 1] = NULL;
		}
		printf("�̵��Ϸ� \n");
		if (player1[player] > 20)
			goal();
	}
}
bool YutnoriClass::randT()
{
	srand(time(NULL));
	int temp;
	if (playing) {
		temp = rand() % 2;
		if (temp == 0)
		{
			this->turn = true; printf("�÷��̾�1�� ���� �����մϴ�.");
		}
		else if (temp == 1) {
			this->turn = false; printf("�÷��̾�2�� ���� �����մϴ�.");
		}
	}
	return true;
}
bool YutnoriClass::bonusT() //���� ������?
{
	return true;
}
bool YutnoriClass::catchs(int num) //���������� �ƴ��� üũ
{
	for (int i = 0; i < 4; i++) {
		if (player1[i] == num) //���� ���� ���
			return false;
		else if (player2[i] == num) { //���� ���
			player2[i] = 0;
			return true;
		}
		else
			return false;
	}
	return false;
}
bool YutnoriClass::goal()
{
	for (int i = 0; i < 4; i++) {
		if (player1[i] > 20) {
			player1[i] = -1;
			return true;
		}
		if (player2[i] > 20) {
			player2[i] = -1;
			return true;
		}
	}
	return false;
}
bool YutnoriClass::win()
{
	int temp = 0;
	for (int i = 0; i < 4; i++)
		temp -= player1[i];
	if (temp == -4)
		printf("�¸��Ͽ����ϴ�!");
	for (int i = 0; i < 4; i++)
		temp -= player2[i];
	if (temp == -4)
		printf("�й��Ͽ����ϴ�!");
	return false;
}
void YutnoriClass::showPlayer()
{
	printf("������ ���� ���ʽÿ�. (������� ���� ��:");
	for (int i = 0; i < 4; i++)
	{
		if (player1[i] == 0)
			printf("%d / ", i + 1);
	}
	printf(")\n");
	printf("(���� ���� �ִ� �� : ");
	for (int i = 0; i < 4; i++)
	{
		if (player1[i] > 0 && player1[i] < 21)
			printf("%d = %d�� ��ġ / ", i + 1, player1[i]);
	}
	printf(")\n");
}
