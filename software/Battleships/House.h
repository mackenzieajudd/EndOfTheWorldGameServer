#ifndef HOUSE_H_
#define HOUSE_H_

#define HOUSE_STARTING_HEALTH 100

//NOT USED IN CURRENT VERSION
struct House
{
	char valid;

	char health;

	char id;

	char x1;
	char y1;
	char x2;
	char y2;
};

void InitialiseHouse(struct House* house);
struct House GetInitialisedHouse();

#endif
