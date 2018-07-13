/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <avella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 15:10:42 by avella            #+#    #+#             */
/*   Updated: 2017/06/18 15:16:42 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

class AEntity{

public:
    virtual ~AEntity() {}
    virtual  double getTime() const = 0;
    virtual    int getMaxWidth() const = 0;
    virtual int getMaxHeight() const = 0;
    virtual    void setTime(double time) = 0;
    virtual    void setMaxHeight(int height) = 0;
    virtual    void setMaxWidth(int width) = 0;
    virtual std::string getForm() = 0;
private:
    AEntity(AEntity const & src);
    AEntity					&operator=(AEntity const & rhs);
};
#endif
