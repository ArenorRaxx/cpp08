/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:38:02 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/18 10:23:40 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <limits>
#include <time.h>
#include "heads/Span.hpp"

int main(void)
{
	int	offset = 0;
	Span span(10000);

	srand(time(NULL));
	for (int i = 0; i < 10000 + offset; i++)
	{
		try {
			span.addNumber(rand());
		} catch (std::exception &error) {
			++offset;
		}
	}

	std::cout << span.shortestSpan() << '\n';
	std::cout << span.longestSpan() << '\n';
	std::cout << span.getSetSize() << '\n';
	
	std::cout << "\t----\n";

	Span new_span = span;

	std::cout << new_span.shortestSpan() << '\n';
	std::cout << new_span.longestSpan() << '\n';
	std::cout << new_span.getSetSize() << '\n';
	
}