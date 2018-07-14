/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:23:33 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/06 16:23:34 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, bool isSigned, int const gradeToSign,
				int const gradeToExec): _name(name), _signed(isSigned),
										_gradeToSign(gradeToSign),
										_gradeToExec(gradeToExec)
{
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw Form::GradeTooLowException();
	this->setGradeToSign(gradeToSign);
	this->setGradeToExec(gradeToExec);
	return ;
}

Form::Form(Form const & src)
{
	*this = src;
	if (src.getGradeToSign() < 1 || src.getGradeToExec() < 1)
		throw Form::GradeTooHighException();
	else if (src.getGradeToSign() > 150 || src.getGradeToExec() > 150)
		throw Form::GradeTooLowException();
	return ;
}

Form::~Form(void)
{
	return ;
}

Form &					Form::operator=(Form const & rhs)
{
	this->_gradeToSign = rhs.getGradeToSign();
	this->_gradeToExec = rhs.getGradeToExec();
	return *this;
}

std::string	const &		Form::getName(void) const
{
	return this->_name;
}

int			const		Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int			const		Form::getGradeToExec(void) const
{
	return this->_gradeToExec;
}

void					Form::setGradeToSign(int gradeToSign)
{
	this->_gradeToSign = gradeToSign;
}

void					Form::setGradeToExec(int gradeToExec)
{
	this->_gradeToExec = gradeToExec;
}


Form &					Form::besigned(Bureaucrat const & brt)
{
	int grade = brt.getGrade();

	if (grade <= this->_gradeToSign && grade >= 1 && grade <= 150)
		this->_signed = true;
	else
		this->_signed = false;
	if (grade > 150 || grade > this->_gradeToSign)
		throw Form::GradeTooLowException();
	return *this;
}

void					Form::signForm(Bureaucrat const & src)
{
	int grade = src.getGrade();

	this = besigned(src);
	if (this->_signed == true)
		std::cout << src.getName() << " signs " << this->_name << std::endl;
	else
	{
		std::cout << src.getName() << " cannot sign " << this->_name;
		std::cout << " because ";
		if (grade > 150 || grade > this->_gradeToSign)
			throw Form::GradeTooLowException();
		else
			throw Form::GradeTooHighException();
		std::cout << std::endl;
	}
}

Form::GradeTooHighException::GradeTooHighException(void) throw()
{
	return ;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
	*this = src;
	return ;
}

Form::GradeTooHighException & 		Form::GradeTooHighException::operator=(GradeTooHighException const & src) throw()
{
	static_cast <void> (src);
	return *this;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return ;
}

const char							*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too hight.");
}

Form::GradeTooLowException::GradeTooLowException(void) throw()
{
	return ;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
	*this = src;
	return ;
}

Form::GradeTooLowException & 		Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & src) throw()
{
	static_cast <void> (src);
	return *this;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return ;
}

const char							*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}



