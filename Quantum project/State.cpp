#include "State.h"
#include <iostream>

state::state(std::vector<bool> state_vec, double scalar, bool ket)
{
	this->state_vec = state_vec;
	this->scalar = scalar;
	this->ket = ket;
	this->state_vec.shrink_to_fit();
	this->length = this->state_vec.size();
}

state::state(unsigned int length, bool up)
{
	std::vector <bool> temp_vec;
	for (unsigned int i = 0; i < length; i++)
	{
		if (up) temp_vec.push_back(true);
		else temp_vec.push_back(false);		
	}
	this->length = length;
	this->state_vec = temp_vec;
	this->ket = true;
	if (length != 0) this->scalar = 1;
	else this->scalar = 0;
}

state::~state()
{
	this->state_vec.clear();
	this->scalar = 0;
	this->length = 0;
}

void state::show()
{
	std::cout << this->scalar<<" ";
	if (this->ket == true)
	{
		std::cout << "|";
		for (unsigned int i = 0; i < this->length; i++)
		{
			std::cout << " " << this->state_vec.at(i) << " ";
		}
		std::cout << ">";

	}
	else
	{
		std::cout << "<";
		for (unsigned int i = 0; i < this->length; i++)
		{
			std::cout << " " << this->state_vec.at(i) << " ";
		}
		std::cout << "|";

	}
}

void state::conjugate()
{
	this->ket = !(this->ket);
}

void state::add_spin(bool spin)
{
	this->state_vec.push_back(spin);
	this->state_vec.shrink_to_fit();
	this->length++;
}

void state::change_spin(unsigned int place)
{
	if (place <= this->length) this->state_vec.at(place-1) = !(this->state_vec.at(place-1));
	else std::cerr << "Nie mozesz zmienic tego spinu!";	
}

void state::change_scalar(double number)
{
	this->scalar = (this->scalar) * number;
}

std::vector<bool> state::get_state_vec()
{
	return this->state_vec;
}

double state::get_scalar()
{
	return this->scalar;
}

bool state::get_ket()
{
	return this->ket;
}

unsigned int state::get_size()
{
	return this->length;
}

bool state::get_spin(unsigned int place)
{
	return this->state_vec.at(place);
}

state operator*(double num, state v1)
{
	return state(v1.get_state_vec(),num*(v1.get_scalar()),v1.get_ket());
}

state operator*(state v1, state v2)
{
	if (v1.get_ket() != v2.get_ket())
	{
		return state(0, false);
	}
	else
	{
		std::vector <bool> temp;
		for (unsigned int i = 0; i < v1.get_size(); i++)
		{
			temp.push_back(v1.get_spin(i));
		}
		for (unsigned int i = 0; i < v2.get_size(); i++)
		{
			temp.push_back(v2.get_spin(i));
		}
		return state(temp, v1.get_scalar() * v2.get_scalar(), v1.get_ket());
	}
}

state operator+(state v1, state v2)
{
	if ((v1.get_ket() == v2.get_ket()) && (v1.get_state_vec() == v2.get_state_vec()) && (v1.get_size() == v2.get_size()))
	{
		return state(v1.get_state_vec(), v1.get_scalar() + v2.get_scalar(), v1.get_ket());
	}
	else return state(0, false);
}

double operator^(state v1, state v2)
{
	if ((v1.get_ket() == false) && (v2.get_ket() == true) && (v1.get_state_vec() == v2.get_state_vec()) && (v1.get_size() == v2.get_size()))
	{
		return v1.get_scalar() * v2.get_scalar();
	}
	else return 0;
}

bool operator==(state v1, state v2)
{
	if ((v1.get_ket() == v2.get_ket()) && (v1.get_state_vec() == v2.get_state_vec()) && (v1.get_size() == v2.get_size()) &&
		(v1.get_scalar() == v2.get_scalar()))
	{
		return true;
	}
	else return false;
}
