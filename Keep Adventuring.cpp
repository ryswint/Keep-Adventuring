//Ryan Swint
//Fall 2021 Chapter 5
//Module 6

//Do You Want to Keep Adventuring?
//https://github.com/ryswint
#include <Windows.h>
#include <iostream>
using namespace std;
//===========================================GLOBAL VARIABLES=====================================================//
const int waitTime = 1000;
const int typeTime = 25;

int health = 20;
int totalTreasure = 0;

//===========================================USER DEFINED FUNCTIONS===============================================//
void Report(string report, bool newLine = true)
{
	if (newLine)
	{
		cout << endl << time(NULL) << ": ";
	}

	for (int i = 0; i < report.length(); i++)
	{
		cout << report[i];
		Sleep(typeTime);
	}

	Sleep(waitTime);
}

void Success()
{
	system("Color 02");
	Sleep(50);
	system("Color 20");
	Sleep(50);
	system("Color 02");
	Sleep(50);
	system("Color 20");
	Sleep(50);
	system("Color 02");
	Sleep(50);
	system("Color 20");
	Sleep(50);
}

void Invalid()
{
	system("Color 40");
	Sleep(50);
	system("Color 04");
	Sleep(50);
	system("Color 40");
	Sleep(50);
	system("Color 04");
	Sleep(50);
	system("Color 40");
	Sleep(50);
	system("Color 04");
	Sleep(50);

}

void Block()
{
	system("Color 10");
	Sleep(50);
	system("Color 01");
	Sleep(50);
	system("Color 10");
	Sleep(50);
	system("Color 01");
	Sleep(50);
	system("Color 10");
	Sleep(50);
	system("Color 01");
	Sleep(50);
}
void Login()
{
	string loading = "-\|/- ";
	system("Color 02");
	Report("-*H.E.R.O.S. SHIP COMPUTER SYSTEM -- NSS OPPOSITION NS1473-- MAIN BATTLE GROUP*-", 0);
	cout << endl;
	Report("SYSTEM ACCESS REQUESTED............", 1);


	Report("ACCESS KEY REQUIRED: ", 1);



	for (int i = 0; i < 10; i++)
	{


		cout << "*";
		Sleep((rand() % 400 + 1) * 2);

	}

	cout << endl;

	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "\b";
			cout << loading[i];
			Sleep(200);

		}
	}

	Success();
	system("Color 02");

	Report("KEY VERIFIED");

	cout << endl;

	Report("INITIALIZING CONNECTION");

	for (int i = 0; i < 15; i++)
	{
		Sleep(100);
		cout << ".";
	}
	for (int i = 0; i < 15; i++)
	{
		Sleep(50);
		cout << ".";
	}


	for (int i = 0; i < 1000; i++)
	{
		cout << endl;

		for (int i = 0; i < 75; i++)
		{

			cout << rand() % 2;


		}
	}

	system("cls");
	for (int i = 0; i < 3; i++)
	{
		Sleep(150);
		cout << "*SYSTEM ACCESS GRANTED*";
		Sleep(150);
		system("cls");
	}

}

bool AskYesNo()
{
	bool contMission;
	int answerLoop = 1;
	char answer;
	char answerCap;
	while (answerLoop)
	{

		cout << endl << "INITIATE COMBAT? (y/n) ";
		cin >> answer;
		answerCap = toupper(answer);
		switch (answerCap)
		{
		case 'Y':
			Success();


			answerLoop = false;
			contMission = true;
			break;
		case 'N':
			Success();
			answerLoop = false;
			contMission = false;
			break;
		default:
			Invalid();
			Report("INVALID ENTRY");
			answerLoop = true;
		}
	}
	return contMission;
}

int RollDie(bool output = false)
{
	int roll = rand() % 6 + 1;
	if (output)
	{
		cout << endl;
		Report("THE DIE ROLLS AND STOPS AT: ");
		cout << roll << endl;
	}
	return roll;
}

void Story()
{
	Login();
	system("Color 09");
	Report("-*H.E.R.O.S. COMMUNICATION NETWORK*-", 0);

	cout << endl;

	Report("INCOMING COMMUNICATION FROM COMMAND.......");

	cout << endl;

	Report("This is Commander Nemlock.");
	Report("After your 'success' with the Bridge Troll, you have been selected for a new mission.");
	Report("You were also the only other survivor.");
	Report("That is why I knocked you out and sent you to the surface of this planet.");
	Report("I need you to take out enemies and collect their 'treasure'.");
	Report("The creatures of this planet carry crystals that can power our ship.");
	Report("Some creatures are harder than others, but they will be carrying more crystals.");
	Report("I'm hoping that you can use your stupid luck to pull this off.");
	Report("Collect as much as you can, but don't die.");
	Report("You are the only one that can bring the crystals back to the ship.");
	Report("I don't care if you get hurt, just don't die.");
	cout << endl;
	system("pause");
	system("cls");
	system("color 02");
	Report("LOADING H.E.R.O.S. COMBAT SYSTEM", 0);
	for (int i = 0; i < 15; i++)
	{
		Sleep(100);
		cout << ".";
	}
	for (int i = 0; i < 15; i++)
	{
		Sleep(50);
		cout << ".";
	}

	system("cls");
	for (int i = 0; i < 3; i++)
	{
		Sleep(150);
		cout << "*H.E.R.O.S. COMBAT SYSTEM LOADED SUCCESSFULLY*";
		Sleep(150);
		system("cls");
		system("color 40");
	}
}

