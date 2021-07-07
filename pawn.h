#include "knight.h"
using namespace std;

struct pawn
{
	int x,y, color;
	bool firstmove=true;
	bool enpassent=false;
	
	bool validmove(int curx,int cury,int nextx,int nexty)
	{
		if(curx==nextx && cury==nexty) return false;
		if(!(nextx>=0 && nextx<=7 && nexty>=0 && nexty<=7)) return false;
		int inc=1;
		if(color==1) inc=-1;
		int start=(1-color)*10;
		
		if(inc==1)
		{
			if(nextx==curx)
			{
				if((nexty!=cury+1) && (nexty!=cury+2)) return false;
				if(nexty==cury+1)
				{
					if(board[nextx][nexty]!=0) return false;
					board[curx][cury]=0;
					board[nextx][nexty]=10*color+1;
					return true;
				}
				else
				{
					if(cury!=1) return false;
					
					if(board[nextx][nexty]!=0 || board[nextx][cury+1]!=0) return false;
					board[curx][cury]=0;
					board[nextx][nexty]=10*color+1;
					return true;
				}
			}
			else if(abs(nextx-curx)>1) return false;
			else
			{
				if(inc!=nexty-cury) return false;
				if(board[nextx][nexty]!=0)
				{
					
					if((1-color)*10+1<=board[nextx][nexty] && board[nextx][nexty]<=(1-color)*10+6)
					{
						board[curx][cury]=0;
						board[nextx][nexty]=10*color+1;
						return true;
					}
					else return false;
				}
				else if(board[nextx][cury]!=0)
				{
					if(board[nextx][cury]!=(1-color)*10+1 || lastx!=nextx || lasty!=cury) return false;
					if(color==0 && cury!=4) return false;
					if(color==1 && cury!=3) return false; 
					board[curx][cury]=0;
					board[nextx][cury]=0;
					board[nextx][nexty]=10*color+1;
					return true;
				}
				else
					return false;
			}
			if(nexty==7) board[nextx][nexty]=10*color+5;
			return true;
		}
		else
		{
			if(nextx==curx)
			{
				if(nexty!=cury-1 && nexty!=cury-2) return false;
				if(nexty==cury-1)
				{
					if(board[nextx][nexty]!=0) return false;
					board[curx][cury]=0;
					board[nextx][nexty]=10*color+1;
				}
				else
				{
					if(cury!=6) return false;
					
					if(board[nextx][nexty]!=0 || board[nextx][cury-1]!=0) return false;
					board[curx][cury]=0;
					board[nextx][nexty]=10*color+1;
				}
			}
			else if(abs(nextx-curx)>1) return false;
			else
			{
				if(inc!=nexty-cury) return false;
				if(board[nextx][nexty]!=0)
				{
					if((1-color)*10+1<=board[nextx][nexty] && board[nextx][nexty]<=(1-color)*10+6)
					{
						board[curx][cury]=0;
						board[nextx][nexty]=10*color+1;
					}
					else return false;
				}
				else if(board[nextx][cury]!=0)
				{
					if(board[nextx][cury]!=(1-color)*10+1 || lastx!=nextx || lasty!=cury) return false;
					if(color==0 && cury!=4) return false;
					if(color==1 && cury!=3) return false; 
					board[curx][cury]=0;
					board[nextx][cury]=0;
					board[nextx][nexty]=10*color+1;
				}
				else
					return false;
			}
			if(nexty==0) board[nextx][nexty]=10*color+5;
			return true;
		}
				
	}
};

