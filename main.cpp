#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int chosenTeam = 0;
int skill = NULL;

struct newcoach {
	string firstname;
	string lastname;
} coach;

int pointGuard;
int shootingGuard;
int smallForward;
int powerForward;
int center;
int pointGuardskill;
int shootingGuardskill;
int smallForwardskill;
int powerForwardskill;
int centerSkill;

//Teams Names
const char* teams[14] = {
	"Michigan",
	"Michigan State",
	"Ohio State",
	"Maryland",
	"Wisconsin",
	"Illinois",
	"Penn State",
	"Iowa",
	"Rutgers",
	"Indiana",
	"Purdue",
	"Minnesota",
	"Northwestern",
	"Nebraska"
};

//Possible Player Names
const string names[100] = {
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

int main(int nNumberofArgs, char* pszArgs[])
{
	//Setup
	srand(time(NULL));
	//Welcome Player
	cout << "Welcome to Big 10 College Basketball! Select a team from the following list:" << endl;
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
	cout << "Welcome Coach " << coach.lastname << " we're glad to have you here at " << teams[chosenTeam - 1] << endl;
	//Create team and save random names
	pointGuardskill = rand() % 3;
	shootingGuardskill = rand() % 3;
	smallForwardskill = rand() % 3;
	powerForwardskill = rand() % 3;
	centerSkill = rand() % 3;
	cout << names[rand() % 99] << endl;
	return 0;
}