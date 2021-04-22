#include "CustomerOrder.h"
namespace sdds {
	size_t CustomerOrder::m_widthField = 0;
	CustomerOrder::CustomerOrder(const std::string str)
	{
		Utilities u;
		bool more = false;
		size_t pos = 0;

		//customer name
		m_name = u.extractToken(str, pos, more);
		//order number
		m_product = u.extractToken(str, pos, more);
		//list of items
		std::string items = str.substr(pos, str.length() - pos);
		m_cntItem = (std::count(items.begin(), items.end(), u.getDelimiter())) + 1;
		m_lstItem = new Item * [m_cntItem];
		for (size_t i = 0; i < m_cntItem && more; i++)
		{
			m_lstItem[i] = new Item(u.extractToken(str, pos, more));
		}
		m_widthField = std::max(m_widthField, u.getFieldWidth());

	}

	CustomerOrder::CustomerOrder(CustomerOrder&& obj) noexcept
	{
		*this = std::move(obj);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj) noexcept
	{
		if (this != &obj)
		{
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}

			m_name = obj.m_name;
			obj.m_name = "";
			m_product = obj.m_product;
			obj.m_product = "";
			m_cntItem = obj.m_cntItem;
			obj.m_cntItem = 0;
			m_lstItem = obj.m_lstItem;
			obj.m_lstItem = nullptr;

		}
		// TODO: insert return statement here
		return *this;
	}
	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
			m_lstItem[i] = nullptr;
		}
	}
	bool CustomerOrder::isFilled() const
	{
		bool filled = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (!m_lstItem[i]->m_isFilled)
			{
				filled = false;
			}
		}
		return filled;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool filled = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				filled = m_lstItem[i]->m_isFilled;
			}
		}
		return filled;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (station.getItemName() == m_lstItem[i]->m_itemName)
			{
				if (station.getQuantity() > 0)
				{
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
				else
				{
					os << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			os << std::left << std::setfill(' ') << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled)
			{
				os << "FILLED" << std::endl;
			}
			else
			{
				os << "TO BE FILLED" << std::endl;
			}

		}

	}
}