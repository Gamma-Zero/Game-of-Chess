#include "global.h"
using namespace std;

struct rook
{
	int x,y, color;
	bool castle=true;
	
	bool validmove(int curx, int cury, int nextx, int nexty)
	{
		if(curx==nextx && cury==nexty) return false;
		if(!(nextx>=0 && nextx<=7 && nexty>=0 && nexty<=7)) return false;
		if(nextx==curx)
		{
			int inc=1;
			if(cury>nexty) inc=-1;
			if(inc>0)
			{
				for(int i=cury;i<=nexty;i++)
				{
					if(i!=nexty && (board[x][i]==0 || i==cury))
						continue;
					else if(i!=nexty)
						return false;
					else
					{
						int start;
						if(color==0) start=11;
						else start=1;
						if((start<=board[curx][i] && start+5>=board[curx][i]) || board[curx][i]==0)
						{
							board[curx][cury]=0;
							board[curx][nexty]=10*color+4;
							return true;
						}
						else 
							return false;
					}
				}
				return false;
			}
			else
			{
				for(int i=cury;i>=nexty;i--)
				{
					if(i!=nexty && (board[x][i]==0 || i==cury))
						continue;
					else if(i!=nexty)
						return false;
					else
					{
						int start;
						if(color==0) start=11;
						else start=1;
						if((start<=board[curx][i] && start+5>=board[curx][i]) || board[curx][i]==0)
						{
							board[curx][cury]=0;
							board[curx][nexty]=10*color+4;
							return true;
						}
						else 
							return false;
					}
				}
				return false;
			}
		}

		else if(cury==nexty)
		{
			int inc=1;
			if(curx>nextx) inc=-1;
			if(inc>0)
			{
				for(int i=curx;i<=nextx;i++)
				{
					if(i!=nextx && (board[i][y]==0 || i==curx))
						continue;
					else if(i!=nextx)
						return false;
					else
					{
						int start;
						if(color==0) start=11;
						else start=1;
						if((start<=board[i][cury] && start+5>=board[i][cury]) || board[i][cury]==0)
						{
							board[curx][cury]=0;
							board[nextx][cury]=10*color+4;
							return true;
						}
						else 
							return false;
					}
				}
				return false;
			}
			else
			{
				for(int i=curx;i>=nextx;i--)
				{
					if(i!=nextx && (board[i][y]==0 || i==curx))
						continue;
					else if(i!=nextx)
						return false;
					else
					{
						int start;
						if(color==0) start=11;
						else start=1;
						if((start<=board[i][cury] && start+5>=board[i][cury]) || board[i][cury]==0)
						{
							board[curx][cury]=0;
							board[nextx][cury]=10*color+4;
							return true;
						}
						else 
							return false;
					}
				}
				return false;
			}
		}
		else 
			return false;
	}
};

