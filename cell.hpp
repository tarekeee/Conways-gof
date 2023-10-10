#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
class cell {
    public:
        sf::RectangleShape body;
        float x;
        float y; 
        bool enabled = false;       
        cell(float x,float y,bool enabled = true):x(x),y(y),enabled(enabled), body(sf::Vector2f(16.f,16.f)) {
            body.setPosition(sf::Vector2f(x,y));
        }
        void draw(sf::RenderWindow &window) {
            if (!enabled) return;
            window.draw(body);
        }
};