#pragma once
#ifndef SONG_H
#define SONG_H

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <functional>

namespace sdds {
	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		int m_year;
		int m_length;
	};

	class SongCollection {
		std::vector<Song>m_songs;
	public:
		SongCollection(const char* filename);
		void display(std::ostream& out) const;
		void sort(std::string str);
		void cleanAlbum();
		bool inCollection(std::string name) const;
		std::list<Song> getSongsForArtist(std::string name) const;

	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}
#endif // !SONG_H



