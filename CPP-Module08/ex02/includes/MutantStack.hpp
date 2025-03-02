/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:35:42 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 16:36:30 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &rhs);
	MutantStack &operator=(const MutantStack &rhs);

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
};

#include "MutantStack.tpp"

#endif //! MUTANTSTACK_HPP