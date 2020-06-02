#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <random>
#include <time.h>
#include <fstream>
#include "readfromfile.h"

using namespace std;

int chosenTeam = 0;
int skill = NULL;
int slot;
int access = 1;
int tries = 3;

char createOrSignin;

string username;
string password;

struct newcoach {
	string firstname;
	string lastname;
} coach;

struct newTeam {
	int quarterback;
	int runningback;
	int wideReceiver;
	int tightEnd;
	int lineBacker;
	int offensiveLineman;
	int defensiveLineman;
	int cornerBack;
	int safety;
	int quarterbackskill;
	int runningbackskill;
	int wideReceiverskill;
	int tightEndskill;
	int lineBackerskill;
	int offensiveLinemanskill;
	int defensiveLinemanskill;
	int cornerBackskill;
	int safetyskill;
} team;

//Teams Names
const char* teams[] = {
	"Arizona Cardinals",
	"Atlanta Falcons",
	"Baltimore Ravens",
	"Buffalo Bills",
	"Carolina Panthers",
	"Chicago Bears",
	"Cincinnati Bengals",
	"Cleveland Browns",
	"Dallas Cowboys",
	"Denver Broncos",
	"Detroit Lions",
	"Green Bay Packers",
	"Houston Texans",
	"Indianapolis Colts",
	"Jacksonville Jaguars",
	"Kansas City Chiefs",
	"Los Angeles Chargers",
	"Los Angeles Rams",
	"Miami Dolphins",
	"Minnesota Vikings",
	"New England Patriots",
	"New Orleans Saints",
	"New York Giants",
	"New York Jets",
	"Oakland Raiders",
	"Philadelphia Eagles",
	"Pittsburgh Steelers",
	"San Francisco 49ers",
	"Seattle Seahawks",
	"Tampa Bay Buccaneers",
	"Tennessee Titans",
	"Washington Redskins",
};

//Possible Player Names
std::vector< string > names;

int truRand(int max) {
	srand(time(NULL));
	return rand()*rand() % max;
}

int main(int nNumberofArgs, char* pszArgs[])
{
	//Setup
	srand(time(NULL));
	while (access != 2) {
		if (access == 1 && tries >= 3) {
			cout << "Sign in to your account or create a new one. [S/N]: " << endl;
			cin >> createOrSignin;
			cout << "What slot would you like to use? 1-3: ";
			cin >> slot;
			access = 1;
			tries = 0;
		}
		if (((createOrSignin == 'S' || createOrSignin == 's') && access == 1) && tries <= 3) {
			cout << "Password: ";
			cin >> password;
			if (getStrings((string)"passwords.txt")[slot - 1] == password) {
				cout << "Access granted." << endl;
				access = 2;
			}
			else {
				cout << "Access denied." << endl;
				access = 1;
				tries++;
			}
		}
		else if (createOrSignin == 'N' || createOrSignin == 'n') {
			cout << "WARNING! Any data that was on this slot will be removed. Be sure this is the correct slot before creating a new password and team." << endl;
			cout << "What would you like the password to be? ";
			cin >> password;
			switch (slot)
			{
			case 1:
				writeStrings((string)"passwords.txt", vector< string > { password, getStrings((string)"passwords.txt")[1], getStrings((string)"passwords.txt")[2] }, 3);
				break;
			case 2:
				writeStrings((string)"passwords.txt", vector< string > { getStrings((string)"passwords.txt")[0], password, getStrings((string)"passwords.txt")[2] }, 3);
				break;
			case 3:
				writeStrings((string)"passwords.txt", vector< string > { getStrings((string)"passwords.txt")[1], getStrings((string)"passwords.txt")[2], password }, 3);
				break;
			}
		}
	}

	//Welcome Player
	cout << "Welcome to NFL Football! Select a team from the following list:" << endl;
	for (int i = 0; teams[i] != NULL; i++) {
		cout << i + 1 << ". " << teams[i] << endl;
	}
	//Get player's team of choice
	cout << endl << "Type the number of the team you would like to play as: ";
	cin >> chosenTeam;
	cout << "You chose: " << teams[chosenTeam - 1] << endl;
	//Get name of player (coach)
	cout << "What is the name of your coach?" << endl;
	cout << "Coach: ";
	cin >> coach.firstname;
	cin >> coach.lastname;
	cout << "Welcome Coach " << coach.lastname << " we're glad to have you here with the " << teams[chosenTeam - 1] << endl;
	//Create team and save random names
	for (int i = 0; i < 100; i++) {
		names.push_back(getStrings((string)"personNames.txt")[i]);
	}

	team.quarterbackskill = truRand(3);
	team.runningbackskill = truRand(3);
	team.wideReceiverskill = truRand(3);
	team.tightEndskill = truRand(3);
	team.offensiveLinemanskill = truRand(3);
	team.lineBackerskill = truRand(3);
	team.defensiveLinemanskill = truRand(3);
	team.cornerBackskill = truRand(3);
	team.safetyskill = truRand(3);
	cout << team.safetyskill << endl;
	cout << names[rand() % 99] << endl;
	return 0;
}