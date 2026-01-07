#include <enemy.hpp>

void Enemy::update(float time)
{
    switch (state)
    {
    case RIGHT: 
        dx = speed;  
        CurrentFrame += 0.005*time;
        if (CurrentFrame > 3) CurrentFrame -= 3;
        setTextureRect({{13 * int(CurrentFrame) + 13, 0 },{-13, 16}});
        break;
    case LEFT: 
        dx = -speed;  
        CurrentFrame += 0.005*time;
        if (CurrentFrame > 3) CurrentFrame -= 3;
        setTextureRect({{13 * int(CurrentFrame), 0}, {13, 16}});
        break;
    }
    move({dx * time, dy * time});
    dy = dy + 0.0015*time;
}