#include "king.h"

struct knight
{
	int x,y;
	int color;

	bool validmove(int curx, int cury, int nextx, int nexty)
	{
		if(curx==nextx && cury==nexty) return false;
		if(!(nextx>=0 && nextx<=7 && nexty>=0 && nexty<=7)) return false;
		if((board[nextx][nexty]<(1-color)*10+7 && board[nextx][nexty]>(1-color)*10) || board[nextx][nexty]==0)
		{
			if((abs(nextx-curx)==2 && abs(nexty-cury)==1) || (abs(nextx-curx)==1 && abs(nexty-cury)==2))
			{
				board[curx][cury]=0;
				board[nextx][nexty]=color*10+2;
				return true;
			}
			else
				return false;
		}
		return false;
	}
};

