#include "move.h"
void Promote()
{
	for(int i=0;i<pw.size();++i)
	{
		if(pw[i].y==7) 
		{
			queen q;
			q.y=7;
			q.x=pw[i].x;
			q.color=0;
			qw.push_back(q);
			board[pw[i].x][7]=5;
		}
	}
	for(int i=0;i<pb.size();++i)
	{
		if(pb[i].y==0) 
		{
			queen q;
			q.y=0;
			q.x=pb[i].x;
			q.color=1;
			qb.push_back(q);
			board[pb[i].x][0]=15;
		}
	}
}
