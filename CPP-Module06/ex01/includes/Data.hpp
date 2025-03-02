/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:17:36 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 12:23:52 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <cstddef>
#include <string>

struct Data {
	std::string	name;
	std::size_t	model;
	char		size;
	float		width;
	double		height;
};

#endif //! DATA_HPP