void Adventure()
{
	system("cls");
	system("color 40");
	Report("-*H.E.R.O.S. COMBAT SYSTEM*-", 0);
	cout << endl;
	int difficulty = RollDie();
	string currentEnemy;
	int attack;
	int block;
	int spoils;
	int tempSpoils;
	int tempHealth;

	switch (difficulty)
	{
	case 1:
		currentEnemy = "Trog";
		break;
	case 2:
		currentEnemy = "Goblin";
		break;
	case 3:
		currentEnemy = "Orc";
		break;
	case 4:
		currentEnemy = "Ogre";
		break;
	case 5:
		currentEnemy = "Demon";
		break;
	case 6:
		currentEnemy = "Troll Ghost";
		break;
	}

	Report("ENEMY DETECTED!");
	Report("DESIGNATION: " + currentEnemy);
	Report("ATTACK = ROLL + ");
	cout << (difficulty - 1) / 2;
	cout << endl;

	attack = RollDie(1) + (difficulty - 1) / 2;

	Report("INCOMING ATTACK FROM " + currentEnemy + ": ");
	cout << attack;

	block = RollDie(1);
	Report("BLOCK VALUE: ");
	cout << block;

	if (attack > block) //Block Fail
	{
		system("color 40");
		Report("BLOCK FAILED!");
		cout << endl;
		Report("HEALTH: ");
		cout << health;
		Sleep(1000);
		tempHealth = health;
		for (int i = 0; i < attack; i++)
		{
			Sleep(50);
			if (tempHealth > 99)
			{
				cout << "\b\b\b" << " ";

			}
			else if (tempHealth == 10)
			{
				cout << "\b\b" << " ";
			}
			else if (tempHealth > 9)
			{
				cout << "\b\b";
			}
			else
			{
				cout << "\b";
			}
			tempHealth--;
			system("Color 40");
			Sleep(50);
			system("Color 04");
			Sleep(50);
			system("color 40");
			cout << tempHealth;
		}
		health -= attack;

		Report("TREASURE STOCKPILE: ");
		cout << totalTreasure;


	}
	else //Block Successful
	{

		Block();
		system("color 40");
		Report("BLOCK SUCCESSFUL!");
		spoils = difficulty * RollDie();
		Report("TREASURE ADDED TO STOCKPILE: ");
		cout << spoils;
		cout << endl;
		Report("HEALTH: ");
		cout << health;
		Report("TREASURE STOCKPILE: ");
		cout << totalTreasure;
		Sleep(1000);
		tempSpoils = totalTreasure;
		for (int i = 0; i < spoils; i++)
		{
			Sleep(50);
			if (tempSpoils > 99)
			{
				cout << "\b\b\b";

			}
			else if (tempSpoils > 9)
			{
				cout << "\b\b";
			}
			else
			{
				cout << "\b";
			}
			tempSpoils++;
			system("Color 02");
			Sleep(50);
			system("Color 20");
			Sleep(50);
			system("color 40");
			cout << tempSpoils;
		}
		totalTreasure = totalTreasure + spoils;
	}


}

void Ending()
{
	system("Color 90");
	system("Color 09");
	system("Color 90");
	system("Color 09");
	system("cls");
	system("Color 02");
	Report("LOADING H.E.R.O.S. NARRATION APPLICATION", 0);
	for (int i = 0; i < 15; i++)
	{
		Sleep(100);
		cout << ".";
	}
	for (int i = 0; i < 15; i++)
	{
		Sleep(50);
		cout << ".";
	}

	system("cls");
	for (int i = 0; i < 3; i++)
	{
		Sleep(150);
		cout << "*H.E.R.O.S. NARRATION APPLICATION LOADED SUCCESSFULLY*";
		Sleep(150);
		system("cls");
	}

	system("Color 17");
	Report("-*H.E.R.O.S. NARRATION APPLICATION*-", 0);
	cout << endl;
	if (totalTreasure == 0)
	{
		Report("You set the shuttle for self destruct, you have no time for this nonsense!");
		Report("You don't have time to get beat up and find crystals.");
		Report("Time to end it all!");
	}
	else if (health <= 0)
	{
		Report("You are quickly fading out.");
		Report("You have failed your Commander, your ship, and yourself.");
		Report("You were too greedy and desparate for attention.");
		Report("You had a stockpile of ");
		cout << totalTreasure << " crystals.";
		Report("But you had to look like a big boy, didn't you?");
		Report("Your mind focuses on the image of Susan from Engineering as everything fades to black...");
	}
	else
	{
		Report("You board the shuttle with your stockpile of ");
		cout << totalTreasure << " crystals.";
		Sleep(1000);
		Report("The mission was a success!");
		Report("Your mind focuses on the image of Susan from Engineering as you ponder where your next mission will take you.");
		cout << endl;
		Report("MISSION SUCCESSFULL");
	}
	cout << endl << endl;
	system("pause");

}

//===========================================MAIN FUNCTION=====================================================//

int main()
{
	srand(time(NULL)); //Seed RNG with current time
	Story();
	while (AskYesNo())
	{
		Adventure();
		if (health <= 0)
		{
			break;
		}
	}
	Ending();

}

