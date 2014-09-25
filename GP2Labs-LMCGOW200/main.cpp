//Header files
#include <iostream>

#include <SDL.h>
#include <SDL_opengl.h>
#include <gl\GLU.h>


using namespace std;
//Global variables

//Pointer to our SDL window
SDL_Window *window;

//Constants to control window creation
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
bool running = true;
SDL_GLContext glContext = NULL;

//Initialise opengl
void InitOpenGL(){

	glContext = SDL_GL_CreateContext(window);

	if (!glContext){
		cout << "Error Creating OpenGL Context " << SDL_GetError() << endl;
	}

	//Smooth shading
	glShadeModel(GL_SMOOTH);

	//Clear the background to black
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//Clear the depth buffer to 1.0
	glClearDepth(1.0f);

	//Enable depth testing
	glEnable(GL_DEPTH_TEST);

	//The depth test to use
	glDepthFunc(GL_LEQUAL);

	//Turn on best perspective correction
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

//Function to set/reset viewport
void SetViewport(int width, int height){

}

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

	while (running){

		while (SDL_PollEvent(&event)){

			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE){
				//set our boolean which controls the game loop to false
				running = false; 
			}

		}

	}

	CleanUp();

	return 0;


}