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

string appdatapath;
string password;

struct newcoach {
	string firstname;
	string lastname;
} coach;

struct newTeam {
	string quarterback;
	string runningback;
	string wideReceiver;
	string tightEnd;
	string lineBacker;
	string offensiveLineman;
	string defensiveLineman;
	string cornerBack;
	string safety;

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

string encrypt(string input) {
	string output;
	const char* password = input.c_str();
	for (int i = 0; password[i] != NULL; i++) {
		output.push_back((char)((int)password[i] + 3));
	}

	return output;
}

string decrypt(string input) {
	string output;
	const char* password = input.c_str();
	for (int i = 0; password[i] != NULL; i++) {
		output.push_back((char)((int)password[i] - 3));
	}

	return output;
}

int main(int nNumberofArgs, char* pszArgs[])
{
	//Setup
	appdatapath = appData()+"NFL_Football\\";
	cout << appdatapath << endl;
	srand(time(NULL));
	while (access != 2 && access != 4) {
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
			if (decrypt(getStrings(appdatapath+"passwords.txt")[slot - 1]) == password) {
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
			access = 4;
			cout << "WARNING! Any data that was on this slot will be removed. Be sure this is the correct slot before creating a new password and team." << endl;
			cout << "What would you like the password to be? ";
			cin >> password;
			switch (slot)
			{
			case 1:
				writeStrings(appdatapath+"passwords.txt", vector< string > { encrypt(password), getStrings(appdatapath+"passwords.txt")[1], getStrings(appdatapath+"passwords.txt")[2] }, 3);
				break;
			case 2:
				writeStrings(appdatapath+"passwords.txt", vector< string > { getStrings(appdatapath+"passwords.txt")[0], encrypt(password), getStrings(appdatapath+"passwords.txt")[2] }, 3);
				break;
			case 3:
				writeStrings(appdatapath+"passwords.txt", vector< string > { getStrings(appdatapath+"passwords.txt")[1], getStrings(appdatapath+"passwords.txt")[2], encrypt(password) }, 3);
				break;
			}
		}
	}

	if (access == 4) {
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
			names.push_back(getStrings(appdatapath + "personNames.txt")[i]);
		}

		team.quarterbackskill = rand() % 3;
		srand(time(NULL));
		team.runningbackskill = rand() % 3;
		srand(time(NULL));
		team.wideReceiverskill = rand() % 3;
		srand(time(NULL));
		team.tightEndskill = rand() % 3;
		srand(time(NULL));
		team.offensiveLinemanskill = rand() % 3;
		srand(time(NULL));
		team.lineBackerskill = rand() % 3;
		srand(time(NULL));
		team.defensiveLinemanskill = rand() % 3;
		srand(time(NULL));
		team.cornerBackskill = rand() % 3;
		srand(time(NULL));
		team.safetyskill = rand() % 3;
		srand(time(NULL));
		team.quarterback = names[ rand() % 99];
		srand(time(NULL));
		team.runningback = names[ rand() % 99];
		srand(time(NULL));
		team.wideReceiver = names[ rand() % 99];
		srand(time(NULL));
		team.tightEnd = names[ rand() % 99];
		srand(time(NULL));
		team.offensiveLineman = names[ rand() % 99];
		srand(time(NULL));
		team.lineBacker = names[ rand() % 99];
		srand(time(NULL));
		team.defensiveLineman = names[ rand() % 99];
		srand(time(NULL));
		team.cornerBack = names[ rand() % 99];
		srand(time(NULL));
		team.safety = names[ rand() % 99];
		cout << "QB " << team.quarterback << " : " << team.quarterbackskill << endl;
		cout << "RB " << team.runningback << " : " << team.runningbackskill << endl;
		cout << "WR " << team.wideReceiver << " : " << team.wideReceiverskill << endl;
		cout << "TE " << team.tightEnd << " : " << team.tightEndskill << endl;
		cout << "OL " << team.offensiveLineman << " : " << team.offensiveLinemanskill << endl;
		cout << "LB " << team.lineBacker << " : " << team.lineBackerskill << endl;
		cout << "DL " << team.defensiveLineman << " : " << team.defensiveLinemanskill << endl;
		cout << "CB " << team.cornerBack << " : " << team.cornerBackskill << endl;
		cout << "S " << team.safety << " : " << team.safetyskill << endl;
	}
	//start game normally
	return 0;
}