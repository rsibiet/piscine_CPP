/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:42:32 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/02 13:42:33 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
#include <iostream>
#include <stdexcept>

class Bureaucrat
{

public:

	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat(void);
	Bureaucrat 			&operator=(Bureaucrat const & rhs);

	std::string	const	&getName(void) const;
	int					getGrade(void) const;
	void				setGrade(int grade);
	Bureaucrat 			&operator++(void);
	Bureaucrat 			&operator--(void);

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
	int					_grade;

};

std::ostream &			operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
