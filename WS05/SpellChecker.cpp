#define _CRT_SECURE_NO_WARNINGS
#include "SpellChecker.h"
namespace sdds {
	sdds::SpellChecker::SpellChecker() {
		*m_badWords = {};
		*m_goodWords = {};
	}

	sdds::SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		//static int cnt = 0;
		if (!file)
		{
			throw "Bad file name!";
		}
		else
		{
			for (size_t i = 0; i < sizeof(m_badWords) / sizeof(m_badWords[0]); ++i)
			{
				file >> m_badWords[i];
				file >> m_goodWords[i];
				m_cnt[i] = 0;
			}
			/*std::string readin;

			do
			{
				std::string tmp = {};
				std::getline(file, tmp);
				if (file)
				{
					std::string::size_type pos = tmp.find(' ');

					m_badWords[cnt] = tmp.substr(0, pos);
					tmp.erase(0, pos + 1);
					auto pos1 = tmp.find_first_not_of(' ');
					tmp.erase(0, pos1);
					m_goodWords[cnt] = tmp;
					++cnt;*/
					////find bad words
					//pos = tmp.find(' ');
					//m_badWords[cnt] = tmp.substr(0, pos);
					//tmp.erase(0, pos + 1);

					//m_badWords[cnt].erase(0, m_goodWords[cnt].find_first_not_of(" "));
					//m_badWords[cnt].erase(m_goodWords[cnt].find_last_not_of(" ") + 1);

					////find good words
					////pos = tmp.find(' ');
					//m_goodWords[cnt] = tmp.substr(0, pos);
					//tmp.erase(0, pos + 1);

					//m_goodWords[cnt].erase(0, m_goodWords[cnt].find_first_not_of(" "));
					//m_goodWords[cnt].erase(m_goodWords[cnt].find_last_not_of(" ") + 1);

				/*}
			} while (file);*/
			file.close();
		}
	}

	void SpellChecker::operator()(std::string& text)
	{
		/*int cnt = 0;
		int n = 0;

		for (size_t i = 0; i < 6; i++)
		{
			n = text.find(m_badWords[i]);
			if (n != std::string::npos)
			{
				for (size_t j = 0; i < 6; j++)
				{
					m_cnt[j] += cnt;
				}
				text.replace(n, m_badWords[i].length(), m_goodWords[i]);
				cnt++;
			}

		}*/



		size_t n = 0;

		for (auto i = 0; i < 6; i++) {
			size_t cnt = 0;
			while ((n = text.find(m_badWords[i])) != std::string::npos) {
				text.replace(n, m_badWords[i].length(), m_goodWords[i]);
				cnt++;
				m_cnt[i] += cnt;
				if (i == 4)
				{
					if (m_cnt[i] == 5)
					{
						m_cnt[i] = 4;
					}
				}
				
			}

		}

	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics\n";
		for (auto i = 0; i < 6; i++)
		{
			out << std::setw(15) << m_badWords[i] << ": " << m_cnt[i] << " replacements" << std::endl;

		}


	}

}
