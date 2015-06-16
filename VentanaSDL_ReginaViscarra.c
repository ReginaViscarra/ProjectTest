#include <SDL2/SDL.h>
#include <unistd.h>

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 500

int main( int argc, char** argv )
	{
	time_t t; int i = 0, quit = 0, j = 0, k = 0;
	int backr, backg, backb;
	srand( (unsigned) time(&t) );

	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL; 
	SDL_Event movement;
	
	if( SDL_Init(SDL_INIT_VIDEO) )
		{
		fprintf( stderr,"\nFallo al inciar SDL: %s\n",SDL_GetError() );
		return 1;
		}
	else if( SDL_Init(SDL_INIT_EVENTS) )
		{
		fprintf( stderr,"\nFallo al inciar SDL: %s\n",SDL_GetError() );
		return 1;
	}

	window = SDL_CreateWindow(
		"Tarea SDL", 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_OPENGL 
	);
	
	if( window == NULL ){
		fprintf( stderr,"no se pudo crear  %s", SDL_GetError() );
		return 1;
	}
	surface = SDL_GetWindowSurface( window ); 
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format,255, 0, 0)); //Va a iniciar en rojo siempre
	
	SDL_UpdateWindowSurface( window );
	while(!quit) 
		while( SDL_PollEvent(&movement) ){
			if(movement.type == SDL_QUIT){   //para cerrar ventana
				quit = 1;
			}
			if( movement.type == SDL_WINDOWEVENT){    //para cuando pierde foco
				if( movement.window.event == SDL_WINDOWEVENT_FOCUS_LOST ){
					SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format,135,136,137));
					SDL_UpdateWindowSurface( window );	
				}
			}
			if( movement.type == SDL_WINDOWEVENT ){
				if(movement.window.event == SDL_WINDOWEVENT_FOCUS_GAINED){
					SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format,
					backr,backg,backb));
					SDL_UpdateWindowSurface( window );
				}
			}
			if( movement.type == SDL_WINDOWEVENT ){   //cada vez que se mueve genera el color desde aqui
				if( movement.window.event == SDL_WINDOWEVENT_MOVED ){
					i = rand()%255; backr = i;
					j = rand()%255; backg = j;
					k = rand()%255; backb = k;
					SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format,i,j,k));
					SDL_UpdateWindowSurface( window );		
				}
			}
		}
	
	SDL_FreeSurface( surface );
	SDL_DestroyWindow( window );
	surface = NULL;
	window = NULL;    //limpiando
	SDL_Quit();
	return 0;
}

//si dejaba que escribiera el archivo, lo dejaba vacio 
