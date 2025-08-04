#include<stdio.h>
#include<graphics.h>
#include<conio.h>   // getch����ͷ�ļ�
#include<mmsystem.h>// �������ֵ�ͷ�ļ�
#pragma comment(lib, "winmm.lib")
#include "tools.h" //ʵ��PNG͸��������ͼ
#include "ChessData.h" //��������ͷ�ļ�
#include<math.h>
#include <windows.h> // ����MessageBox

//----���� ���� ����
IMAGE chessBlackImg, chessWhiteImg; //�ڰ�����ͼƬ

ChessData game;

int clickPosRow, clickPosCol;// ��Ч�����λ��

//----��������

bool clickBoard(MOUSEMSG msg)
{
	int x = msg.x;
	int y = msg.y;
	int col = (x - margin_x) / BLOCK_SIZE;
	int row = (y - margin_y) / BLOCK_SIZE;
	int leftTopPosX = margin_x + BLOCK_SIZE * col;
	int leftTopPosY = margin_y + BLOCK_SIZE * row;
	int len;
	int selectPos = false;

	do
	{
		//���λ�þ���������Ͻǵľ���
		len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY) * (y - leftTopPosY));// sart�ǿ���
		if (len < POS_OFFSET)
		{
			clickPosRow = row;
			clickPosCol = col;
			if (game.chessMap[clickPosRow][clickPosCol] == 0)// ���λ��ԭ��û������
			{
				selectPos = true;
			}
			break;
		}
		//���λ�þ���������Ͻǵľ���
		len = sqrt((x - leftTopPosX - BLOCK_SIZE) * (x - leftTopPosX - BLOCK_SIZE) + (y - leftTopPosY) * (y - leftTopPosY));// sart�ǿ���
		if (len < POS_OFFSET)
		{
			clickPosRow = row;
			clickPosCol = col + 1;
			if (game.chessMap[clickPosRow][clickPosCol] == 0)// ���λ��ԭ��û������
			{
				selectPos = true;
			}
			break;
		}
		//�����λ�þ���������½ǵľ���
		len = sqrt((x - leftTopPosX - BLOCK_SIZE) * (x - leftTopPosX - BLOCK_SIZE) + (y - leftTopPosY - BLOCK_SIZE) * (y - leftTopPosY - BLOCK_SIZE));// sart�ǿ���
		if (len < POS_OFFSET)
		{
			clickPosRow = row + 1;
			clickPosCol = col + 1;
			if (game.chessMap[clickPosRow][clickPosCol] == 0)// ���λ��ԭ��û������
			{
				selectPos = true;
			}
			break;
		}
		//���λ�þ���������½ǵľ���
		len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY - BLOCK_SIZE) * (y - leftTopPosY - BLOCK_SIZE));// sart�ǿ���
		if (len < POS_OFFSET)
		{
			clickPosRow = row + 1;
			clickPosCol = col;
			if (game.chessMap[clickPosRow][clickPosCol] == 0)// ���λ��ԭ��û������
			{
				selectPos = true;
			}
			break;
		}
	} while (0);
	return selectPos;
}

void init()//��ʼ��
{
	initgraph(897, 895); //��ʼ��ͼ�δ���
	loadimage(0, "./assets/����2.jpg"); //���ز���ʾ����ͼƬ

	mciSendString("play ./assets/start.WAV", 0, 0, 0); //��ʼ��Ϸ��ʾ��

	loadimage(&chessBlackImg, "./assets/black.png", BLOCK_SIZE, BLOCK_SIZE, true); //���غ�����ͼƬ
	loadimage(&chessWhiteImg, "./assets/white.png", BLOCK_SIZE, BLOCK_SIZE, true); //���ذ�����ͼƬ

	initChessData(&game);

	// ���ű������֣�ѭ������
	mciSendString("open ./assets/bg.mp3 alias bgm", 0, 0, 0);
	mciSendString("play bgm repeat", 0, 0, 0);
}

void chessDown(int row, int col, chess_kind_t kind)// ��������---������������
{
	mciSendString("play ./assets/down7.wav", 0, 0, 0); //������Ч

	int x = margin_x + col * BLOCK_SIZE - 0.5 * BLOCK_SIZE; //��������X����
	int y = margin_y + row * BLOCK_SIZE - 0.5 * BLOCK_SIZE; //��������Y����

	if (kind == CHESS_WHITE) {
		putimagePNG(x, y, & chessWhiteImg); //���ư�����
	}
	else {
		putimagePNG(x, y, &chessBlackImg); //���ƺ�����
	}
}

// ��鵱ǰλ��(row, col)�Ƿ��γ���������
bool isFive(int row, int col, int kind) {
    int dr[4] = {0, 1, 1, 1}; // �ĸ����򣺺ᡢ�������Խǡ����Խ�
    int dc[4] = {1, 0, 1, -1};
	//dr ����洢�У�row���ı仯����dc ����洢�У�column���ı仯��
	//��������ͨ������һһ��Ӧ����ͬ��ʾһ������
		//���� 0��dr = 0, dc = 1 �� ˮƽ���������ƶ����в��䣬��������
		//���� 1��dr = 1, dc = 0 �� ��ֱ���������ƶ����в��䣬��������
		//���� 2��dr = 1, dc = 1 �� ���Խ��߷��򣨴����ϵ����£��к���ͬʱ������
		//���� 3��dr = 1, dc = -1 �� ���Խ��߷��򣨴����ϵ����£������м����м�����
    for (int d = 0; d < 4; ++d) {
        int cnt = 1;
        // ��������
        for (int i = 1; i < 5; ++i) {
            int r = row + dr[d] * i;
            int c = col + dc[d] * i;
            if (r < 0 || r >= BOARD_GRAD_SIZE || c < 0 || c >= BOARD_GRAD_SIZE) break;
            if (game.chessMap[r][c] == kind) cnt++;
            else break;
        }
        // �򷴷���
        for (int i = 1; i < 5; ++i) {
            int r = row - dr[d] * i;
            int c = col - dc[d] * i;
            if (r < 0 || r >= BOARD_GRAD_SIZE || c < 0 || c >= BOARD_GRAD_SIZE) break;
            if (game.chessMap[r][c] == kind) cnt++;
            else break;
        }
        if (cnt >= 5) return true;// �����������һ�� ��ʤ
    }
    return false;
}

