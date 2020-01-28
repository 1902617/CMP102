#include <Robot.h>
#include <GraphicsManager.h>

class MyRobot :
	public Robot
{
public:
	void move(int);
	void back();
	void goTo(int, int, GraphicsManager*);
	void teleport(int, int, GraphicsManager*);
	void anotherLogOnTheFire();


	int backDir;
	int invBackDir;
	int currX;
	int currY;
};