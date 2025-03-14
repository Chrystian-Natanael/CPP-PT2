/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:23:03 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/14 15:03:37 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <map>
#define MAX_BTC 1000

class BitcoinExchange {
 public:
	BitcoinExchange(const std::map<std::string, float>& dataMap);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

	void makeExchange(const std::string& input) const;

 private:
	BitcoinExchange();
	
	const std::map<std::string, float>& data;
	bool validateValue(const float value) const;
	BitcoinExchange& operator=(const BitcoinExchange& other);
};

#endif //! BITCOINEXCHANGE_HPP