/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:48:10 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/21 19:00:51 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <deque>



typedef std::chrono::high_resolution_clock 						t_crono;

template<typename T, template<typename, typename> class Container>
class PmergeMe
{
	private:
		PmergeMe(void);
		
	public:	
		typedef Container<T, std::allocator<T> >& t_Template;
		static void parseArgv(t_Template _container, int argc, char **str)
		{
			T n;
			std::string input;
			
			_container.clear();
			for (int i = 1; i < argc; i++)
			{
				input = str[i];
				std::istringstream iss(input);
				while(iss >> n)
				{
					if (iss.fail() || n < 0)
						throw std::runtime_error("Error");
					_container.push_back(n);
				}
			}
		}

		static void merge(t_Template left, t_Template right, t_Template _container)
		{
			int leftSize = _container.size() / 2;
			int rightSize = _container.size() - leftSize;
			int i = 0; int l = 0; int r = 0;

			while (l < leftSize && r < rightSize)
			{
				if (left[l] < right[r])
				{
					if (typeid(_container) == typeid(std::vector<int>))
						_container[i++] = left[l++];
					if (typeid(_container) == typeid(std::deque<int>))
						_container.at(i++) = left.at(l++);
				}
				else
				{
					if (typeid(_container) == typeid(std::vector<int>))
						_container[i++] = right[r++];
					if (typeid(_container) == typeid(std::deque<int>))
						_container.at(i++) = right.at(r++);
				}
			}
			
			while (l < leftSize)
			{
				if (typeid(_container) == typeid(std::vector<int>))
					_container[i++] = left[l++];
				if (typeid(_container) == typeid(std::deque<int>))
					_container.at(i++) = left.at(l++);
			}

			while (r < rightSize)
			{
				if (typeid(_container) == typeid(std::vector<int>))
					_container[i++] = right[r++];
				if (typeid(_container) == typeid(std::deque<int>))
					_container.at(i++) = right.at(r++);	
			}
		}

		static void MergeSort(t_Template _container)
		{
			int length = _container.size();
			int middle = length / 2;
			if (length <= 1)
				return;
			Container<T, std::allocator<T> > left(_container.begin(), _container.begin() + middle);
			Container<T, std::allocator<T> > right(_container.begin() + middle, _container.end());
			
			PmergeMe<T, Container>::MergeSort(left);
			PmergeMe<T, Container>::MergeSort(right);
			PmergeMe<T, Container>::merge(left, right, _container);

		}
    

};

#endif