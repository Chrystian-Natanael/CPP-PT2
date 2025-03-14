/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:43:31 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/14 15:59:04 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdlib>
#include <string>

std::string trim(const std::string &str);

bool isOp(char c);

bool doubleDigit(const std::string &str);

std::string trimInternSpaces(const std::string &str);

std::string trim(const std::string &str);

int performOperation(char op, int a, int b);

bool nbOp(const std::string &str);

#endif // !UTILS_HPP
