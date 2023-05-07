#include "ball.hpp"
#include "paddle.hpp"

Ball::Ball(int width, int height, float x, float y)
{
	ball.setSize(sf::Vector2f(width, height));
	ball.setOrigin(width / 2, height / 2);
	ball.setPosition(sf::Vector2f(x, y));
	ball.setFillColor(sf::Color(200, 200, 200));
}

void Ball::drawTo(sf::RenderWindow& window)
{
	window.draw(ball);
}

void Ball::moveBall()
{
	velocity.x = step_x * cos(random_angle * M_PI / 180);
	velocity.y = step_y * sin(random_angle * M_PI / 180);
	ball.move(velocity);
}

void Ball::collision(Paddle& paddle_rect)
{
	// If ball hits paddle reverse y direction
	auto paddle = paddle_rect.paddle;
	if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
	{
		step_y *= -1;
		ball.setPosition(ball.getPosition().x, paddle.getPosition().y - 10);
	}

	// If ball hits window borders reverse direction
	if (ball.getPosition().x >= 695)
	{
		step_x *= -1;
	}
	else if (ball.getPosition().x <= 5)
	{
		step_x *= -1;
	}

	if (ball.getPosition().y <= 4)
	{
		step_y *= -1;
	}
}