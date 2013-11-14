#include "Communications.h"

alt_up_rs232_dev* serialConnection;

void InitialiseCommunications()
{
	unsigned char data;
	unsigned char parity;

	serialConnection = alt_up_rs232_open_dev(SERIAL_NAME);

	//Clear Buffer
	while (alt_up_rs232_get_used_space_in_read_FIFO(serialConnection))
		alt_up_rs232_read_data(serialConnection, &data, &parity);
}

void PublishEvent(char playerId, EVENT event,  unsigned char eventData[])
{
	int i;

	char numBytesInEvent = strlen((const char*)eventData);
	//printf("length: %d\n", strlen(eventData));
	//printf("length calced: %d\n", numBytesInEvent);
	//Send Player ID
	alt_up_rs232_write_data(serialConnection, playerId);
	//printf("player: %d\n", playerId);

	// Start with the number of bytes in our message
	alt_up_rs232_write_data(serialConnection, EVENT_TYPE_SIZE + numBytesInEvent);
	//printf("size: %d\n", EVENT_TYPE_SIZE + numBytesInEvent);

	//Send Event Type
	alt_up_rs232_write_data(serialConnection, event);

	//printf("event: %d\n", event);

	//Send Event Data
	for (i = 0; i < numBytesInEvent; i++)
		alt_up_rs232_write_data(serialConnection, eventData[i]);
}

void ReceiveCommand()
{
	unsigned char parity;
	unsigned char playerId;
	unsigned char command;
	unsigned char dataSize;
	int commandSize;

	int i;

	//Get Player ID
	while (alt_up_rs232_get_used_space_in_read_FIFO(serialConnection) == 0);
	alt_up_rs232_read_data(serialConnection, &playerId, &parity);

	//Get Command Length (BUG: sent twice so I read it twice)
	//while (alt_up_rs232_get_used_space_in_read_FIFO(serialConnection) == 0);
	//alt_up_rs232_read_data(serialConnection, &dataSize, &parity);
	while (alt_up_rs232_get_used_space_in_read_FIFO(serialConnection) == 0);
	alt_up_rs232_read_data(serialConnection, &dataSize, &parity);
	commandSize = (int)dataSize - COMMAND_TYPE_SIZE;

	//Get Command Type
	while (alt_up_rs232_get_used_space_in_read_FIFO(serialConnection) == 0);
	alt_up_rs232_read_data(serialConnection, &command, &parity);

	//Allocate Memory for Command
	unsigned char* commandData = malloc(commandSize);

	//Fill up Command with Command Data
	for (i = 0; i < commandSize; i++)
	{
		while (alt_up_rs232_get_used_space_in_read_FIFO(serialConnection) == 0);
		alt_up_rs232_read_data(serialConnection, &commandData[i], &parity);
	}

	HandleCommand(playerId, (COMMAND)command, commandData);
}

void CheckForCommand()
{
	//Check if there are any commands ready to be received
	if(alt_up_rs232_get_used_space_in_read_FIFO(serialConnection) >= 1)
	{
		ReceiveCommand();
	}
}

void HandleCommand(char playerId, COMMAND command, unsigned char commandData[])
{
	switch(command)
	{
		case REQUEST_ID:
			HandleRequestId(playerId);
			break;
		case QUIT:
			HandleQuit(playerId);
			break;
		case READY:
			HandleReady(playerId, commandData);
			break;
		case PLACE_HOUSE:
			HandlePlaceHouse(playerId, commandData);
			break;
		case PLAYER_ATTACK:
			HandleAttack(playerId, commandData);
			break;
		case MESSAGE:
			HandleMessage(playerId, commandData);
			break;
		default:
			printf("Unrecognised command %d from player %s\n", command, PlayerEnumToString(PlayerIdToPlayer(playerId)));
	}
}
