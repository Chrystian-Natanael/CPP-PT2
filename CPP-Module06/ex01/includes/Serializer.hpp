/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:18:12 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 12:19:39 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

typedef unsigned int *uintptr_t;

class Serializer {
private:
	Serializer();

	Serializer(Serializer const &rhs);

	Serializer &operator=(Serializer const &rhs);

public:
	~Serializer();

	static uintptr_t serialize(Data *ptr);

	static Data *deserialize(uintptr_t raw);
};

#endif //! SERIALIZER_HPP