#pragma once
#include <vector>


class state //quantum state in spin representation (they may me base in some Hilbert space)
{
private:
	double scalar; //scalar factor of state
	std::vector <bool> state_vec; //list of spin in order
	bool ket; //when true it is ket, when not it is bra
	unsigned int length; //how many spin

public:
	state(std::vector <bool> state_vec = {}, double scalar = 1, bool ket = true); //constructor for some list
	state(unsigned int length, bool up); //constructor for only up or down state
	~state();
	void show(); //shows representation of state
	void conjugate(); //makes hermitian conjugate on state
	void add_spin(bool spin); //adds spin on the end of previous list
	void change_spin(unsigned int place); //changes spin in wanted place
	void change_scalar(double number); //changes scalar factor of state
	std::vector <bool> get_state_vec(); 
	double get_scalar(); 
	bool get_ket();
	unsigned int get_size();
	bool get_spin(unsigned int place); //gives information about spin in wanted place
	
};
state operator *(double num, state v1); //scalar multiply state
state operator *(state v1, state v2); //tensor product of states
state operator +(state v1, state v2); //sum of state
double operator ^(state v1, state v2); //scalar product od states
bool operator==(state v1, state v2);


class state_lin //state as superposition (linear combination) of base states
{
private:
	std::vector <state> base; //list of base states
	std::vector <double> coeff; //coefficient 
	unsigned int hilbert_space; //large of Hilbert space
	bool ket; //when true it is ket, when not it is bra

public:


};