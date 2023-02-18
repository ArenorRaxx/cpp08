/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:18:40 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/18 10:23:22 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

typedef std::set< int, std::greater<int> >	set_t;

class Span
{
	private:
		int			 static	_substractFunctionResult;
		set_t				_set;
		unsigned int		_size;
		
	//	Special Methods
	//		substractFunction()
	
		int	 static	_substractFunction(void);
		void static	_substractFunction(int);
	public:
	//	Constructors
	
		Span(void);
		Span(Span const&);
		Span(unsigned int);
		
	//	Destructor

		~Span(void);

	//	Operators

		Span &operator = (Span const&);
	
	//	Exceptions

		class MaxSizeExceededException;
		class NoElementStoredException;
		class NumberDuplicateException;

	//	Get / Set

		unsigned int	getSetSize(void)	const;
		unsigned int	getMaxSize(void)	const;

	//	Methods

		int				longestSpan(void)	const;
		int				shortestSpan(void)	const;
		void			addNumber(int);
		
		template <class _InputIterator>
		void			addNumber(_InputIterator first, _InputIterator last)
		{
			try {
				for (; first != last; first++)
					this->addNumber(*first);
			} catch (std::exception &error) {
				std::cout << error.what();
			}
		}
};


class Span::MaxSizeExceededException: public std::exception
{
	char const *what() const throw();
};

class Span::NoElementStoredException: public std::exception
{
	char const *what() const throw();
};

class Span::NumberDuplicateException: public std::exception
{
	char const *what() const throw();
};

#endif