package com.mygdx.first_game;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.glutils.ShapeRenderer;

public class Ball
{
    int x, y, size, xSpeed, ySpeed;
    Color color = Color.WHITE;

    public Ball(int x, int y, int size, int xSpeed, int ySpeed)
    {
        this.x = x;
        this.y = y;
        this.size = size;
        this.xSpeed = xSpeed;
        this.ySpeed = ySpeed;
    }

    public void update()
    {
        x += xSpeed;
        y += ySpeed;
        if (x < size || x > Gdx.graphics.getWidth() - size) { xSpeed = -xSpeed; }
        if (y < size || y > Gdx.graphics.getHeight() - size) { ySpeed = -ySpeed; }
    }

    public void checkCollision(Paddle paddle) { if(collidesWith(paddle)) { this.ySpeed *= -1; } }

    public void checkCollision(Block block) { if(collidesWith(block)) { this.ySpeed *= -1; block.destroyed = true; } }

    private boolean collidesWith(Paddle paddle) { return this.x > paddle.x - this.size && this.x < paddle.x + paddle.width + this.size && this.y > paddle.y - this.size && this.y < paddle.y + paddle.height + this.size; }

    private boolean collidesWith(Block block) { return this.x > block.x - this.size && this.x < block.x + block.width + this.size && this.y > block.y - this.size && this.y < block.y + block.height + this.size; }


    public void draw(ShapeRenderer shape)
    {
        shape.setColor(color);
        shape.circle(x, y, size);
    }
}
