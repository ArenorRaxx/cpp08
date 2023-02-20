/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:38:02 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/20 11:40:17 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "heads/MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	
	std::cout << '\n';

	mstack.push(5);
	std::cout << "push 5 in mstack\n";
	
	mstack.push(17);
	std::cout << "push 17 in mstack\n";
	
	std::cout << "mstack.size():\t" << mstack.size() << '\n';
	
	std::cout << "mstack.top():\t" << mstack.top() << '\n';
	
	mstack.pop();
	std::cout << "pop of mstack\n";

	std::cout << "\n\t----\n\n";
	
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
		mstack.push(rand() % 10000);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	std::cout << "*mstack.begin(): " << *it << '\n';

	++it;
	--it;
	
	std::cout << "iterate over mstack:\n";
	while (it != ite)
	{
		std::cout << *it << ", ";
		++it;
	}
	std::cout << '\n';

	std::cout << "\n\t----\n\n";

	std::stack<int, std::list<int> > s(mstack);

	s.push(0);

	std::cout << "copy size: " << s.size() << '\n';
	std::cout << "orig size: " << mstack.size() << '\n';
	
	std::cout << '\n';
	
	return (0);
}