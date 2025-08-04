#pragma once// ��һ���Ǳ�׼�����㷺֧�ֵ�ͷ�ļ�����ָ�
// ����������ȷ��ͷ�ļ���ͬһ�����뵥Ԫ��ֻ�ᱻ������include��һ�Σ���ֹ�ظ����嵼�µı������

const float BLOCK_SIZE = 67.4f; //���̸��Ӵ�С
const int BOARD_GRAD_SIZE = 13; //���̴�С13x13
const int margin_x = 44; //�������� �߾�
const int margin_y = 43; //�������±߾�
const int POS_OFFSET = BLOCK_SIZE * 0.4;// ��������ж�ƫ����

typedef enum { // ��������
	CHESS_WHITE = -1,
	CHESS_BLACK = 1
}chess_kind_t; 

struct ChessData
{
	//�洢��ǰ���̺�����״̬���հ�Ϊ0������Ϊ1������Ϊ-1
	int chessMap[BOARD_GRAD_SIZE][BOARD_GRAD_SIZE];

	//�洢������λ�������������ΪAI����Ĳο�
	int scoreMap[BOARD_GRAD_SIZE][BOARD_GRAD_SIZE];

	//��ʾ���巽 ����(���)��true������(AI)��false
	bool playerFlag;
};

void initChessData(ChessData*);// ��ʼ����������

void updataGameMap(ChessData* data, int row, int col);//������������