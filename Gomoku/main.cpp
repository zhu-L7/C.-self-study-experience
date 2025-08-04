#include<stdio.h>
#include<graphics.h>
#include<conio.h>   // getch函数头文件
#include<mmsystem.h>// 播放音乐的头文件
#pragma comment(lib, "winmm.lib")
#include "tools.h" //实现PNG透明背景贴图
#include "ChessData.h" //棋盘数据头文件
#include<math.h>
#include <windows.h> // 用于MessageBox

//----常量 定义 声明
IMAGE chessBlackImg, chessWhiteImg; //黑白棋子图片

ChessData game;

int clickPosRow, clickPosCol;// 有效点击的位置

//----函数定义

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
		//点击位置距离格子左上角的距离
		len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY) * (y - leftTopPosY));// sart是开方
		if (len < POS_OFFSET)
		{
			clickPosRow = row;
			clickPosCol = col;
			if (game.chessMap[clickPosRow][clickPosCol] == 0)// 这个位置原本没有棋子
			{
				selectPos = true;
			}
			break;
		}
		//点击位置距离格子右上角的距离
		len = sqrt((x - leftTopPosX - BLOCK_SIZE) * (x - leftTopPosX - BLOCK_SIZE) + (y - leftTopPosY) * (y - leftTopPosY));// sart是开方
		if (len < POS_OFFSET)
		{
			clickPosRow = row;
			clickPosCol = col + 1;
			if (game.chessMap[clickPosRow][clickPosCol] == 0)// 这个位置原本没有棋子
			{
				selectPos = true;
			}
			break;
		}
		//鼠标点击位置距离格子右下角的距离
		len = sqrt((x - leftTopPosX - BLOCK_SIZE) * (x - leftTopPosX - BLOCK_SIZE) + (y - leftTopPosY - BLOCK_SIZE) * (y - leftTopPosY - BLOCK_SIZE));// sart是开方
		if (len < POS_OFFSET)
		{
			clickPosRow = row + 1;
			clickPosCol = col + 1;
			if (game.chessMap[clickPosRow][clickPosCol] == 0)// 这个位置原本没有棋子
			{
				selectPos = true;
			}
			break;
		}
		//点击位置距离格子左下角的距离
		len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY - BLOCK_SIZE) * (y - leftTopPosY - BLOCK_SIZE));// sart是开方
		if (len < POS_OFFSET)
		{
			clickPosRow = row + 1;
			clickPosCol = col;
			if (game.chessMap[clickPosRow][clickPosCol] == 0)// 这个位置原本没有棋子
			{
				selectPos = true;
			}
			break;
		}
	} while (0);
	return selectPos;
}

void init()//初始化
{
	initgraph(897, 895); //初始化图形窗口
	loadimage(0, "./assets/棋盘2.jpg"); //加载并显示棋盘图片

	mciSendString("play ./assets/start.WAV", 0, 0, 0); //开始游戏提示音

	loadimage(&chessBlackImg, "./assets/black.png", BLOCK_SIZE, BLOCK_SIZE, true); //加载黑棋子图片
	loadimage(&chessWhiteImg, "./assets/white.png", BLOCK_SIZE, BLOCK_SIZE, true); //加载白棋子图片

	initChessData(&game);

	// 播放背景音乐，循环播放
	mciSendString("open ./assets/bg.mp3 alias bgm", 0, 0, 0);
	mciSendString("play bgm repeat", 0, 0, 0);
}

void chessDown(int row, int col, chess_kind_t kind)// 绘制棋子---在棋盘上落子
{
	mciSendString("play ./assets/down7.wav", 0, 0, 0); //下棋音效

	int x = margin_x + col * BLOCK_SIZE - 0.5 * BLOCK_SIZE; //计算棋子X坐标
	int y = margin_y + row * BLOCK_SIZE - 0.5 * BLOCK_SIZE; //计算棋子Y坐标

	if (kind == CHESS_WHITE) {
		putimagePNG(x, y, & chessWhiteImg); //绘制白棋子
	}
	else {
		putimagePNG(x, y, &chessBlackImg); //绘制黑棋子
	}
}

// 检查当前位置(row, col)是否形成五子连珠
bool isFive(int row, int col, int kind) {
    int dr[4] = {0, 1, 1, 1}; // 四个方向：横、竖、主对角、副对角
    int dc[4] = {1, 0, 1, -1};
	//dr 数组存储行（row）的变化量，dc 数组存储列（column）的变化量
	//两组数组通过索引一一对应，共同表示一个方向：
		//索引 0：dr = 0, dc = 1 → 水平方向（左右移动，行不变，列增减）
		//索引 1：dr = 1, dc = 0 → 垂直方向（上下移动，列不变，行增减）
		//索引 2：dr = 1, dc = 1 → 主对角线方向（从左上到右下，行和列同时增减）
		//索引 3：dr = 1, dc = -1 → 副对角线方向（从右上到左下，行增列减或行减列增
    for (int d = 0; d < 4; ++d) {
        int cnt = 1;
        // 向正方向
        for (int i = 1; i < 5; ++i) {
            int r = row + dr[d] * i;
            int c = col + dc[d] * i;
            if (r < 0 || r >= BOARD_GRAD_SIZE || c < 0 || c >= BOARD_GRAD_SIZE) break;
            if (game.chessMap[r][c] == kind) cnt++;
            else break;
        }
        // 向反方向
        for (int i = 1; i < 5; ++i) {
            int r = row - dr[d] * i;
            int c = col - dc[d] * i;
            if (r < 0 || r >= BOARD_GRAD_SIZE || c < 0 || c >= BOARD_GRAD_SIZE) break;
            if (game.chessMap[r][c] == kind) cnt++;
            else break;
        }
        if (cnt >= 5) return true;// 五个棋子连在一起 获胜
    }
    return false;
}

