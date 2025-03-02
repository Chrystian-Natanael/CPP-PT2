/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:28:52 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 13:30:04 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include "Colors.hpp"
#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t lenght, F function) {
	if (!function || !array)
		return;
	for (size_t i = 0; i < lenght; ++i)
		function(*(array + i));
}

template <typename T> void print(const T &val) { std::cout << Y << val << RST;}

template <typename T> void increment(T &val) {
	val += 1;
	std::cout << Y << val << RST;
}

template <typename T> void oddEven(T const &val) {
	std::cout << Y << val << (val % 2 == 0 ? " Even" : " Odd") << RST << std::endl;
}

#endif //! ITER_HPP