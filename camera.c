#include"camera.h"
void init_camera(Camera *cam,SDL_Rect posperso,int width,int height)
{
	cam->camera.x=posperso.x-(width*.5);
    cam->camera.y=posperso.y-(height*.5);
    cam->camera.w=width;
    cam->camera.h=height;
}

void poscamera(Camera *cam,SDL_Rect posperso,int width,int height)
{
	(cam->camera.x)=(posperso.x-posperso.w*.5)-(width*.5);
	
	(cam->camera.y)=(posperso.y-posperso.h*.5)-(height*.5);
	
	if((cam->camera.x)>=4000-width)
        {
            (cam->camera.x)=4000-width;
        }
    if(cam->camera.y>=4000-height)
        {
            (cam->camera.y)=4000-height;
        }
    if((cam->camera.x)<=0)
    	{
    		(cam->camera.x)=0;
    	}
    if((cam->camera.y)<=0)
    {
    	(cam->camera.y)=0;	
    }
}
