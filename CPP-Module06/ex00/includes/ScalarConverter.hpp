/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:38:55 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 11:39:29 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &rhs);
	ScalarConverter &operator=(ScalarConverter const &rhs);

public:
	~ScalarConverter();

	static void convert(const std::string &str);
};

#endif //! SCALARCONVERTER_HPP