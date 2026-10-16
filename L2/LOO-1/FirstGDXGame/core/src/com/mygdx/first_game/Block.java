package com.mygdx.first_game;

import com.badlogic.gdx.graphics.glutils.ShapeRenderer;

public class Block
{
    int x, y, width, height;
    boolean destroyed;

    public Block(int x, int y, int width, int height)
    {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.destroyed = false;
    }

    public void draw(ShapeRenderer shape) { if (this.destroyed) return; shape.rect(x, y, width, height); }
}
