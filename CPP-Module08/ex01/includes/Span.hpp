/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Spam.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:29:08 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 15:29:22 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iterator>
#include <stdexcept>
#include <vector>

class Span {
private:
	std::vector<int> _numbers;
	unsigned int _maxSize;

public:
	Span();
	Span(unsigned int N);
	Span(Span const &rhs);
	Span &operator=(Span const &rhs);
	~Span();

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	template <typename Iterator> void addRange(Iterator begin, Iterator end) {
		if (std::distance(begin, end) > static_cast<int>(_maxSize)) {
			throw std::overflow_error("Not enough space in Span to add entire range");
		}
		_numbers.insert(_numbers.end(), begin, end);
	}
};

#endif // SPAN_HPP