#include"ChessData.h"
#include<string.h>

void initChessData(ChessData* data)
{
	if (!data)
	{
		return;
	}
	memset(data->chessMap, 0, sizeof(data->chessMap));//需要引用<string.h>头文件
	memset(data->chessMap, 0, sizeof(data->scoreMap));
	data->playerFlag = true;
}

void updataGameMap(ChessData* data,int row,int col)
{
	if (!data)
	{
		return;
	}
	if (data->playerFlag)
	{
		data->chessMap[row][col] = 1;
	}
	else
	{
		data->chessMap[row][col] = -1;
	}

	data->playerFlag = !data->playerFlag;// 换下棋方
}