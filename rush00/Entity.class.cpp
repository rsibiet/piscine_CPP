/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 15:11:05 by avella            #+#    #+#             */
/*   Updated: 2017/06/18 15:11:06 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.class.hpp"



Entity::~Entity(){

    return;
}

Entity::Entity(std::string form) : val(0),_time(0), form(form){

    return;
}
Entity::Entity(Entity const & src){
    *this = src;
    return ;
}

void Entity::setTime(double time){
    this->_time = time;
}
void Entity::setMaxHeight(int height){
    this->_maxheight = height;
}
void Entity::setMaxWidth(int width){
    this->_maxwidth = width;
}

double 	Entity::getTime() const{
    return this->_time;
}
int 	Entity::getMaxWidth() const{
    return this->_maxwidth;
}
int 	Entity::getMaxHeight() const{
    return this->_maxheight;
}
std::string 	Entity::getForm(){
    return this->form;
}

Entity		&Entity::operator=(Entity const & rhs){
    this->val = rhs.val;
    setTime(rhs.getTime());
    setMaxHeight(rhs.getMaxHeight());
    setMaxWidth(rhs.getMaxWidth());
    this->x = rhs.x;
	this->y = rhs.y;
    return *this;
}
