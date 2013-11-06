#ifndef HOUSE_H_
#define HOUSE_H_

#define HOUSE_STARTING_HEALTH 100

struct House
{
	int valid;

	int health;

	int x1;
	int y1;
	int x2;
	int y2;
};

void InitialiseHouse(struct House* house);
struct House GetInitialisedHouse();

#endif
