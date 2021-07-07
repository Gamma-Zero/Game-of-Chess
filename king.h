#include "rook.h"

struct king
{
	int x,y, color;
	bool check=false;
	bool castle=true;
	

	bool validmove(int curx,int cury,int nextx,int nexty, rook &r1, rook &r2)
	{
		if(curx==nextx && cury==nexty) return false;
		if(!(nextx>=0 && nextx<=7 && nexty>=0 && nexty<=7)) return false;
		if(abs(curx-nextx)<=1 && abs(cury-nexty)<=1)
		{
			if(color==0 && 1<=board[nextx][nexty] && board[nextx][nexty]<10) return false;
			if(color==1 && 10<board[nextx][nexty]) return false;
			board[curx][cury]=0;
			board[nextx][nexty]=10*color+6;
			castle=false;
			return true;
		}
		else if(abs(curx-nextx)!=2 || nexty!=cury) return false;
		else
		{
			if(!castle) return false;
			if(nextx==curx+2)
			{
				if(ischeck(x,y,color)) return false;
				if((r1.x==nextx+1 && r1.y==nexty) || (r1.x==nextx+2 && r1.y==nexty))
				{
					if(!r1.castle) return false;
					for(int q=x+1;q<r1.x;++q) if(board[q][y]!=0) return false;
					board[curx][cury]=0;
					board[r1.x][r1.y]=0;
					board[nextx][nexty]=10*color+6;
					board[nextx-1][nexty]=10*color+4;
					r1.x=nextx-1;
					r1.castle=false;
					return true;
				}
				if((r2.x==nextx+1 && r2.y==nexty) || (r2.x==nextx+2 && r2.y==nexty))
				{
					if(!r2.castle) return false;
					for(int q=x+1;q<r2.x;++q) if(board[q][y]!=0) return false;
					board[curx][cury]=0;
					board[r2.x][r2.y]=0;
					board[nextx][nexty]=10*color+6;
					board[nextx-1][nexty]=10*color+4;
					r2.x=nextx-1;
					r2.castle=false;
					return true;
				}
				return false;
			}
			else
			{
				if((r1.x==nextx-2 && r1.y==nexty) || (r1.x==nextx-3 && r1.y==nexty))
				{
					for(int q=x-1;q>r1.x;--q) if(board[q][y]!=0) return false;
					board[curx][cury]=0;
					board[r1.x][r1.y]=0;
					board[nextx][nexty]=10*color+6;
					board[nextx+1][nexty]=10*color+4;
					r1.x=nextx+1;
					r1.castle=false;
					return true;
				}
				if((r2.x==nextx-2 && r2.y==nexty) || (r2.x==nextx-3 && r2.y==nexty))
				{
					for(int q=x-1;q>r2.x;--q) if(board[q][y]!=0) return false;
					board[curx][cury]=0;
					board[r2.x][r2.y]=0;
					board[nextx][nexty]=10*color+6;
					board[nextx+1][nexty]=10*color+4;
					r2.x=nextx+1;
					r2.castle=false;
					return true;
				}
				return false;
			}
		}
	}
};
