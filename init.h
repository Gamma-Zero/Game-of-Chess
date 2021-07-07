#include "queen.h"
using namespace std;

vector<pawn> pw(8), pb(8);
vector<knight> knw(2), knb(2);
vector<bishop> bw(2), bb(2);
vector<rook> rw(2), rb(2);
vector<queen> qw(1), qb(1);
vector<king> kw(1), kb(1);

void print()
{
	for(int i=7;i>=0;--i)
	{
		for(int j=0;j<8;++j)
		{
			if(board[j][i]<10) cout<<0;
			cout<<board[j][i]<<' ';
		}
		cout<<'\n';
	}
	cout<<'\n';
}

void init()
{
	for(int i=0;i<8;++i)
	{
		board[i][1]=1;
		board[i][6]=11;
	}
	board[0][0]=4;
	board[7][0]=4;
	board[0][7]=14;
	board[7][7]=14;
	board[3][0]=5;
	board[3][7]=15;
	board[4][0]=6;
	board[4][7]=16;
	board[1][0]=2;
	board[6][0]=2;
	board[1][7]=12;
	board[6][7]=12;
	board[2][0]=3;
	board[5][0]=3;
	board[2][7]=13;
	board[5][7]=13;
	
	print();
	
	for(int i=0;i<8;++i)
	{
		pw[i].color=0;
		pw[i].x=i;
		pw[i].y=1;
		
		pb[i].color=1;
		pb[i].x=i;
		pb[i].y=6;
	}
	
	for(int i=0;i<2;++i)
	{
		knw[i].color=0;
		rw[i].color=0;
		bw[i].color=0;
		knw[i].y=0;
		bw[i].y=0;
		rw[i].y=0;
		
		knb[i].color=1;
		rb[i].color=1;
		bb[i].color=1;
		knb[i].y=7;
		bb[i].y=7;
		rb[i].y=7;
	}
	
	knw[0].x=1;
	knw[1].x=6;
	bw[0].x=2;
	bw[1].x=5;
	rw[0].x=0;
	rw[1].x=7;
	
	knb[0].x=1;
	knb[1].x=6;
	bb[0].x=2;
	bb[1].x=5;
	rb[0].x=0;
	rb[1].x=7;
	
	qw[0].color=0;
	kw[0].color=0;
	qb[0].color=1;
	kb[0].color=1;
	
	qw[0].x=3;
	kw[0].x=4;
	qb[0].x=3;
	kb[0].x=4;
	
	qw[0].y=0;
	kw[0].y=0;
	qb[0].y=7;
	kb[0].y=7;
}
