#define _CRT_SECURE_NO_WARNINGS
#include "Autoshop.h"
namespace sdds {
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
    {
        m_vehicles.push_back(theVehicle);
        // TODO: insert return statement here
        return *this;
    }

    void Autoshop::display(std::ostream& out) const
    {
        out << "--------------------------------" << std::endl;
        out << "| Cars in the autoshop!        |" << std::endl;
        out << "--------------------------------" << std::endl;

        std::vector<Vehicle*>::iterator i;
        for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
            (*i)->display(out);
            out << std::endl;
        }
       /* for (size_t i = 0; i < m_vehicles.size(); i++)
        {
            m_vehicles[i]->display(out);
            out << std::endl;
        }*/
        out << "--------------------------------" << std::endl;

    }

    Autoshop::~Autoshop()
    {
        for (auto& v : m_vehicles) {
            delete v;
            v = nullptr;
        }

    }

}
