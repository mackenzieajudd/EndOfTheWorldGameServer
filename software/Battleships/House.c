#include "House.h"

void InitialiseHouse(struct House* house)
{
	(*house).valid = 0;

	(*house).health = HOUSE_STARTING_HEALTH;

	(*house).id = 0;

	(*house).x1 = 0;
	(*house).y1 = 0;
	(*house).x2 = 0;
	(*house).y2 = 0;
}

struct House GetInitialisedHouse()
{
	struct House house;
	InitialiseHouse(&house);
	return house;
}
