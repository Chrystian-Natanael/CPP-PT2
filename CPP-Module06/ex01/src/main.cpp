/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:26:01 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 12:27:06 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Colors.hpp"
#include "Serializer.hpp"
#include <iostream>

static void printData(const Data *p) {
  std::cout << Y << "Name: "<< RST << p->name << std::endl;
  std::cout << Y << "Size: "<< RST << p->size << std::endl;
  std::cout << Y << "Model: "<< RST << p->model << std::endl;
  std::cout << Y << "Height: "<< RST << p->height << std::endl;
  std::cout << Y << "Width: "<< RST << p->width << std::endl;
  std::cout << std::endl;
}

int main(void) {
  Data *clothing = new Data();

  clothing->name = "t-shirt";
  clothing->size = 'L';
  clothing->model = 23;
  clothing->height = 70.0;
  clothing->width = 50.0f;

  uintptr_t ptr;

  std::cout << RED << "Data before serialize" << RST << std::endl;
  printData(clothing);

  ptr = Serializer::serialize(clothing);

  std::cout << RED << "Data after serialize" << RST << std::endl;
  printData(clothing);

  Data *testData;

  testData = Serializer::deserialize(ptr);
  std::cout << RED << "Data after deserialize" << RST << std::endl;
  printData(testData);

  delete clothing;

  return 0;
}