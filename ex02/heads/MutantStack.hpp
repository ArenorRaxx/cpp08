/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:51:28 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/20 11:10:25 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <string>

template <class T>
class MutantStack: public std::stack<T, std::list<T> >
{
	typedef typename std::stack<T, std::list<T> > _self_type_t;

	public:
	//	Constructors
	
		MutantStack(void): _self_type_t()
		{
		}

		MutantStack(MutantStack const &to_copy): _self_type_t(to_copy)
		{
			*this = to_copy;
		}
	
	//	Destructors

		~MutantStack(void)
		{
		}
		
	//	Operators
	
		MutantStack &operator = (MutantStack const &to_set_to)
		{
			this->c = std::list<T>(to_set_to.c);
			return (*this); 
		}

	//	Iterators

		typedef typename std::list<T>::reverse_iterator iterator;

		iterator begin(void)
		{
			return this->c.rbegin();
		}

		iterator end(void)
		{
			return this->c.rend();
		}
};

#endif