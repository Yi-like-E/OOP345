#define _CRT_SECURE_NO_WARNINGS
#include "SongCollection.h"

namespace sdds {
	int total = 0;  //record total length of listening
	SongCollection::SongCollection(const char* filename)
	{
		std::ifstream file(filename);
		if (!file)
		{
			throw "file cannot open";
		}
		else
		{
			while (!file.eof()) {
				std::string str, artist, title, album, price, year, length;
				Song songs;
				getline(file, str, '\n');
				//titile
				title = str.substr(0, 25);
				title.erase(0, title.find_first_not_of(" "));
				title.erase(title.find_last_not_of(" ") + 1);
				str.erase(0, 25);

				//artist
				artist = str.substr(0, 25);
				artist.erase(0, artist.find_first_not_of(" "));
				artist.erase(artist.find_last_not_of(" ") + 1);
				str.erase(0, 25);

				//album
				album = str.substr(0, 25);
				album.erase(0, album.find_first_not_of(" "));
				album.erase(album.find_last_not_of(" ") + 1);
				str.erase(0, 25);

				//year
				year = str.substr(0, 5);
				year.erase(0, year.find_first_not_of(" "));
				year.erase(year.find_last_not_of(" ") + 1);
				str.erase(0, 5);

				//length
				length = str.substr(0, 5);
				length.erase(0, length.find_first_not_of(" "));
				length.erase(length.find_last_not_of(" ") + 1);
				str.erase(0, 5);

				//price
				price = str;
				price.erase(0, price.find_first_not_of(" "));
				price.erase(price.find_last_not_of(" ") + 1);

				songs.m_artist = artist;
				songs.m_title = title;
				songs.m_album = album;
				songs.m_price = std::stod(price);
				if (year == "")
				{
					songs.m_year = 0;
				}
				else {
					songs.m_year = std::stoi(year);
				}
				songs.m_length = std::stoi(length);

				total += songs.m_length;  //calculate total length of listening

				m_songs.push_back(songs);
			}
		}file.close();

	}
	void SongCollection::display(std::ostream& out) const
	{
		int hr, min, sec;
		hr = total / 3600;
		min = (total % 3600) / 60;
		sec = (total % 3600) % 60;

		std::for_each(m_songs.begin(), m_songs.end(), [&](const Song songs) {out << songs << std::endl; });
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| " << std::right << std::setw(77) << "Total Listening Time: " << hr << ":" << min << ":" << sec << " |" << std::endl;
	}

	void SongCollection::sort(std::string str)
	{
		if (str == "title")
		{
			std::sort(m_songs.begin(), m_songs.end(), [](Song& a, Song& b) {return a.m_title < b.m_title; });                 //sort
		}
		else if (str == "length")
		{
			std::sort(m_songs.begin(), m_songs.end(), [](Song& a, Song& b) {return a.m_length < b.m_length; });

		}
		else if (str == "album")
		{
			std::sort(m_songs.begin(), m_songs.end(), [](Song& a, Song& b) {return a.m_album < b.m_album; });
		}
		else
		{
			throw "your input cannot be identified";
		}
	}
	void SongCollection::cleanAlbum()
	{
		std::for_each(m_songs.begin(), m_songs.end(), [](Song& songs) {              //for each
			if (songs.m_album == "[None]")
			{
				songs.m_album = " ";
			}
			});
	}
	bool SongCollection::inCollection(std::string name) const
	{
		return std::any_of(m_songs.cbegin(), m_songs.cend(), [&name](const Song& songs) {return name == songs.m_artist; });         //any of
	}
	std::list<Song> SongCollection::getSongsForArtist(std::string name) const
	{
		std::list<Song> collection{};
		std::copy_if(m_songs.cbegin(), m_songs.cend(), std::back_inserter(collection), [&name](const Song& s) {return name == s.m_artist; });
		return collection;
	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		out << "| " << std::setw(20) << std::left << theSong.m_title << " | " << std::setw(15) << theSong.m_artist << " | " << std::setw(20) << theSong.m_album << " | " << std::setw(6);
		if (!theSong.m_year)
		{
			out << "     ";
		}
		else
		{
			out << std::right << theSong.m_year << std::left;
		}
		out << " | " << std::right << (theSong.m_length / 60) << ":" << std::setw(2);
		out << std::setfill('0') << (theSong.m_length % 60);
		out << std::setfill(' ') << " | " << theSong.m_price << " |";
		// TODO: insert return statement here
		return out;
	}
}