#pragma once// 是一个非标准但被广泛支持的头文件保护指令。
// 它的作用是确保头文件在同一个编译单元中只会被包含（include）一次，防止重复定义导致的编译错误。

const float BLOCK_SIZE = 67.4f; //棋盘格子大小
const int BOARD_GRAD_SIZE = 13; //棋盘大小13x13
const int margin_x = 44; //棋盘左右 边距
const int margin_y = 43; //棋盘上下边距
const int POS_OFFSET = BLOCK_SIZE * 0.4;// 点击落子判定偏移量

typedef enum { // 棋子种类
	CHESS_WHITE = -1,
	CHESS_BLACK = 1
}chess_kind_t; 

struct ChessData
{
	//存储当前棋盘和棋子状态，空白为0，黑子为1，白子为-1
	int chessMap[BOARD_GRAD_SIZE][BOARD_GRAD_SIZE];

	//存储各个点位的评分情况，作为AI走棋的参考
	int scoreMap[BOARD_GRAD_SIZE][BOARD_GRAD_SIZE];

	//标示下棋方 黑棋(玩家)：true，白棋(AI)：false
	bool playerFlag;
};

void initChessData(ChessData*);// 初始化棋盘数据

void updataGameMap(ChessData* data, int row, int col);//更新棋子数据