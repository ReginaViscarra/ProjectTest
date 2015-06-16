

void cerrar(SDL_Surface** lienzo, SDL_window** ventana int v, int l ){
	int i;
	for( i = 0; i < l; i++ ){
		SDL_FreeSurface( (lienzo[i]) );
		(lienzo[i]) = NULL;
	}
	for( i = 0; i < v; i++ ){
		SDL_Destroywindow( (ventana[i]) );
		(ventana[i]) = NULL;
	}
	exit(0);
}



cerrar(&ventana,&lienzoPrincipal);

