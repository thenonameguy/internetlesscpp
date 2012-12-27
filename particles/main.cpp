#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <time.h>
#include <random>
#include <vector>

using namespace std;

struct Particle {
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::RectangleShape sprite;
	void update()
	{
		if(active)
		{
			--life;
			pos+=vel;
			sprite.setPosition(pos);
		}
		active=isActive();
	}
	void activate(int l)
	{
		active=true;
		life=l;
	}
	bool isActive() const {return life>0;	}
	int life;
	bool active;
	void init(const Particle& other)
	{
		pos=sf::Vector2f(other.pos.x,other.pos.y+other.sprite.getSize().y/2);
		vel=sf::Vector2f(-other.vel.x+rand()%2-0.5,-other.vel.y+rand()%2-0.5);
		activate(10);
	}
	bool isDisplayable() const {return vel.x<0;}
};

int main(int argc, const char *argv[])
{
	const int WIDTH=800;
	const int HEIGHT=600;
	Particle emitter;
	emitter.pos=sf::Vector2f(WIDTH/2,HEIGHT/2);
	emitter.vel=sf::Vector2f(1,1);
	emitter.sprite=sf::RectangleShape(sf::Vector2f(32,10));

	srand(time(NULL));
	int particlecount=100;
	int neededparts=50;
	vector<Particle> particles;
	for (int i = 0; i < particlecount; ++i) {
		particles.push_back(Particle());
		particles[i].pos=emitter.pos;
		particles[i].vel=-emitter.vel;
		particles[i].sprite=sf::RectangleShape(sf::Vector2f(2,2));
		particles[i].sprite.setFillColor(sf::Color::Red);
		particles[i].life=-1;
	}

	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"Particles");
	window.setFramerateLimit(120);
	window.setVerticalSyncEnabled(true);
	int speed=2;
	while (window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type==sf::Event::Closed)
				window.close();
		}
		emitter.vel=sf::Vector2f();
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			++speed;
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			--speed;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			emitter.vel.x=-speed;
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			emitter.vel.x=speed;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			emitter.vel.y=-speed;
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			emitter.vel.y=speed;
		}
		int active=0;
		for (int i = 0; i < particlecount; ++i) {
			if(particles[i].isActive())
			{
				++active;
				particles[i].update();
			}
			else if(active<neededparts)
				particles[i].init(emitter);
		}
		emitter.activate(100);
		emitter.update();
		window.clear();
		for (int i = 0; i < particlecount; ++i) {
			if(particles[i].isActive() && particles[i].isDisplayable())
				window.draw(particles[i].sprite);
		}
		window.draw(emitter.sprite);
		window.display();
	}
	return 0;
}
