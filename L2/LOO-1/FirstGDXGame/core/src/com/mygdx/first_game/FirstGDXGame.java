package com.mygdx.first_game;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.glutils.ShapeRenderer;
import com.badlogic.gdx.graphics.GL20;

import java.util.ArrayList;

public class FirstGDXGame extends ApplicationAdapter
{
	ShapeRenderer shape;
	Ball ball = null;
	Paddle paddle = null;
	ArrayList<Block> blocks = new ArrayList<>();

	@Override
	public void create()
	{
		shape = new ShapeRenderer();
		ball = new Ball(25, 25, 5, 3, 7);
		paddle = new Paddle(0, 30, 100, 10);

		int blockWidth = 63;
		int blockHeight = 20;
		for (int y = Gdx.graphics.getHeight()/2; y < Gdx.graphics.getHeight(); y += blockHeight + 10)
		{
			for (int x = 0; x < Gdx.graphics.getWidth(); x += blockWidth + 10)
			{
				blocks.add(new Block(x, y, blockWidth, blockHeight));
			}
		}
	}

	@Override
	public void render()
	{
		Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);
		shape.begin(ShapeRenderer.ShapeType.Filled);

		ball.update();
		paddle.update();

		ball.checkCollision(paddle);
		for (Block b : blocks) { ball.checkCollision(b); }

		for (int i = 0; i < blocks.size(); i++) {
			Block b = blocks.get(i);
			if (b.destroyed) { blocks.remove(b); i--; }
			b.draw(shape);
		}
		ball.draw(shape);
		paddle.draw(shape);

		shape.end();
	}
}