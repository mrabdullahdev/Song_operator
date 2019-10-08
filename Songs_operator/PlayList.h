// PlayList class
#pragma once
#include "Song.h"	// including header file of class Song to use the object of that class

using namespace std;

// Playlist class to store the songs and playing them 

class PlayList
{
private:	// private data members
	int playlist_size;	// variable
	int num_of_songs;
	int playing_now;
	// dynamically allocated array of Song class objects 
	Song* SongList;
public:

	PlayList();
	void AddSong(const Song& s);
	bool DeleteSong(const Song& s);
	void ShowAll()const;
	void Play(int num = 1);
	void ShowStatus()const;
	void halfplaylist_size();
	void doubleplaylist_size();
	~PlayList();
	friend PlayList operator+(const PlayList p, const Song& s);
	friend PlayList operator-(const PlayList p, const Song& s);
};

