#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;


int main()
{
	int combos[16] = { 1,1,-1,1,1,-1,-1,-1,1,0,0,1,-1,0,0,-1 };

	char buffer[25 * 25] = {};
	for (int i = 0; i < sizeof(buffer); i++)
	{
		int randbroj = rand() % 5;
		if (randbroj == 1 || randbroj == 2 || randbroj == 3 || randbroj == 4)
		{
			buffer[i] = '.';
		}
		else
		{
			buffer[i] = '*';
		}
	}

	char screen[25 * 25] = {};
	for (int i = 0; i < sizeof(screen); i++)
	{
		int randbroj = rand() % 5;
		if (randbroj == 1 || randbroj == 2 || randbroj == 3 || randbroj == 4)
		{
			screen[i] = '.';
		}
		else
		{
			screen[i] = '*';
		}
	}

	srand(time(NULL));
	int lastTime = duration_cast<seconds>(system_clock::now().time_since_epoch()).count() + 0.25;
	while (true)
	{
		if (duration_cast<seconds>(system_clock::now().time_since_epoch()).count() - lastTime > 0.25)
		{
			system("cls");
			lastTime = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
			for (int i = 0; i < 25; i++)
			{
				for (int j = 0; j < 25; j++)
				{
					screen[25 * i + j] = buffer[25 * i + j];
				}
			}
			for (int i = 0; i < 25; i++)
			{
				for (int j = 0; j < 25; j++)
				{
					cout << screen[25 * i + j];
					int neighbors = 0;
					for (int k = 0; k < 8; k++)
					{
						if (screen[25 * ((i + combos[2 * k]) % 25) + (j + combos[2 * k + 1]) % 25] == '*')
						{
							neighbors++;
						}
					}
					if (screen[25 * i + j] == '*')
					{
						if (neighbors < 2)
						{
							buffer[25 * i + j] = '.';
						}
						else if (neighbors < 4)
						{
							buffer[25 * i + j] = '*';
						}
						else
						{
							buffer[25 * i + j] = '.';
						}
					}
					else
					{
						if (neighbors == 3)
						{
							buffer[25 * i + j] = '*';
						}
					}
				}
				cout << endl;
			}
		}
	}
}