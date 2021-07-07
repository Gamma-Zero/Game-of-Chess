#include "pawn.h"

struct bishop
{
	int x,y;
	int color;

	bool validmove(int curx, int cury, int nextx, int nexty)
	{
		if(curx==nextx && cury==nexty) return false;
		if(!(nextx>=0 && nextx<=7 && nexty>=0 && nexty<=7)) return false;
		if(curx+cury==nextx+nexty)
		{
			int inc=(curx<nextx)-(curx>nextx);  // inc=1 if curx<nextx and -1 otherwise
			
			int x=curx, y=cury;
			
			if(inc>0)
			{
				for(int i=curx;i<=nextx;i+=inc)
				{
					x=i;
					y=curx+cury-x;
					
					if(x!=nextx && (board[x][y]==0 || x==curx))
						continue;
					else if(x!=nextx)
						return false;
					else
					{
						int start;
						if(color==0) start=11;
						else start=1;
						if((start<=board[x][y] && start+5>=board[x][y]) || board[x][y]==0)
						{
							board[curx][cury]=0;
							board[x][y]=10*color+3;
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
				for(int i=curx;i>=nextx;i+=inc)
				{
					x=i;
					y=curx+cury-x;
					
					if(x!=nextx && (board[x][y]==0 || x==curx))
						continue;
					else if(x!=nextx)
						return false;
					else
					{
						int start;
						if(color==0) start=11;
						else start=1;
						if((start<=board[x][y] && start+5>=board[x][y]) || board[x][y]==0)
						{
							board[curx][cury]=0;
							board[x][y]=10*color+3;
							return true;
						}
						else 
							return false;
					}
				}
				return false;
			}
		}
		
		else if(curx-cury==nextx-nexty)
		{
			int inc=(curx<nextx)-(curx>nextx);  // inc=1 if curx<nextx and -1 otherwise
			
			int x=curx, y=cury;
			if(inc>0)
			{
				for(int i=curx;i<=nextx;i+=inc)
				{

					x=i;
					y=-curx+cury+x;
					
					if(x!=nextx && (board[x][y]==0 || x==curx))
						continue;
					else if(x!=nextx)
						return false;
					else
					{
						int start;
						if(color==0) start=11;
						else start=1;
						if((start<=board[x][y] && start+5>=board[x][y]) || board[x][y]==0)
						{
							board[curx][cury]=0;
							board[x][y]=10*color+3;
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
				for(int i=curx;i>=nextx;i+=inc)
				{
					x=i;
					y=-curx+cury+x;
					
					if(x!=nextx && (board[x][y]==0 || x==curx))
						continue;
					else if(x!=nextx)
						return false;
					else
					{
						int start;
						if(color==0) start=11;
						else start=1;
						if((start<=board[x][y] && start+5>=board[x][y]) || board[x][y]==0)
						{
							board[curx][cury]=0;
							board[x][y]=10*color+3;
							return true;
						}
						else 
							return false;
					}
				}
				return false;
			}
		}
		else return false;
	}
};
