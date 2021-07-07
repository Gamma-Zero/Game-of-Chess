#include "move.h"
using namespace std;

vector<king>gkw, gkb;
vector<queen>gqw, gqb;
vector<rook>grw, grb;
vector<bishop>gbw, gbb;
vector<knight>gknw, gknb;
vector<pawn>gpw, gpb;
int gboard[8][8];

map<int,int>value;

void init_val()
{
	value[1]=100;
	value[2]=300;
	value[3]=300;
	value[4]=500;
	value[5]=900;
	value[6]=10000;
	value[11]=-100;
	value[12]=-300;
	value[13]=-300;
	value[14]=-500;
	value[15]=-900;
	value[16]=-10000;
}


vector<int>minimax(int color, int depth, int alpha, int beta)
{
	
	int V=0;
	for(int i=0;i<8;++i) for(int j=0;j<8;++j) V+=value[board[i][j]];
	
	int board1[8][8];
	for(int i=0;i<8;++i) for(int j=0;j<8;++j) board1[i][j]=board[i][j];    // storing board to restore it later
	
	vector<pawn>pw1=pw, pb1=pb;
	vector<rook>rw1=rw, rb1=rb;
	vector<queen>qw1=qw, qb1=qb;
	vector<king>kw1=kw, kb1=kb;
	vector<bishop>bw1=bw, bb1=bb;
	vector<knight>knw1=knw, knb1=knb;
	int lastx1=lastx, lasty1=lasty;
	
	int score=-100000000;
	if(color==1) score=-score;
	pair<int,int>nextmove;
	int nummoves=0;
	
	
	
	vector<vector<int>>v1;
	for(auto i:rw)
	{
		int cx=i.x, cy=i.y;
		for(int j=0;j<8;++j) v1.push_back({cx, cy, cx, j});
		for(int j=0;j<8;++j) v1.push_back({cx,cy,j,cy});
	}
	for(auto i:rb)
	{
		int cx=i.x, cy=i.y;
		for(int j=0;j<8;++j) v1.push_back({cx, cy, cx, j});
		for(int j=0;j<8;++j) v1.push_back({cx,cy,j,cy});
	}
	
	for(auto i:bw)
	{
		int cx=i.x, cy=i.y;
		for(int j=0;j<8;++j) v1.push_back({cx, cy, j, cy-cx+j});
		for(int j=0;j<8;++j) v1.push_back({cx, cy, j, cx+cy-j});
	}
	for(auto i:bb)
	{
		int cx=i.x, cy=i.y;
		for(int j=0;j<8;++j) v1.push_back({cx, cy, j, cy-cx+j});
		for(int j=0;j<8;++j) v1.push_back({cx, cy, j, cx+cy-j});
	}
	for(auto i:qw)
	{
		int cx=i.x, cy=i.y;
		for(int j=0;j<8;++j) v1.push_back({cx, cy, cx, j});
		for(int j=0;j<8;++j) v1.push_back({cx,cy,j,cy});
		for(int j=0;j<8;++j) v1.push_back({cx, cy, j, cy-cx+j});
		for(int j=0;j<8;++j) v1.push_back({cx, cy, j, cx+cy-j});
	}
	for(auto i:qb)
	{
		int cx=i.x, cy=i.y;
		for(int j=0;j<8;++j) v1.push_back({cx, cy, cx, j});
		for(int j=0;j<8;++j) v1.push_back({cx,cy,j,cy});
		for(int j=0;j<8;++j) v1.push_back({cx, cy, j, cy-cx+j});
		for(int j=0;j<8;++j) v1.push_back({cx, cy, j, cx+cy-j});
	}
	for(auto i:pw)
	{
		int cx=i.x, cy=i.y;
		v1.push_back({cx, cy, cx, cy+1});
		v1.push_back({cx, cy, cx, cy+2});
		v1.push_back({cx, cy, cx, cy-1});
		v1.push_back({cx, cy, cx, cy-2});
		v1.push_back({cx, cy, cx-1, cy+1});
		v1.push_back({cx, cy, cx-1, cy-1});
		v1.push_back({cx, cy, cx+1, cy-1});
		v1.push_back({cx, cy, cx+1, cy+1});
	}
	for(auto i:pb)
	{
		int cx=i.x, cy=i.y;
		v1.push_back({cx, cy, cx, cy+1});
		v1.push_back({cx, cy, cx, cy+2});
		v1.push_back({cx, cy, cx, cy-1});
		v1.push_back({cx, cy, cx, cy-2});
		v1.push_back({cx, cy, cx-1, cy+1});
		v1.push_back({cx, cy, cx-1, cy-1});
		v1.push_back({cx, cy, cx+1, cy-1});
		v1.push_back({cx, cy, cx+1, cy+1});
	}
	for(auto i:knw)
	{
		int cx=i.x, cy=i.y;
		v1.push_back({cx, cy, cx-1, cy-2});
		v1.push_back({cx, cy, cx-1, cy+2});
		v1.push_back({cx, cy, cx+1, cy-2});
		v1.push_back({cx, cy, cx+1, cy+2});
		v1.push_back({cx, cy, cx-2, cy-1});
		v1.push_back({cx, cy, cx-2, cy+1});
		v1.push_back({cx, cy, cx+2, cy-1});
		v1.push_back({cx, cy, cx+2, cy-1});
	}
	for(auto i:knb)
	{
		int cx=i.x, cy=i.y;
		v1.push_back({cx, cy, cx-1, cy-2});
		v1.push_back({cx, cy, cx-1, cy+2});
		v1.push_back({cx, cy, cx+1, cy-2});
		v1.push_back({cx, cy, cx+1, cy+2});
		v1.push_back({cx, cy, cx-2, cy-1});
		v1.push_back({cx, cy, cx-2, cy+1});
		v1.push_back({cx, cy, cx+2, cy-1});
		v1.push_back({cx, cy, cx+2, cy-1});
	}
	for(auto i:kw)
	{
		int cx=i.x, cy=i.y;
		for(int p=-1;p<=1;++p)
		{
			for(int q=-1;q<=1;++q)
				v1.push_back({cx, cy, cx+p, cy+q});
		}
	}
	for(auto i:kb)
	{
		int cx=i.x, cy=i.y;
		for(int p=-1;p<=1;++p)
		{
			for(int q=-1;q<=1;++q)
				v1.push_back({cx, cy, cx+p, cy+q});
		}
	}
	
	random_shuffle(v1.begin(), v1.end());
	for(auto z:v1)
	{
			bool t=1;
			for(auto n:z)
			{
				if(n<0 || n>7) t=0;
			} 
			if(!t) continue;
			int i=8*z[0]+z[1];
			int j=8*z[2]+z[3];
			if(alpha>=beta) break;
			
			bool b=move(i/8, i%8, j/8, j%8, 0);
			if(!b) continue;
			++nummoves;
			
			//cout<<i<<' '<<j<<'\n';
			//print();
			/*for(int i=7;i>=0;--i)
			{	
				for(int j=0;j<8;++j)
				{
					if(board1[j][i]<10) cout<<0;
					cout<<board1[j][i]<<' ';
				}
				cout<<'\n';
			}
			cout<<'\n';*/
			lastcol=1-lastcol;
			lastx=j/8;
			lasty=j%8;
			Destroy_Captures();
			
			if(depth<2) 
			{
				vector<int>v=minimax(1-color, depth+1, alpha, beta);
				if((color==0 && score<v[0]))
				{
					score=v[0];
					nextmove={i,j};
					alpha=max(alpha, score);
				}
				else if(color==1 && score>v[0])
				{
					score=v[0];
					nextmove={i,j};
					beta=min(beta, score);
				}

			}
			
			lastcol=1-lastcol;
			lastx=lastx1;
			lasty=lasty1;
			
			pw=pw1;pb=pb1;
			kw=kw1;kb=kb1;
			qw=qw1;qb=qb1;
			rw=rw1;rb=rb1;
			knw=knw1;knb=knb1;
			bw=bw1;bb=bb1;
			for(int i=0;i<8;++i) for(int j=0;j<8;++j) board[i][j]=board1[i][j];
	}
	
	
	if(nummoves==0)
	{
		if(color==0 && ischeck(kw[0].x, kw[0].y, 0)) return {-10000000, -1, -1};
		else if(color==1 && ischeck(kb[0].x, kb[0].y, 1)) return {10000000, -1, -1};
		else return {0, -1, -1};
	}
	
	if(depth==2) return {V,-1,-1};
	return {score, nextmove.first, nextmove.second};
}
