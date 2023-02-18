/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:56:38 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/18 10:22:42 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../heads/Span.hpp"

//	Constructors

Span::Span(void): _set(), _size(0)
{
	// std::cout << "Span Default constructor.\n";
}

Span::Span(Span const &to_copy)
{
	// std::cout << "Span Copy constructor.\n";
	*this = to_copy;
}

Span::Span(unsigned int n): _set(), _size(n)
{
}

//	Destructors

Span::~Span(void)
{
	// std::cout << "Span Destructor.\n";
}

//	Operators

Span &Span::operator = (Span const &to_set_to)
{
	// std::cout << "Span Assignation constructor.\n";
	this->_size = to_set_to._size;
	addNumber(to_set_to._set.begin(), to_set_to._set.end());
	return (*this);
}

//	Exceptions

char const *Span::MaxSizeExceededException::what() const throw()
{
	return ("Cannot store more element: Max size exceeded.\n");
}

char const *Span::NoElementStoredException::what() const throw()
{
	return ("Cannot perform operation: Not enough element stored.\n");
}

char const *Span::NumberDuplicateException::what() const throw()
{
	return ("Cannot store this element: No duplicate allowed.\n");
}

//	Methods

void Span::addNumber(int number)
{
	std::pair<set_t::iterator, bool>	ret_of_insert;

	if (this->_set.size() == this->_size)
		throw MaxSizeExceededException();
	ret_of_insert = this->_set.insert(number);
	if (ret_of_insert.second == false)
		throw NumberDuplicateException();
}

int	Span::longestSpan(void) const
{
	if (this->_set.size() < 2)
		throw NoElementStoredException();
	return (*this->_set.begin() - *this->_set.rbegin());
}

int Span::shortestSpan(void) const
{

	if (this->_set.size() < 2)
		throw NoElementStoredException();
	std::for_each(this->_set.begin(), this->_set.end(), static_cast<void (*)(int)>(&Span::_substractFunction));
	return (Span::_substractFunction());
}

unsigned int Span::getSetSize(void) const
{
	return (this->_set.size());
}

unsigned int Span::getMaxSize(void) const
{
	return (this->_size);
}

  /*------------------*/
 /*		 PRIVATE	 */
/*------------------*/

int Span::_substractFunctionResult = 0;

//	Special methods

int	Span::_substractFunction(void)
{
	int	current_result = Span::_substractFunctionResult;

	Span::_substractFunctionResult = 0;	
	return (current_result);
}

void Span::_substractFunction(int number)
{
	int static	last_value;
	int			&current_result = Span::_substractFunctionResult;

	if (current_result == 0)
		current_result = number;
	else if (current_result > last_value - number)
		current_result = last_value - number;
	last_value = number;
}
