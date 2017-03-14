#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Monster ;
class Room ;

using namespace std;
class Object
{
protected:
	string name ;
	string description;
public:
	Object ();
    virtual bool act()=0;
    virtual ~Object(){}
};

#endif // OBJECT_H
