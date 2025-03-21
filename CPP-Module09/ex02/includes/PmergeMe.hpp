/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:17:25 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/19 17:15:42 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "Colors.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <ostream>
#include <set>
#include <stdexcept>
#include <vector>

extern bool printAfter;

class Ford {
private:
	std::vector<int> _vseq;
	std::list<int> _lseq;
	Ford();

public:
	Ford(const std::vector<int> &nb, const std::list<int> &lnb);
	Ford(const Ford &rhs);
	Ford &operator=(const Ford &rhs);
	~Ford();

	std::vector<int> getVector(void) const;
	std::list<int> getList(void) const;
};

template <typename Iterator>
void merge(Iterator first, Iterator mid, Iterator last) {
	typedef typename std::iterator_traits<Iterator>::value_type T;
	std::vector<T> sortedSeq;
	sortedSeq.reserve(std::distance(first, last));

	Iterator it1 = first;
	Iterator it2 = mid;
	while (it1 != mid && it2 != last) {
		if (*it1 < *it2) {
			sortedSeq.push_back(*it1);
			++it1;
		} else {
			sortedSeq.push_back(*it2);
			++it2;
		}
	}
	while (it1 != mid) {
		sortedSeq.push_back(*it1);
		++it1;
	}
	while (it2 != last) {
		sortedSeq.push_back(*it2);
		++it2;
	}

	std::copy(sortedSeq.begin(), sortedSeq.end(), first);
}

template <typename Iterator> void insertionSort(Iterator first, Iterator last) {
	typedef typename std::iterator_traits<Iterator>::value_type ValueType;

	if (first == last)
		return;

	for (Iterator it = first; it != last; ++it) {
		Iterator current = it;
		Iterator previous = it;
		if (current != first) {
			--previous;
		}
		ValueType key = *current;
		while (current != first && *previous > key) {
			*current = *previous;
			current = previous;
			if (previous != first) {
			--previous;
			}
		}
		*current = key;
	}
}

const int threshold = 10;

template <typename Iterator>
void mergeInsertSortRecursively(Iterator first, Iterator last) {
	if (std::distance(first, last) <= 1)
		return;

	if (std::distance(first, last) <= threshold) {
		insertionSort(first, last);
		return;
	}
	Iterator mid = first;
	std::advance(mid, std::distance(first, last) / 2);
	mergeInsertSortRecursively(first, mid);
	mergeInsertSortRecursively(mid, last);

	merge(first, mid, last);
}

template <typename Container> void mergeInsertSort(Container &seq) {
	mergeInsertSortRecursively(seq.begin(), seq.end());
}

template <typename Container>
Container validateAndProcessInput(char **input, int &elements) {
	Container numbers;
	std::set<typename Container::value_type> seenNumbers;

	for (int i = 1; i < elements; ++i) {
		int num = std::atoi(input[i]);
		if (num <= 0) {
			throw std::invalid_argument(
				"Number must be positive or not double signal.");
		}
		if (!seenNumbers.insert(num).second) {
			std::cout << "Duplicate number detected: " << num << std::endl;
			throw std::invalid_argument("Duplicate number detected.");
		}
		numbers.push_back(num);
	}
	return numbers;
}

template <typename Container> void printSequence(const Container &seq) {
	typename Container::const_iterator it;
	for (it = seq.begin(); it != seq.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename Container>
void displayTime(Container &seq, const std::string &containerName) {
	clock_t start = clock();
	mergeInsertSort(seq);
	clock_t end = clock();
	if (printAfter) {
		std::cout << B << "after: ";
		printSequence(seq);
		std::cout << "\n" << RST;
	}
	double timeInSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << Y << seq.size()
			<< " elements with" << B << " std::" << containerName << RST
			<< ": " << (timeInSeconds * 1000.0) << " us" << std::endl;
}

#endif // !PMERGEME_HPP