// 评分函数
int evaluatePoint(int row, int col, int kind) {
    int score = 0;
    int dr[4] = {0, 1, 1, 1};
    int dc[4] = {1, 0, 1, -1};
    for (int d = 0; d < 4; ++d) {
        int cnt = 1;
        // 正方向
        for (int i = 1; i < 5; ++i) {
            int r = row + dr[d] * i;
            int c = col + dc[d] * i;
            if (r < 0 || r >= BOARD_GRAD_SIZE || c < 0 || c >= BOARD_GRAD_SIZE) break;
            if (game.chessMap[r][c] == kind) cnt++;
            else break;
        }
        // 反方向
        for (int i = 1; i < 5; ++i) {
            int r = row - dr[d] * i;
            int c = col - dc[d] * i;
            if (r < 0 || r >= BOARD_GRAD_SIZE || c < 0 || c >= BOARD_GRAD_SIZE) break;
            if (game.chessMap[r][c] == kind) cnt++;
            else break;
        }
        score += cnt * cnt; // 连珠越多分越高
    }
    return score;
}

// AI走棋：评分法
void AI_GO() {
    int maxScore = -1;
    int aiRow = -1, aiCol = -1;
    // 评分：既考虑AI自己，也考虑玩家（防守）
    for (int row = 0; row < BOARD_GRAD_SIZE; ++row) {
        for (int col = 0; col < BOARD_GRAD_SIZE; ++col) {
            if (game.chessMap[row][col] == 0) {
				int scoreAI = evaluatePoint(row, col, CHESS_WHITE);// AI的评分
				int scorePlayer = evaluatePoint(row, col, CHESS_BLACK);// 玩家的评分
                int score = scoreAI > scorePlayer ? scoreAI : scorePlayer + 1; // 进攻优先，防守次之
                if (score > maxScore) {
                    maxScore = score;
                    aiRow = row;
                    aiCol = col;
                }
            }
        }
    }
    if (aiRow != -1 && aiCol != -1) { // 检查 AI 是否找到了有效的落子位置（-1通常表示未找到有效位置）。
        chessDown(aiRow, aiCol, CHESS_WHITE);
        updataGameMap(&game, aiRow, aiCol);
        clickPosRow = aiRow; // 用于checkOver
        clickPosCol = aiCol;
    }
}

// 检查游戏是否结束
bool checkOver() {
    int kind = game.playerFlag ? CHESS_WHITE : CHESS_BLACK; // 刚刚下完的棋
    if (isFive(clickPosRow, clickPosCol, kind)) {
        // 弹窗
		HWND hWnd = GetHWnd(); // 获取图形窗口句柄，使其父窗口为图形窗口
        int ret = MessageBox(hWnd, kind == CHESS_BLACK ? "玩家胜利！是否重新开始？" : "AI胜利！是否重新开始？", "游戏结束", MB_YESNO | MB_ICONQUESTION);
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

// 玩家走棋
void manGO() {
    chessDown(clickPosRow, clickPosCol, CHESS_BLACK);
    updataGameMap(&game, clickPosRow, clickPosCol);
}



int main(void)
{
	init();

	while (1)
	{
		MOUSEMSG msg = GetMouseMsg();// 获取鼠标消息(等待，直到有鼠标信息)
		if(msg.uMsg==WM_LBUTTONUP && clickBoard(msg)) // 鼠标左键抬起
		{
			manGO();//玩家走棋
			if (checkOver())// 检查游戏是否结束
			{
				init();// 开启新的一局
				continue;
			}
			AI_GO();// AI走棋
			if(checkOver())// 检查游戏是否结束
			{
				init();// 开启新的一局
				continue;
			}
		}
	}

	mciSendString("close bgm", 0, 0, 0);// 关闭背景音乐
	closegraph(); //关闭图形窗口
	return 0;
}


// loadimage(IMAGE* img, ...)
//  这种用法是把图片加载到内存中的 IMAGE 对象里，不会直接显示到窗口，需要配合 putimage 才能显示。
// loadimage(0, ...)
//  这种用法是一个特殊写法。当第一个参数为 0 时，EasyX 会把图片直接加载并显示到主窗口（即图形窗口）上。
//  也就是说，这种写法相当于“加载并显示”，不需要再调用 putimage。