// ���ֺ���
int evaluatePoint(int row, int col, int kind) {
    int score = 0;
    int dr[4] = {0, 1, 1, 1};
    int dc[4] = {1, 0, 1, -1};
    for (int d = 0; d < 4; ++d) {
        int cnt = 1;
        // ������
        for (int i = 1; i < 5; ++i) {
            int r = row + dr[d] * i;
            int c = col + dc[d] * i;
            if (r < 0 || r >= BOARD_GRAD_SIZE || c < 0 || c >= BOARD_GRAD_SIZE) break;
            if (game.chessMap[r][c] == kind) cnt++;
            else break;
        }
        // ������
        for (int i = 1; i < 5; ++i) {
            int r = row - dr[d] * i;
            int c = col - dc[d] * i;
            if (r < 0 || r >= BOARD_GRAD_SIZE || c < 0 || c >= BOARD_GRAD_SIZE) break;
            if (game.chessMap[r][c] == kind) cnt++;
            else break;
        }
        score += cnt * cnt; // ����Խ���Խ��
    }
    return score;
}

// AI���壺���ַ�
void AI_GO() {
    int maxScore = -1;
    int aiRow = -1, aiCol = -1;
    // ���֣��ȿ���AI�Լ���Ҳ������ң����أ�
    for (int row = 0; row < BOARD_GRAD_SIZE; ++row) {
        for (int col = 0; col < BOARD_GRAD_SIZE; ++col) {
            if (game.chessMap[row][col] == 0) {
				int scoreAI = evaluatePoint(row, col, CHESS_WHITE);// AI������
				int scorePlayer = evaluatePoint(row, col, CHESS_BLACK);// ��ҵ�����
                int score = scoreAI > scorePlayer ? scoreAI : scorePlayer + 1; // �������ȣ����ش�֮
                if (score > maxScore) {
                    maxScore = score;
                    aiRow = row;
                    aiCol = col;
                }
            }
        }
    }
    if (aiRow != -1 && aiCol != -1) { // ��� AI �Ƿ��ҵ�����Ч������λ�ã�-1ͨ����ʾδ�ҵ���Чλ�ã���
        chessDown(aiRow, aiCol, CHESS_WHITE);
        updataGameMap(&game, aiRow, aiCol);
        clickPosRow = aiRow; // ����checkOver
        clickPosCol = aiCol;
    }
}

// �����Ϸ�Ƿ����
bool checkOver() {
    int kind = game.playerFlag ? CHESS_WHITE : CHESS_BLACK; // �ո��������
    if (isFive(clickPosRow, clickPosCol, kind)) {
        // ����
		HWND hWnd = GetHWnd(); // ��ȡͼ�δ��ھ����ʹ�丸����Ϊͼ�δ���
        int ret = MessageBox(hWnd, kind == CHESS_BLACK ? "���ʤ�����Ƿ����¿�ʼ��" : "AIʤ�����Ƿ����¿�ʼ��", "��Ϸ����", MB_YESNO | MB_ICONQUESTION);
        if (ret == IDYES) {
            init();
            return true;
        } else {
            closegraph();
            exit(0);
        }
    }
    return false;
}

// �������
void manGO() {
    chessDown(clickPosRow, clickPosCol, CHESS_BLACK);
    updataGameMap(&game, clickPosRow, clickPosCol);
}



int main(void)
{
	init();

	while (1)
	{
		MOUSEMSG msg = GetMouseMsg();// ��ȡ�����Ϣ(�ȴ���ֱ���������Ϣ)
		if(msg.uMsg==WM_LBUTTONUP && clickBoard(msg)) // ������̧��
		{
			manGO();//�������
			if (checkOver())// �����Ϸ�Ƿ����
			{
				init();// �����µ�һ��
				continue;
			}
			AI_GO();// AI����
			if(checkOver())// �����Ϸ�Ƿ����
			{
				init();// �����µ�һ��
				continue;
			}
		}
	}

	mciSendString("close bgm", 0, 0, 0);// �رձ�������
	closegraph(); //�ر�ͼ�δ���
	return 0;
}


// loadimage(IMAGE* img, ...)
//  �����÷��ǰ�ͼƬ���ص��ڴ��е� IMAGE ���������ֱ����ʾ�����ڣ���Ҫ��� putimage ������ʾ��
// loadimage(0, ...)
//  �����÷���һ������д��������һ������Ϊ 0 ʱ��EasyX ���ͼƬֱ�Ӽ��ز���ʾ�������ڣ���ͼ�δ��ڣ��ϡ�
//  Ҳ����˵������д���൱�ڡ����ز���ʾ��������Ҫ�ٵ��� putimage��