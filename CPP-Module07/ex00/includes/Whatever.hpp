/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:12:25 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 13:12:35 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> void swap(T &first, T &second) {
	T holder = first;
	first = second;
	second = holder;
}

template <typename T> T min(T const &first, T const &second) {
	return first < second ? first : second;
}

template <typename T> T max(T const &first, T const &second) {
	return first > second ? first : second;
}

#endif //! WHATEVER_HPP