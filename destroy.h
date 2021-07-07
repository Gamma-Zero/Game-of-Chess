#include "init.h"
using namespace std;
const int INF=1e9;

void Destroy_Captures()
{
	for(int i=0;i<kw.size();++i)
	{
		if(kw[i].x==INF) continue;
		if(board[kw[i].x][kw[i].y]!=6)
		{
			kw[i].x=INF;
			kw[i].y=INF;
		} 
	}
	for(int i=0;i<qw.size();++i)
	{
		if(qw[i].x==INF) continue;
		if(board[qw[i].x][qw[i].y]!=5)
		{
			qw[i].x=INF;
			qw[i].y=INF;
		} 
	}
	for(int i=0;i<rw.size();++i)
	{
		if(rw[i].x==INF) continue;
		if(board[rw[i].x][rw[i].y]!=4)
		{
			rw[i].x=INF;
			rw[i].y=INF;
		} 
	}
	for(int i=0;i<bw.size();++i)
	{
		if(bw[i].x==INF) continue;
		if(board[bw[i].x][bw[i].y]!=3)
		{
			bw[i].x=INF;
			bw[i].y=INF;
		} 
	}
	for(int i=0;i<knw.size();++i) 
	{
		if(knw[i].x==INF) continue;
		if(board[knw[i].x][knw[i].y]!=2)
		{
			knw[i].x=INF;
			knw[i].y=INF;
		} 
	}
	for(int i=0;i<pw.size();++i) 
	{
		if(pw[i].x==INF) continue;
		if(board[pw[i].x][pw[i].y]!=1)
		{
			pw[i].x=INF;
			pw[i].y=INF;
		} 
	}
	
	for(int i=0;i<kb.size();++i) 
	{
		if(kb[i].x==INF) continue;
		if(board[kb[i].x][kb[i].y]!=16)
		{
			kb[i].x=INF;
			kb[i].y=INF;
		} 
	}
	for(int i=0;i<qb.size();++i) 
	{
		if(qb[i].x==INF) continue;
		if(board[qb[i].x][qb[i].y]!=15)
		{
			qb[i].x=INF;
			qb[i].y=INF;
		} 
	}
	for(int i=0;i<rb.size();++i) 
	{
		if(rb[i].x==INF) continue;
		if(board[rb[i].x][rb[i].y]!=14)
		{
			rb[i].x=INF;
			rb[i].y=INF;
		} 
	}
	for(int i=0;i<bb.size();++i)  
	{
		if(bb[i].x==INF) continue;
		if(board[bb[i].x][bb[i].y]!=13)
		{
			bb[i].x=INF;
			bb[i].y=INF;
		} 
	}
	for(int i=0;i<knb.size();++i) 
	{
		if(knb[i].x==INF) continue;
		if(board[knb[i].x][knb[i].y]!=12)
		{
			knb[i].x=INF;
			knb[i].y=INF;
		} 
	}
	for(int i=0;i<pb.size();++i) 
	{
		if(pb[i].x==INF) continue;
		if(board[pb[i].x][pb[i].y]!=11)
		{
			pb[i].x=INF;
			pb[i].y=INF;
		} 
	}
}

