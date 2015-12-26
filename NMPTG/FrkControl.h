#ifndef FrkControl
#include"FrkContent.h"
#include"FrkGraphic.h"
#include"FrkKeyboard.h"
#include "Object.h"
#define FrkControl

FrkGraphic* _LocalGraphic;
FrkContent* _LocalContent;
FrkKeyboard* _LocalKeyboard;
float Zoom = 1.0f;
RECT R_Viewport;
Object* _LocalHero;
float _LocalTimeDelay = 0;

#endif FrkControl