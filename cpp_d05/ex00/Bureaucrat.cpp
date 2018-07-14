/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:42:25 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/02 13:42:26 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _grade(grade), _name(name)
{
	this->setGrade(grade);
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}

Bureaucrat &				Bureaucrat::operator=(Bureaucrat const & rhs)
{
	this->_grade = rhs.getGrade();
	return *this;
}

std::string	const &			Bureaucrat::getName(void) const
{
	return this->_name;
}

int							Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void						Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat &				Bureaucrat::operator++(void)
{
	this->_grade += 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return *this;
}


Bureaucrat &				Bureaucrat::operator--(void)
{
	this->_grade -= 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw()
{
	return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
	*this = src;
	return ;
}

Bureaucrat::GradeTooHighException & 	Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & src) throw()
{
	static_cast <void> (src);
	return *this;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return ;
}

const char					*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too hight (< 1).");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw()
{
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
	*this = src;
	return ;
}

Bureaucrat::GradeTooLowException & 		Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & src) throw()
{
	static_cast <void> (src);
	return *this;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return ;
}

const char					*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low (> 150)");
}

std::ostream &		operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	o << "." << std::endl;
	return o;
}












