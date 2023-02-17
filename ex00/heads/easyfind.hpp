/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:52:19 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/17 17:15:36 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <class T>
typename T::const_iterator easyfind(T const &container, int value)
{
	typename T::const_iterator result;

	result = std::find(container.begin(), container.end(), value);
	if (result == container.end())
		throw std::exception();
	return (result);
}

#endif