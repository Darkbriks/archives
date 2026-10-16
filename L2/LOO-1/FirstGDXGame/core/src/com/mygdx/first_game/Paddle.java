package com.mygdx.first_game;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.graphics.glutils.ShapeRenderer;

public class Paddle
{
    int x, y, width, height, speed;

    public Paddle(int x, int y, int width, int height)
    {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    public void update()
    {
        this.x = Gdx.input.getX();

        if (x < 0) { x = 0; }
        if (x > Gdx.graphics.getWidth() - width) { x = Gdx.graphics.getWidth() - width; }
        if (y < 0) { y = 0; }
        if (y > Gdx.graphics.getHeight() - height) { y = Gdx.graphics.getHeight() - height; }
    }

    public void draw(ShapeRenderer shape)
    {
        shape.rect(x, y, width, height);
    }
}
