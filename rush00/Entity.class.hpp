/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 15:11:10 by avella            #+#    #+#             */
/*   Updated: 2017/06/18 15:11:12 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_CLASS_HPP
# define ENTITY_CLASS_HPP

#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>


class Entity {

    public:
        int val;
        int						x, y;
        virtual ~Entity();
        Entity(std::string form);
        Entity(Entity const & src);
        Entity		&operator=(Entity const & rhs);



        double getTime() const;
        int getMaxWidth() const;
        int getMaxHeight() const;
        void setTime(double time);
        void setMaxHeight(int height);
        void setMaxWidth(int width);
        std::string getForm();
    private:
    	double					_time;
    	int						_maxwidth, _maxheight;
        std::string		form;


};
#endif
