#include "Restaurant.h"
namespace sdds {
	sdds::Restaurant::Restaurant()
	{
		m_res = {};
		m_cnt = 0;
	}

	Restaurant::~Restaurant()
	{
		delete[] m_res;
		m_res = nullptr;
	}

	sdds::Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		m_res = new Reservation[cnt];
		for (size_t i = 0; i < cnt; i++)
		{
			m_res[i] = *reservations[i];
		}
		m_cnt = cnt;
	}

	Restaurant::Restaurant(const Restaurant& res)
	{
		if (this != &res) {
			m_res = nullptr;
			delete[] m_res;
			*this = res;
		}
	}

	Restaurant& Restaurant::operator=(const Restaurant& res)
	{
		if (&res != this)
		{
			if (m_res != nullptr) {
				m_res = nullptr;
				delete[] m_res;
			}
			m_res = new Reservation[res.m_cnt];
			for (size_t i = 0; i < res.m_cnt; i++)
			{
				m_res[i] = res.m_res[i];
			}
			m_cnt = res.m_cnt;
		}
		// TODO: insert return statement here
		return *this;
	}

	size_t sdds::Restaurant::size() const
	{
		return m_cnt;
	}

	Restaurant& Restaurant::operator=(Restaurant&& R)noexcept
	{
		if (this != &R)
		{
			m_cnt = R.m_cnt;
			m_res = nullptr;
			delete[] m_res;
			m_res = R.m_res;
			R.m_res = nullptr;
			R.m_cnt = 0;
		}
		// TODO: insert return statement here
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& R)noexcept
	{
		*this = std::move(R);
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& res)
	{
		static int call_cnt = 0;
		if (res.m_cnt == 0)
		{
			call_cnt++;
			os << "--------------------------\n";
			os << "Fancy Restaurant (" << call_cnt << ")\n";
			os << "--------------------------\n";
			os << "This restaurant is empty!\n";
			os << "--------------------------\n";
		}
		else
		{
			call_cnt++;
			os << "--------------------------\n";
			os << "Fancy Restaurant (" << call_cnt << ")\n";
			os << "--------------------------\n";
			for (size_t i = 0; i < res.m_cnt; i++)
			{
				os << res.m_res[i];
			}
			os << "--------------------------\n";
		}
		// TODO: insert return statement here
		return os;
	}

}
