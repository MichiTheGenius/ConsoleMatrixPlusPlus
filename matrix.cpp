#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <random>
using namespace std;

class Color{
	public:
		string black = "\u001b[30m";
		string red = "\u001b[31m";
		string green = "\u001b[32m";
		string yellow = "\u001b[33m";
		string blue = "\u001b[34m";
		string magenta = "\u001b[35m";
		string cyan = "\u001b[36m";
		string white = "\u001b[37m";
		string reset = "\u001b[0m";
};

Color color; // make a new color object in order to use it

void sleep(int milliseconds)
{
	this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void matrix()
{

	cout << "Enter the delay in milliseconds: ";
	int delay;
	cin >> delay;

	cout << "Enter the number of characters you want: ";
	int numberOfCharacters;
	cin >> numberOfCharacters;

	system("clear"); // clear console
	while(1)
	{
		for(int i = 0; i < numberOfCharacters; i++)
		{
			int randomNumber = rand() % 2;
			cout << color.green << randomNumber << " ";
		}
		cout << "\n";
		sleep(delay);
	}

}

int main()
{
	matrix();
	cout << color.reset; // reset color after exiting program
	return 0;
}
