/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:23:40 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/06 16:23:42 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{

public:

	Form(std::string const name, bool isSigned, int const gradeToSign,
			int const gradeToExec);
	Form(Form const & src);
	~Form(void);
	Form				&operator=(Form const & rhs);

	std::string	const	&getName(void) const;
	int			const	getGradeToSign(void) const;
	int			const	getGradeToExec(void) const;
	void				setGradeToSign(int gradeToSign);
	void				setGradeToExec(int gradeToExec);
	Form				&besigned(Bureaucrat const & brt);
	void				signForm(Bureaucrat const & src);

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(void) throw();
		GradeTooHighException(GradeTooHighException const & src);
		GradeTooHighException 		&operator=(GradeTooHighException const & src) throw();
		virtual ~GradeTooHighException(void) throw();
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(void) throw();
		GradeTooLowException(GradeTooLowException const & src);
		GradeTooLowException 		&operator=(GradeTooLowException const & src) throw();
		virtual ~GradeTooLowException(void) throw();
		virtual const char* what() const throw();
	};

private:

	std::string const	_name;
	bool				_signed;
	int 		const	_gradeToSign;
	int 		const	_gradeToExec;

};

#endif