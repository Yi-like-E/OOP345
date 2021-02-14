#include "ConfirmationSender.h"
namespace sdds {
	ConfirmationSender::ConfirmationSender()
	{
		m_cres = {};
		m_count = 0;
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs)
	{
		if (this != &cs)
		{
			*this = cs;
		}
	}
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_cres;
		m_cres = nullptr;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool found = false;
		for (size_t i = 0; i < m_count; i++)
		{
			if (&res == m_cres[i])
			{
				found = true;
			}

		}
		if (!found)
		{
			const Reservation** temp = nullptr;
			temp = new const Reservation * [m_count + 1];
			for (size_t i = 0; i < m_count; i++)
			{
				temp[i] = m_cres[i];
			}
			temp[m_count] = &res;
			++m_count;
			delete[] m_cres;
			m_cres = temp;
		}
		// TODO: insert return statement here
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		for (size_t i = 0; i < m_count; i++)
		{
			if (&res == m_cres[i]) {
				m_cres[i] = nullptr;
				--m_count;
			}
		}
		// TODO: insert return statement here
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs)
	{
		if (this != &cs)
		{
			m_count = cs.m_count;
			m_cres = nullptr;
			delete[] m_cres;

			m_cres = new const Reservation * [cs.m_count + 1];
			for (size_t i = 0; i < m_count; i++)
			{
				m_cres[i] = cs.m_cres[i];
			}
		}
		// TODO: insert return statement here
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& C)noexcept
	{
		if (this != &C)
		{

			m_cres = nullptr;
			delete[] m_cres;
			m_count = C.m_count;
			m_cres = C.m_cres;
			C.m_cres = nullptr;
			C.m_count = 0;
		}
		// TODO: insert return statement here
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& C)noexcept
	{
		*this = std::move(C);
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs)
	{
		if (cs.m_count == 0)
		{
			os << "--------------------------\n";
			os << "Confirmations to Send\n";
			os << "--------------------------\n";
			os << "There are no confirmations to send!\n";
			os << "--------------------------\n";
		}
		else
		{
			os << "--------------------------\n";
			os << "Confirmations to Send\n";
			os << "--------------------------\n";
			for (size_t i = 0; i < cs.m_count; i++)
			{
				if (cs.m_cres[i] != nullptr)
				{
					os << *cs.m_cres[i];
				}

			}
			os << "--------------------------\n";
		}
		// TODO: insert return statement here
		return os;
	}
}
