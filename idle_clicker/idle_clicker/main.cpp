#include "idle_clicker_helper.h"

bool shouldKeepRunning = true;
int bits = 0;
int bytes = 0;
int cpus = 0;

void update()
{
	bits += cpus * 1;

	while (bits >= 8)
	{
		bits = bits - 8;
		bytes = bytes + 1;
	}
}

void draw()
{
	system("cls");
	std::cout << "You have " << bits << " bits!" << std::endl;
	if (bytes > 0)
	{
		std::cout << "You have " << bytes << " bytes!" << std::endl;
	}
	if (cpus > 0)
	{
		std::cout << "You have " << cpus << " CPU's!" << std::endl;
	}
}

void handleKey(char c)
{
	//If the user hits the 'q' key, quit the program
	if (c == 'q')
	{
		std::cout << "Should quit!" << std::endl;
		shouldKeepRunning = false;
	}

	if (c == '1')
	{
		bits = bits + 1;

		
		draw();

	}

	if (c == '2')
	{
		if (bytes >= 18)
		{
			bytes -= 18;
			cpus++;
			draw();
		}
		else
		{
			std::cout << "You are poor, can't do!\n";
		}
	}


}


//Needs more commenting!
int main()
{
	AsyncKeyboard::setupKeyboard(handleKey);

	while (shouldKeepRunning) 
	{
		update();
		draw();
		std::this_thread::sleep_for(1s);
	}

	AsyncKeyboard::shutdown();

	return 0;
}