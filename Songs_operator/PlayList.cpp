#include <iostream>
#include "PlayList.h"
#include "Song.h"

using namespace std;

// Constructor to  create empty PlayList
PlayList::PlayList()
{
	playlist_size = 2;
	num_of_songs = 0;
	playing_now = 0;
	SongList = new Song[playlist_size];
}

// function to add Song
void PlayList::AddSong(const Song& s)
{
	if (num_of_songs < playlist_size - 1)
	{
		SongList[num_of_songs] = s;
		num_of_songs++;
	}
	else
	{
		doubleplaylist_size();
		SongList[num_of_songs] = s;
		num_of_songs++;
	}
}

// fuction for deleting a Song
bool PlayList::DeleteSong(const Song& s)
{
	for (int i = 0; i < num_of_songs; i++)
	{
		if (SongList[i] == s)
		{
			for (i; i < num_of_songs - 1; i++)
			{
				SongList[i] = SongList[i + 1];
			}
			num_of_songs--;
			if (num_of_songs < (playlist_size / 2) - 1)
				halfplaylist_size();
			return true;
		}
	}

	return false;
}

// function to view PlayList
void PlayList::ShowAll() const
{
	if (num_of_songs == 0)
		cout << "There is no song in the Playlist.\n";
	else
	{
		cout << "Songs in the Playlist are :\n";

		for (int i = 0; i < num_of_songs; i++)
		{
			cout << i + 1 << ".  ";
			cout << SongList[i];
		}
	}

}

// Playing Songs
void PlayList::Play(int num)
{
	char next;
	int i = playing_now;
	if ((num + playing_now) < num_of_songs)
	{
		while (playing_now < num + i)
		{
			next = 'b';
			cout << "Now playing :\n";
			cout << SongList[playing_now];
			if (playing_now + 1 == num_of_songs)
			{
				playing_now = 0;
				cout << "Next Song :\n";
				cout << SongList[playing_now];
			}
			else
			{
				cout << "Next Song :\n";
				cout << SongList[playing_now + 1];
				playing_now++;
			}
			//	if (playing_now != num_of_songs - 1)
			{
				while (next != 'n' && next != 'N')
				{
					cout << "Press 'N' key for the next song : \n";
					cin >> next;
				}
			}

		}
	}
	else
	{
		while (playing_now < num_of_songs)
		{
			next = 'b';
			cout << "Now playing :\n";
			cout << SongList[playing_now];
			if (playing_now + 1 == num_of_songs)
			{
				cout << "Next Song :\n";
				cout << SongList[0];
			}
			else
			{
				cout << "Next Song :\n";
				cout << SongList[playing_now + 1];
			}

			playing_now++;
			//	if (playing_now != num_of_songs - 1)
			{
				while (next != 'n' && next != 'N')
				{
					cout << "Press 'N' key for the next song : \n";
					cin >> next;
				}
			}

		}
		playing_now = 0;
		while (next != 'n' && next != 'N')
		{
			cout << "Press 'N' key for the next song : \n";
			cin >> next;
		}
		PlayList::Play(num + i - num_of_songs);
	}
}


// Function s to show status of PlayList
void PlayList::ShowStatus() const
{
	cout << "Capacity of the Playlist is " << playlist_size << ".\n";
	if (num_of_songs == 0)
		cout << "There is no song in the Playlist.\n";
	else
	{
		cout << "Songs in Playlist are " << num_of_songs << ".\n";

		cout << "Index of current Song is " << playing_now + 1 << ".\n";
	}


}

// function to decrease the size of PlayList to half
void PlayList::halfplaylist_size()
{
	Song* Plist = new Song[playlist_size / 2];
	for (int i = 0; i < num_of_songs; i++)
	{
		Plist[i] = SongList[i];

	}
	delete[] SongList;
	playlist_size = playlist_size / 2;
	SongList = Plist;

}

// function to double up the size of PlayList
void PlayList::doubleplaylist_size()
{
	Song* Plist = new Song[playlist_size * 2];
	for (int i = 0; i < num_of_songs; i++)
	{
		Plist[i] = SongList[i];

	}
	delete[] SongList;
	playlist_size = playlist_size * 2;
	SongList = Plist;
}

// destructor
PlayList::~PlayList()
{
	delete[] SongList;
}

// operator overloading function for adding new Song
PlayList operator+(const PlayList p, const Song& s)
{
	PlayList p1 = p;
	p1.AddSong(s);
	return p1;
}

// operator overloading function for deleting specific Song
PlayList operator-(const PlayList p, const Song& s)
{
	PlayList p1 = p;
	p1.DeleteSong(s);
	return p1;
}