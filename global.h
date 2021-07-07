#include<bits/stdc++.h>
using namespace std;


int board[8][8], boardcopy[8][8];
int lastx=-1, lasty=-1, lastcol=1;

bool ischeck(int x, int y, int color)   // in the position (x,y), is the king in check?
{
	for(int i=x+1;i<8;++i)
	{
		if(board[i][y]==0) continue;
		if(board[i][y]!=10*(1-color)+4 && board[i][y]!=10*(1-color)+5) break;
		return true;
	}
	for(int i=x-1;i>=0;--i)
	{
		if(board[i][y]==0) continue;
		if(board[i][y]!=10*(1-color)+4 && board[i][y]!=10*(1-color)+5) break;
		return true;
	}
	
	for(int i=y+1;i<8;++i)
	{
		if(board[x][i]==0) continue;
		if(board[x][i]!=10*(1-color)+4 && board[x][i]!=10*(1-color)+5) break;
		return true;
	}
	for(int i=y-1;i>=0;--i)
	{
		if(board[x][i]==0) continue;
		if(board[x][i]!=10*(1-color)+4 && board[x][i]!=10*(1-color)+5) break;
		return true;
	}
	
	for(int i=x+1, j=y+1;i<8 && j<8; ++i, ++j)
	{
		if(board[i][j]==0) continue;
		if(board[i][j]!=10*(1-color)+3 && board[i][j]!=10*(1-color)+5) break;
		return true;
	}
	
	for(int i=x-1, j=y-1;i>=0 && j>=0; --i, --j)
	{
		if(board[i][j]==0) continue;
		if(board[i][j]!=10*(1-color)+3 && board[i][j]!=10*(1-color)+5) break;
		return true;
	}
	
	for(int i=x+1, j=y-1;i<8 && j>=0; ++i, --j)
	{
		if(board[i][j]==0) continue;
		if(board[i][j]!=10*(1-color)+3 && board[i][j]!=10*(1-color)+5) break;
		return true;
	}
	
	for(int i=x-1, j=y+1;i>=0 && j<8; --i, ++j)
	{
		if(board[i][j]==0) continue;
		if(board[i][j]!=10*(1-color)+3 && board[i][j]!=10*(1-color)+5) break;
		return true;
	}
	
	vector<pair<int,int>>v;
	v.push_back({x-2,y-1});
	v.push_back({x-2,y+1});
	v.push_back({x+2,y-1});
	v.push_back({x+2,y+1});
	v.push_back({x-1,y-2});
	v.push_back({x-1,y+2});
	v.push_back({x+1,y-2});
	v.push_back({x+1,y+2});
	
	for(auto i:v)
	{
		int p1=i.first, p2=i.second;
		if(0<=p1 && p1<8 && 0<=p2 && p2<8 && board[p1][p2]==(1-color)*10+2) return true;
	}
	
	if(color==0)
	{
		if(x>0 && y<7 && board[x-1][y+1]==11) return true;
		if(x<7 && y<7 && board[x+1][y+1]==11) return true;
	}
	else
	{
		if(x>0 && y>0 && board[x-1][y-1]==1) return true;
		if(x<7 && y>0 && board[x+1][y-1]==1) return true;
	}
	for(int i=-1;i<=1;++i)
	{
		for(int j=-1;j<=1;++j)
		{
			if(i==0 && j==0) continue;
			if(0<=x+i && x+i<=7 && 0<=y+j && y+j<=7 && board[x+i][y+j]%10==6)
				return true;
		}
	}
	
	
	return false;
	
}
