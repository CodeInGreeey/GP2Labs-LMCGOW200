//Header files
#include <iostream>

#include <SDL.h>


using namespace std;
//Global variables

//Pointer to our SDL window
SDL_Window *window;

//Constants to control window creation
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
bool running = true;


//Global functions
void InitWindow(int width, int height, bool fullScreen){

	window = SDL_CreateWindow("Lab 1", //Window title
		SDL_WINDOWPOS_CENTERED, //x position, centered
		SDL_WINDOWPOS_CENTERED, //y position, centered
		width, //width in pixels
		height, //height in pixels
		SDL_WINDOW_OPENGL //flags
		);



}

//Used to cleanup once we exit
void CleanUp(){

	SDL_DestroyWindow(window);
	SDL_Quit();

}

//Main method
int main(int argc, char* arg[]){

	//init everything - SDL, if it is nonzero we have a problem
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){

		cout << "ERROR SDL_Init " << SDL_GetError() << endl;
		return -1;

	}

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, false);

	SDL_Event event;


	CleanUp();

	return 0;


}