#ifndef ShareControl
#include"FrkContent.h"
#include"FrkGraphic.h"
#include"FrkKeyboard.h"
#include"Object.h"
#include <map>
class Object;
class QNode;
#define ShareControl

typedef map<int, Object*>mapObject;
typedef map<int, QNode*>mapQNode;
extern FrkGraphic* _LocalGraphic;
extern FrkContent* _LocalContent;
extern FrkKeyboard* _LocalKeyboard;
extern float Zoom;
extern float _delay;
extern float _LocalTimeDelay;
extern RECT R_Viewport;
extern Object* _LocalHero;
#endif ShareControl