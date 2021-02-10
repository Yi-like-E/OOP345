#pragma once
//name:Yuelin Wen
//email:ywen26@myseneca.ca
//ID:114379209
//date:Feb.07.2021
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SETSUM_H
#define _SETSUM_H
#include "Set.h"
#include <cstring>
#include <iostream>

namespace sdds {
	template <unsigned N, typename T>
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const std::string& filter) const {
			T object(filter); //define an T object with one argrument constructor
			for (size_t i = 0; i < this->size(); i++) //iteration
			{
				if (object.isCompatibleWith(this->get(i))) //check each element in the collection to determine if it is compatible
				{
					object += this->get(i); //add element to accmulator object
				}
			}
			return object;
		};
	};
}
#endif