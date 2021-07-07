#include "bestmove.h"
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
int x11, y11, x2, y2;
string play;

bool initSDL();
void close();
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gsquare = NULL;

bool initSDL()
{
	bool success = true;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}
bool loadMedia(string path)
{
	gsquare = IMG_Load(path.c_str());
	return true;
}

void close()
{
	SDL_FreeSurface( gsquare );
	gsquare = NULL;
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	SDL_Quit();
}


bool Simulate(int x1, int y1, int x2, int y2)
{
		bool b=move(x1,y1,x2,y2,0);
		if(!b)
		{
			cout<<"INVALID MOVE\n";
			return false;
		}
		print();
		lastcol=1-lastcol;
		lastx=x2;
		lasty=y2;
		Destroy_Captures();
		
		bool moveleft=findmove(1-lastcol);
		bool mate;
		if(lastcol==1) mate=ischeck(kw[0].x, kw[0].y, 0);
		else mate=ischeck(kb[0].x, kb[0].y, 1);
		
		
		if(!moveleft && mate) 
		{
			cout<<"GAME ENDS!!, PLAYER ";
			if(lastcol==0) cout<<1; else cout<<2;
			cout<<" WINS!!";
			exit(0);
		}
		else if(!moveleft)
		{
			cout<<"DRAW BY STALEMATE:(";
			exit(0);
		}
		return true;
}

void Display(bool attack, int flip)
{
	int arr[8][8]={{0}};
	if(attack)
	{
		for(int i=0;i<8;++i)
		{
			for(int j=0;j<8;++j)
			{
				if(move(x11,y11,i,j,1))
					arr[i][j]=1;
			}
		}
	}
	for(int k=0;k<8;k++)
	{
		for(int l=0;l<8;l++)
		{
			SDL_Rect stretchRect;
			stretchRect.x = 100*k;
			stretchRect.y = 100*l;
			stretchRect.w = 100;
			stretchRect.h = 100;
			
			int x=k, y=7-l;
			if(flip)
			{
				x=7-x;
				y=7-y;
			}
			if((k+l)%2==0)
			{
				if(board[x][y]==0) 
				{
					if(arr[x][y]==1) 
						loadMedia("textures/colour/yellowmove.png");
					else
						loadMedia("textures/colour/yellow.png");
				}
				else if(board[x][y]==1)
					loadMedia("textures/pawn/ywpawn.png");
				else if(board[x][y]==11)
					loadMedia("textures/pawn/ybpawn.png");
				else if(board[x][y]==2)
					loadMedia("textures/knight/ywknight.png");
				else if(board[x][y]==12)
					loadMedia("textures/knight/ybknight.png");
				else if(board[x][y]==3)
					loadMedia("textures/bishop/ywbishop.png");
				else if(board[x][y]==13)
					loadMedia("textures/bishop/ybbishop.png");
				else if(board[x][y]==4)
					loadMedia("textures/rook/ywrook.png");
				else if(board[x][y]==14)
					loadMedia("textures/rook/ybrook.png");
				else if(board[x][y]==5)
					loadMedia("textures/queen/ywqueen.png");
				else if(board[x][y]==15)
					loadMedia("textures/queen/ybqueen.png");
				else if(board[x][y]==6)
					loadMedia("textures/king/ywking.png");
				else
					loadMedia("textures/king/ybking.png");
			}
			else
			{
				if(board[x][y]==0) 
				{
					if(arr[x][y]==1) 
						loadMedia("textures/colour/greenmove.png");
					else
						loadMedia("textures/colour/green.png");
				}
				else if(board[x][y]==1)
					loadMedia("textures/pawn/gwpawn.png");
				else if(board[x][y]==11)
					loadMedia("textures/pawn/gbpawn.png");
				else if(board[x][y]==2)
					loadMedia("textures/knight/gwknight.png");
				else if(board[x][y]==12)
					loadMedia("textures/knight/gbknight.png");
				else if(board[x][y]==3)
					loadMedia("textures/bishop/gwbishop.png");
				else if(board[x][y]==13)
					loadMedia("textures/bishop/gbbishop.png");
				else if(board[x][y]==4)
					loadMedia("textures/rook/gwrook.png");
				else if(board[x][y]==14)
					loadMedia("textures/rook/gbrook.png");
				else if(board[x][y]==5)
					loadMedia("textures/queen/gwqueen.png");
				else if(board[x][y]==15)
					loadMedia("textures/queen/gbqueen.png");
				else if(board[x][y]==6)
					loadMedia("textures/king/gwking.png");
				else
					loadMedia("textures/king/gbking.png");
			}
			
			SDL_BlitSurface( gsquare, NULL, gScreenSurface, &stretchRect);
			SDL_UpdateWindowSurface( gWindow );
				
		}
	}
}


