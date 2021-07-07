#include "destroy.h"
using namespace std;

bool move(int x1, int y1, int x2, int y2, int revert)
{
		int board1[8][8];
		for(int i=0;i<8;++i) for(int j=0;j<8;++j) board1[i][j]=board[i][j];
		int col=0, val=board[x1][y1];
		
		if(val==0)
		{
			return false;
		}
		if(board[x1][y1]>=10) 
		{
			col=1;
			val-=10;
		}
		
		if(lastcol==col)
		{
			return false;
		}
		
		bool b=false;
		
		if(col==0)
		{
			if(val==1)
			{
				for(int i=0;i<pw.size();++i)
				{
					if(pw[i].x==x1 && pw[i].y==y1)
					{
						b=pw[i].validmove(x1,y1,x2,y2);
						if(!b) continue;
						pw[i].x=x2;
						pw[i].y=y2;
						if(ischeck(kw[0].x, kw[0].y, 0))
						{
							pw[i].x=x1;
							pw[i].y=y1;
							b=false;
							continue;
						}
						if(revert)
						{
							pw[i].x=x1;
							pw[i].y=y1;
						}
						break;
					}
				}
			}
			else if(val==2)
			{
				for(int i=0;i<knw.size();++i)
				{
					if(knw[i].x==x1 && knw[i].y==y1)
					{
						b=knw[i].validmove(x1,y1,x2,y2);
						if(!b) continue;
						knw[i].x=x2;
						knw[i].y=y2;
						if(ischeck(kw[0].x, kw[0].y, 0))
						{
							knw[i].x=x1;
							knw[i].y=y1;
							b=false;
							continue;
						}
						if(revert)
						{
							knw[i].x=x1;
							knw[i].y=y1;
						}
						break;
					}
				}
			}
			else if(val==3)
			{
				for(int i=0;i<bw.size();++i)
				{
					if(bw[i].x==x1 && bw[i].y==y1)
					{
						b=bw[i].validmove(x1,y1,x2,y2);
						if(!b) continue;
						bw[i].x=x2;
						bw[i].y=y2;
						if(ischeck(kw[0].x, kw[0].y, 0))
						{
							bw[i].x=x1;
							bw[i].y=y1;
							b=false;
							continue;
						}
						if(revert)
						{
							bw[i].x=x1;
							bw[i].y=y1;
						}
						break;
					}
				}
			}
			else if(val==4)
			{
				for(int i=0;i<rw.size();++i)
				{
					if(rw[i].x==x1 && rw[i].y==y1)
					{
						bool z=rw[i].castle;
						b=rw[i].validmove(x1,y1,x2,y2);
						if(!b) continue;
						rw[i].x=x2;
						rw[i].y=y2;
						rw[i].castle=false;
						if(ischeck(kw[0].x, kw[0].y, 0))
						{
							rw[i].x=x1;
							rw[i].y=y1;
							rw[i].castle=z;
							b=false;
							continue;
						}
						if(revert)
						{
							rw[i].x=x1;
							rw[i].y=y1;
							rw[i].castle=z;
						}
						break;
					}
				}
			}
			else if(val==5)
			{
				for(int i=0;i<qw.size();++i)
				{
					if(qw[i].x==x1 && qw[i].y==y1)
					{
						b=qw[i].validmove(x1,y1,x2,y2);
						if(!b) continue;
						qw[i].x=x2;
						qw[i].y=y2;
						if(ischeck(kw[0].x, kw[0].y, 0))
						{
							qw[i].x=x1;
							qw[i].y=y1;
							b=false;
							continue;
						}
						if(revert)
						{
							qw[i].x=x1;
							qw[i].y=y1;
						}
						break;
					}
				}
			}
			else 
			{
				for(int i=0;i<kw.size();++i)
				{
					if(kw[i].x==x1 && kw[i].y==y1)
					{
						bool z=kw[i].castle;
						int x111=rw[0].x, y111=rw[0].y, c111=rw[0].castle;
						int x222=rw[1].x, y222=rw[1].y, c222=rw[1].castle;
						b=kw[i].validmove(x1,y1,x2,y2, rw[0], rw[1]);
			
						if(!b) continue;
						kw[i].x=x2;
						kw[i].castle=false;
						kw[i].y=y2;
						if(ischeck(kw[0].x, kw[0].y, 0))
						{
							kw[i].x=x1;
							kw[i].y=y1;
							kw[i].castle=z;
							rw[0].x=x111;rw[0].y=y111;rw[0].castle=c111;
							rw[1].x=x222;rw[1].y=y222;rw[1].castle=c222;
							b=false;
							continue;
						}
						if(revert)
						{
							kw[i].x=x1;
							kw[i].y=y1;
							kw[i].castle=z;
							rw[0].x=x111;rw[0].y=y111;rw[0].castle=c111;
							rw[1].x=x222;rw[1].y=y222;rw[1].castle=c222;
						}
						break;
					}
				}
			}
		}
		else
		{
			if(val==1)
			{
				for(int i=0;i<pb.size();++i)
				{
					if(pb[i].x==x1 && pb[i].y==y1)
					{
						b=pb[i].validmove(x1,y1,x2,y2);
						if(!b) continue;
						pb[i].x=x2;
						pb[i].y=y2;
						if(ischeck(kb[0].x, kb[0].y, 1))
						{
							pb[i].x=x1;
							pb[i].y=y1;
							b=false;
							continue;
						}
						if(revert)
						{
							pb[i].x=x1;
							pb[i].y=y1;
						}
						break;
					}
				}
			}
			else if(val==2)
			{
				for(int i=0;i<knb.size();++i)
				{
					if(knb[i].x==x1 && knb[i].y==y1)
					{
						b=knb[i].validmove(x1,y1,x2,y2);
						if(!b) continue;
						knb[i].x=x2;
						knb[i].y=y2;
						if(ischeck(kb[0].x, kb[0].y, 1))
						{
							knb[i].x=x1;
							knb[i].y=y1;
							b=false;
							continue;
						}
						if(revert)
						{
							knb[i].x=x1;
							knb[i].y=y1;
						}
						break;
					}
				}
			}
			else if(val==3)
			{
				for(int i=0;i<bb.size();++i)
				{
					if(bb[i].x==x1 && bb[i].y==y1)
					{
						b=bb[i].validmove(x1,y1,x2,y2);
						if(!b) continue;
						bb[i].x=x2;
						bb[i].y=y2;
						if(ischeck(kb[0].x, kb[0].y, 1))
						{
							bb[i].x=x1;
							bb[i].y=y1;
							b=false;
							continue;
						}
						if(revert)
						{
							bb[i].x=x1;
							bb[i].y=y1;
						}
						break;
					}
				}
			}
			else if(val==4)
			{
				for(int i=0;i<rb.size();++i)
				{
					if(rb[i].x==x1 && rb[i].y==y1)
					{
						bool z=rb[i].castle;
						b=rb[i].validmove(x1,y1,x2,y2);
						if(!b) continue;
						rb[i].x=x2;
						rb[i].y=y2;
						rb[i].castle=false;
						if(ischeck(kb[0].x, kb[0].y, 1))
						{
							rb[i].x=x1;
							rb[i].y=y1;
							rb[i].castle=z;
							b=false;
							continue;
						}
						if(revert)
						{
							rb[i].x=x1;
							rb[i].y=y1;
							rb[i].castle=z;
						}
						break;
					}
				}
			}
			else if(val==5)
			{
				for(int i=0;i<qb.size();++i)
				{
					if(qb[i].x==x1 && qb[i].y==y1)
					{
						b=qb[i].validmove(x1,y1,x2,y2);
						if(!b) continue;
						qb[i].x=x2;
						qb[i].y=y2;
						if(ischeck(kb[0].x, kb[0].y, 1))
						{
							qb[i].x=x1;
							qb[i].y=y1;
							b=false;
							continue;
						}
						if(revert)
						{
							qb[i].x=x1;
							qb[i].y=y1;
						}
						break;
					}
				}
			}
			else 
			{
				for(int i=0;i<kb.size();++i)
				{
					if(kb[i].x==x1 && kb[i].y==y1)
					{
						int x111=rb[0].x, y111=rb[0].y, c111=rb[0].castle;
						int x222=rb[1].x, y222=rb[1].y, c222=rb[1].castle;
						bool z=kb[i].castle;
						b=kb[i].validmove(x1,y1,x2,y2, rb[0], rb[1]);
						if(!b) continue;
						kb[i].x=x2;
						kb[i].y=y2;
						kb[i].castle=false;
						if(ischeck(kb[0].x, kb[0].y, 1))
						{
							kb[i].x=x1;
							kb[i].y=y1;
							kb[i].castle=z;
							rb[0].x=x111;rb[0].y=y111;rb[0].castle=c111;
							rb[1].x=x222;rb[1].y=y222;rb[1].castle=c222;
							b=false;
							continue;
						}
						if(revert)
						{
							kb[i].x=x1;
							kb[i].y=y1;
							kb[i].castle=true;
							rb[0].x=x111;rb[0].y=y111;rb[0].castle=c111;	
							rb[1].x=x222;rb[1].y=y222;rb[1].castle=c222;				
						}
						break;
					}
				}
			}	
		}
		
		if(!b)
		{
			for(int i=0;i<8;++i) for(int j=0;j<8;++j) board[i][j]=board1[i][j];
			return false;
		}
		if(revert) for(int i=0;i<8;++i) for(int j=0;j<8;++j) board[i][j]=board1[i][j];
		return true;
}

bool findmove(int color)
{
	for(int i=0;i<64;++i)
	{
		for(int j=0;j<64;++j)
		{
			if(board[i/8][i%8]==0) continue;
			if(color==0 && board[i/8][i%8]>10) continue;
			if(color==1 && board[i/8][i%8]<10) continue;
			if(move(i/8, i%8, j/8, j%8, 1))
			{
				//cout<<i/8<<' '<<i%8<<' '<<j/8<<' '<<j%8<<'\n';
				return true;
			}
		}
	}
	return false;
}
