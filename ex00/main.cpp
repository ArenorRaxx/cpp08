/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:38:02 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/17 17:16:33 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "heads/easyfind.hpp"

int	main(void)
{
	std::vector<int> v1;
    v1.push_back(42);
    v1.push_back(2);
    v1.push_back(34);
    v1.push_back(72);
    
    std::vector<int>::const_iterator iter = easyfind(v1, 42);
    std::cout << *iter << std::endl;;

    try
    {
        iter = easyfind(v1, 3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}