bool Player(int flip)
{
			int cnt=0;
			
			SDL_Event e;
			
			while(cnt==0)
			{
				while( SDL_PollEvent( &e ) != 0)
				{
					    
					if( e.type == SDL_MOUSEBUTTONDOWN)
					{
						int x, y;
						++cnt;
						SDL_GetMouseState( &x, &y );	
						x11=x/100;
						y11=(int)(7-y/100);
						break;
					}
				}
			}
			if(flip)
			{
				x11=7-x11;
				y11=7-y11;
			}
			cnt=0;
			Display(1, flip);
			
			while(cnt==0)
			{
				while( SDL_PollEvent( &e ) != 0)
				{
					    
					if( e.type == SDL_MOUSEBUTTONDOWN)
					{
						int x, y;
						++cnt;
						SDL_GetMouseState( &x, &y );	
						x2=x/100;
						y2=7-y/100;
						break;
					}
				}
				if(cnt==1)
				{
					if(flip)
					{
						x2=7-x2;
						y2=7-y2;
					}
					bool w=move(x11,y11,x2,y2,1);
					if(w) break;
					else if(board[x2][y2]==0) 
					{
						Display(0,flip);
						return false;
					}
					else if((lastcol==1 && board[x2][y2]<10)||(lastcol==0 && board[x2][y2]>10))
					{
						x11=x2;
						y11=y2;
						Display(1,flip);
						cnt=0;
					}
					else
					{
						Display(0,flip);
						return false;
					}
					
				}
			}
			cnt=0;
			bool b=Simulate(x11,y11,x2,y2);
			return b;
}

bool Engine()
{
			for(int i=0;i<8;++i) for(int j=0;j<8;++j) boardcopy[i][j]=board[i][j];
			vector<int>v=minimax(1-lastcol, 0, -INF, INF);
			bool b=Simulate(v[1]/8, v[1]%8, v[2]/8, v[2]%8);
			cout<<v[1]/8<<' '<<v[1]%8<<' '<<v[2]/8<<' '<<v[2]%8<<'\n';
			return b;

}

int main(int argc, char *argv[])
{
	play=argv[1];
	
	srand(time(0));
	init();
	init_val();
	
	if( !initSDL() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		bool quit=false;
		
		/*Simulate(3,1,3,3);
		Simulate(2,6,2,5);
		Simulate(1,0,2,2);
		Simulate(3,7,0,4);
		Simulate(4,1,4,3);
		Simulate(0,4,1,4);
		Simulate(2,0,5,3);
		Simulate(1,4,4,1);
		assert(ischeck(4,0,0));*/
		
		while(!quit)
		{
		
			if(play=="W")
			{
				Display(0,0);
				
				bool b=false;
				while(b==false)
					b=Player(0);
					
				Display(0,0);
					
				b=false;
				while(b==false)
					b=Engine();
			}
			else if(play=="B")
			{
				Display(0,1);
				bool b=false;
				while(b==false)
					b=Engine();
					
				Display(0,1);
					
				b=false;
				while(b==false)
					b=Player(1);
		
			}
			else if(play=="M")
			{
				Display(0,0);
				
				bool b=false;
				while(b==false)
					b=Player(0);
					
					
				Display(0,1);
				
					
				b=false;
				while(b==false)
					b=Player(1);
			}
			else if(play=="E")
			{
				Display(0,0);
				bool b=false;
				while(b==false)
					b=Engine();
				
				SDL_Delay(1500);
				
				b=false;
				Display(0,0);
				while(b==false)
					b=Engine();
					
				SDL_Delay(1500);
				
				
				
			}
			
		}

		
		
		
	}
	close();
	return 0;
	
}
