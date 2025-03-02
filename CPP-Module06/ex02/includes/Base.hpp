/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:49:14 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 12:49:33 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
	virtual	~Base();
};

Base	*generate(void);

void	identify(Base *p);

void	identify(Base &p);

#endif // !BASE_HPP