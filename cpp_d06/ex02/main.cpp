/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 11:25:56 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/08 11:25:58 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.class.hpp"

class A : public Base {};
class B : public Base {};
class C : public Base {};

// class A : public Base
// {

// public:

// 	A(void) { return ; };
// 	A(A const & src)
// 	{
// 		*this = src;
// 		return ;
// 	};
// 	~A(void) { return ; };
// 	A		&operator=(A const & rhs) { return *this; };

// };

// class B : public Base
// {

// public:

// 	B(void) { return ; };
// 	B(B const & src)
// 	{
// 		*this = src;
// 		return ;
// 	};
// 	~B(void) { return ; };
// 	B		&operator=(B const & rhs) { return *this; };
// };

// class C : public Base
// {

// public:

// 	C(void) { return ; };
// 	C(C const & src)
// 	{
// 		*this = src;
// 		return ;
// 	};
// 	~C(void) { return ; };
// 	C		&operator=(C const & rhs) { return *this; };

// };

static Base		*generate(void)
{
	int		tmp = rand() % 3;
	Base	*basePtr;

	if (tmp == 0)
		basePtr = new A();
	else if (tmp == 1)
		basePtr = new B();
	else
		basePtr = new C();
	return basePtr;
}

static void		identify_from_pointer(Base *p)
{
	A	*baseA = dynamic_cast<A *>(p);
	B	*baseB = dynamic_cast<B *>(p);

	if (baseA != NULL)
		std::cout << "A" << std::endl;
	else if (baseB != NULL)
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

static void		identify_from_reference(Base &p)
{
	try
	{
		A	&baseA = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		try
		{
			B	&baseB = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast &bc)
		{
			std::cout << "C" << std::endl;
		}
	}
}

int				main (void)
{
	srand(static_cast<unsigned int>(time(NULL)));

	for(int i = 0; i < 6; i++)
	{
		Base	*randBase = generate();
		std::cout << "randBase is a base : " << std::endl; 
		std::cout << "	- using pointer :";
		identify_from_pointer(randBase);
		std::cout << "	- using reference :";
		identify_from_reference(*randBase);
		std::cout << std::endl;
		delete randBase;
	}
	return 0;
}
