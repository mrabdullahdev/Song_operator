// Abdullah_proj5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "PlayList.h"
#include "Song.h"

using namespace std;

int main()
{
	// creating and initializing Song objects
	Song  S2("Aye Dil", "Kumar Sanu"), S3("Honda 125", "Young Desi"), S4("Car Nachdi", "Gippy Grewal");
	PlayList p;		// PlayList object created
	char t[64], a[64];
	// taking input from user for S1
	cout << "Enter title of the song :\n";
	cin >> t;
	cout << "Enter name of the artist :\n";
	cin >> a;
	Song S1(t, a);
	cout << S1;

	// adding Songs to PlayList
	p.AddSong(S1);
	p.AddSong(S2);
	p.AddSong(S3);
	p.AddSong(S4);
	// Playing PlayList
	p.Play(4);
	// Showing status
	p.ShowStatus();


	return 0;
}

