#include <iostream>
#include <string>
#include <random>
#include <thread>
#include <chrono>
using namespace std;

int delay;
int amountOfChars;

const string BLACK = "\u001b[30m";
const string RED = "\u001b[31m";
const string GREEN = "\u001b[32m";
const string YELLOW = "\u001b[33m";
const string BLUE = "\u001b[34m";
const string MAGENTA = "\u001b[35m";
const string CYAN = "\u001b[36m";
const string WHITE = "\u001b[37m";

string inputColor;
string outputColor;

string lower(string input)
{
	string output = ""; // declare and initialise an empty output string
	for (int i = 0; i<input.length(); i++) // loop through the array
	{
		char lowerChar = char(tolower(input[i])); // make a lowercase character with a c++ given funtion (not casting to a char does not work)
		output += lowerChar; // output is being "built" with the lowercase characters
	}
	return output;
}

void chooseColor()
{
	cout << "Enter the color (black, red, green, yellow, blue, magenta, cyan, white) : ";
	cin >> inputColor;
	inputColor = lower(inputColor);           

	if(inputColor == "black")
	{
		outputColor = BLACK;
	}
	else if(inputColor == "red")
	{
		outputColor = RED;
	}
	else if(inputColor == "green")
	{
		outputColor = GREEN;
	}
	else if(inputColor == "yellow")
	{
		outputColor = YELLOW;
	}
	else if(inputColor == "blue")
	{
		outputColor = BLUE;
	}
	else if(inputColor == "magenta")
	{
		outputColor = MAGENTA;
	}
	else if(inputColor == "cyan")
	{
		outputColor = CYAN;
	}
	else if(inputColor == "white")
	{
		outputColor = WHITE;
	}
	else
	{
		chooseColor();
	}
}

void sleep(int ms)
{
	this_thread::sleep_for(chrono::milliseconds(ms));
}

int main()
{
	cout << "Enter the delay (milliseconds) : ";
	cin >> delay;

	cout << "Enter the amount of characters to fill the screen: ";
	cin >> amountOfChars;
	
	chooseColor();

	while(1) // infinite loop
	{
		for(int i = 0; i<amountOfChars; i++)
		{
			int randomNumber = rand() % 2; // get a random number between 0 and 1
			cout << outputColor << randomNumber << " "; // output the random number with the chosen color
		}
		cout << "\n";
		sleep(delay);
	}
	return 0;
}
