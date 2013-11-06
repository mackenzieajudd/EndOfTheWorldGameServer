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

void PublishEvent(EVENT event, PLAYER player, unsigned char eventData[])
{
	int i;

	unsigned char numBytesInEvent = (unsigned char)strlen((const char*)eventData);

	// Start with the number of bytes in our message
	alt_up_rs232_write_data(serialConnection, PLAYER_ID_SIZE + EVENT_TYPE_SIZE + numBytesInEvent);

	//Send Event Type
	alt_up_rs232_write_data(serialConnection, event);

	//Send Player ID
	alt_up_rs232_write_data(serialConnection, player);

	//Send Event Data
	for (i = 0; i < numBytesInEvent; i++)
		alt_up_rs232_write_data(serialConnection, eventData[i]);
}

void ReceiveCommand()
{
	unsigned char parity;
	unsigned char player;
	unsigned char command;
	unsigned char dataSize;
	int commandSize;

	int i;

	//Get Command Length
	alt_up_rs232_read_data(serialConnection, &dataSize, &parity);
	commandSize = (int)dataSize - PLAYER_ID_SIZE - COMMAND_TYPE_SIZE;

	//Get Command Type
	while (alt_up_rs232_get_used_space_in_read_FIFO(serialConnection) == 0);
	alt_up_rs232_read_data(serialConnection, &command, &parity);

	//Get Player ID
	while (alt_up_rs232_get_used_space_in_read_FIFO(serialConnection) == 0);
	alt_up_rs232_read_data(serialConnection, &player, &parity);

	//Allocate Memory for Command
	unsigned char* commandData = malloc(commandSize);

	//Fill up Command with Command Data
	for (i = 0; i < commandSize; i++)
	{
		while (alt_up_rs232_get_used_space_in_read_FIFO(serialConnection) == 0);
		alt_up_rs232_read_data(serialConnection, &commandData[i], &parity);
	}

	HandleCommand((COMMAND)command, (PLAYER)player, commandData);
}

void CheckForCommand()
{
	//Check if there are any commands ready to be received
	if(alt_up_rs232_get_used_space_in_read_FIFO(serialConnection) >= 1)
		ReceiveCommand();
}

void HandleCommand(COMMAND command, PLAYER player, unsigned char commandData[])
{
	switch(command)
	{
		case REQUEST_ID:
			HandleRequestId(commandData);
			break;
		case QUIT:
			HandleQuit(player);
			break;
		case READY:
			HandleReady(player);
			break;
	}
}
