/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:48:19 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 13:51:23 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <ostream>

template <typename T> class Array {
private:
	T *_data;
	size_t _size;

public:
	Array();
	Array(const unsigned int &n);
	Array(const Array &rhs);
	~Array();

	Array &operator=(const Array &other);

	unsigned int size() const;

	T const &operator[](const unsigned int &index) const;
	T &operator[](const unsigned int &index);
};

template <typename T>
std::ostream &operator<<(std::ostream &lhs, const Array<T> &rhs);

#include "Array.tpp"

#endif //! ARRAY_HPP