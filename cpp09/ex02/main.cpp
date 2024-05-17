/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:17:38 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/21 19:06:43 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename T, template<typename, typename> class Container>
void printN(Container<T, std::allocator<T> >&cont, std::string str)
{
	std::cout << str;
	for (typename Container<T, std::allocator<T> >::iterator it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << " ";
	std::cout <<  std::endl;
}

template<typename T, template<typename, typename> class Container>
void printMsg(int argc, t_crono::time_point &start, t_crono::time_point &end, Container<T, std::allocator<T> >&cont)
{
	std::chrono::microseconds lapse = std::chrono::duration_cast<std::chrono::microseconds>(start - end);

	std::cout << "Time to process a range of " << argc-1 << " elements with std::";
	typeid(cont) == typeid(std::vector<int>) ? std::cout << "vector<int> : " : std::cout << "std::deque<int> : ";
	std::cout << lapse.count() << "us." << std::endl; //output
}

int main(int argc, char **argv)
{
	try
	{
		std::vector<int> 			vector;
		std::deque<int> 			deque;
		t_crono::time_point 			end;
		t_crono::time_point 			start;
		
		PmergeMe<int, std::vector>::parseArgv(vector, argc, argv); 	//parse from terminal to std::vector<int>
		printN(vector,  std::string("Vector before: "));	//print inicial numbers
		
		end = t_crono::now();	//t_crono: START
		PmergeMe<int, std::vector>::MergeSort(vector);	//launch algoritm
		start = t_crono::now();	//t_crono END
		
		printN(vector,  std::string("Vector after:  ")); //print sorted numbers
		printMsg(argc, start, end, vector);
		PmergeMe<int, std::deque>::parseArgv(deque, argc, argv);	//parse from terminal to std::deque<int>
		
		end = t_crono::now();	//t_crono: START
		PmergeMe<int, std::deque>::MergeSort(deque);	//launch algoritm
		start = t_crono::now();	//t_crono END
		
		printMsg(argc, start, end, deque);
	}catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}