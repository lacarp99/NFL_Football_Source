#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <random>
#include <time.h>
#include <fstream>

using namespace std;

int chosenTeam = 0;
int skill = NULL;

char createOrSignin;

string appdata;
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
const string names[] = {
	"Smith"
	,"Johnson"
	,"Williams"
	,"Jones"
	,"Brown"
	,"Davis"
	,"Miller"
	,"Wilson"
	,"Moore"
	,"Taylor"
	,"Anderson"
	,"Thomas"
	,"Jackson"
	,"White"
	,"Harris"
	,"Martin"
	,"Thompson"
	,"Garcia"
	,"Martinez"
	,"Robinson"
	,"Clark"
	,"Rodriguez"
	,"Lewis"
	,"Lee"
	,"Walker"
	,"Hall"
	,"Allen"
	,"Young"
	,"Hernandez"
	,"King"
	,"Wright"
	,"Lopez"
	,"Hill"
	,"Scott"
	,"Green"
	,"Adams"
	,"Baker"
	,"Gonzalez"
	,"Nelson"
	,"Carter"
	,"Mitchell"
	,"Perez"
	,"Roberts"
	,"Turner"
	,"Phillips"
	,"Campbell"
	,"Parker"
	,"Evans"
	,"Edwards"
	,"Collins"
	,"Stewart"
	,"Sanchez"
	,"Morris"
	,"Rogers"
	,"Reed"
	,"Cook"
	,"Morgan"
	,"Bell"
	,"Murphy"
	,"Bailey"
	,"Rivera"
	,"Cooper"
	,"Richardson"
	,"Cox"
	,"Howard"
	,"Ward"
	,"Torres"
	,"Peterson"
	,"Gray"
	,"Ramirez"
	,"James"
	,"Watson"
	,"Brooks"
	,"Kelly"
	,"Sanders"
	,"Price"
	,"Bennett"
	,"Wood"
	,"Barnes"
	,"Ross"
	,"Henderson"
	,"Coleman"
	,"Jenkins"
	,"Perry"
	,"Powell"
	,"Long"
	,"Patterson"
	,"Hughes"
	,"Flores"
	,"Washington"
	,"Butler"
	,"Simmons"
	,"Foster"
	,"Gonzales"
	,"Bryant"
	,"Alexander"
	,"Russell"
	,"Griffin"
	,"Diaz"
	,"Hayes"
};

int truRand(int max) {
	srand(time(NULL));
	return rand()*rand() % max;
}

int main(int nNumberofArgs, char* pszArgs[])
{
	//Setup
	srand(time(NULL));
	fstream file("C:\\Users\\Public\\NFL_Football\\saveGame.txt");
	cout << "Sign in to your account or create a new one. [S/N]: " << endl;
	cin >> createOrSignin;
	if (createOrSignin == 'S') {
		cin >> username;
		cin >> password;
		//check to see if they match any in the document.
	} else if (createOrSignin == 'N') {
		cin >> username;
		cin >> password;
		//write these to a document.
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