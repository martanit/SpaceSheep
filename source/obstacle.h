/*
 * SpaceSheep, ncurses game. Code is hosted on GitHub.
 *
 * File: obstacle.h
 *
 * Class that defines obstacles, every object has a HitBox member to handle
 *  collision between obstacles.
 *
 * Authors:
 *	Martina Crippa 				<martina.crippa2@studenti.unimi.it>
 *	Pietro Francesco Fontana 	<pietrofrancesco.fontana@studenti.unimi.it>
 *
 *******************************************************************************
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *******************************************************************************
 */

#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "hitbox.h"

class RectObstacle
{
	public:
		RectObstacle(int x, int y, unsigned int width, unsigned int height);
		RectObstacle(position v, rectangle rec);
		~RectObstacle(){ }

		HitBoxRect& get_hitbox(){ return m_hitbox; }
		position get_v() const { return m_v; }
		rectangle get_rec() const { return m_rec; }
		void set_hitbox(HitBoxRect& tmp_hitbox) { m_hitbox = tmp_hitbox; }
		void drop();

	private:
		HitBoxRect m_hitbox;
		position m_v;
		rectangle m_rec;

};

class CircleObstacle
{
	public:
		CircleObstacle(int x, int y, unsigned int radius = 1);
		CircleObstacle(position ref, unsigned int radius = 1);
		~CircleObstacle(){ }

		HitBoxCircle& get_hitbox(){ return m_hitbox; }
		void set_radius(int radius){ m_radius = radius; }
		position get_ref() const { return m_ref; }
		unsigned int get_radius(){ return m_radius; }

	protected:
		HitBoxCircle m_hitbox;
		position m_ref;
		unsigned int m_radius;

};

class SpaceSheep : public CircleObstacle
{
	public:
		SpaceSheep(int x, int y, unsigned int radius);
		SpaceSheep(position ref, unsigned int radius);
		~SpaceSheep(){ }

		void move(char dir); // move 'r' or 'l' for 2 columns
		void move_to(unsigned int x); // move to 'x' column
};

class SpaceBull : public CircleObstacle
{
	public:
		SpaceBull(int x, int y, unsigned int radius);
		SpaceBull(position ref, unsigned int radius);
		~SpaceBull(){ }

		void drop(); //move to bottom for 1 line
};

#endif // _OBSTACLE_H_
