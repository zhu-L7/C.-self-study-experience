#include"ChessData.h"
#include<string.h>

void initChessData(ChessData* data)
{
	if (!data)
	{
		return;
	}
	memset(data->chessMap, 0, sizeof(data->chessMap));//��Ҫ����<string.h>ͷ�ļ�
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

	data->playerFlag = !data->playerFlag;// �����巽
}