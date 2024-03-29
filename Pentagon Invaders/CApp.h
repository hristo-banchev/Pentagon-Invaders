#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/glut.h>

#include "Scene.h"
#include "WaveMaker.h"
#include "BulletMaker.h"
 
class CApp {
private:
	bool Running;

	SDL_Window*	sdlWindow;

	Scene* scene;
	WaveMaker waveMaker;
	BulletMaker bulletMaker;
 
public:
    CApp();
 
    int OnExecute();
 
public:
 
    bool OnInit();
 
    void OnEvent(SDL_Event& event);

    void OnLoop();
 
    void OnRender();
 
    void OnCleanup();
};

#endif