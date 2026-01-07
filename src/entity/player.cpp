#include <player.hpp>

void Player::update(float time)
{
    switch (state)
    {
    case RIGHT: dx = speed;
        break;
    case LEFT: dx = -speed;
        
        break;
    case UP: break;
    case DOWN: break;
    case JUMP:  break;
    case STAY: dx = 0; CurrentFrame = 0; break;
    }
    if(state != CLIMB)
        y += dy * time;
    if (!isMove) {
        speed = 0;
    }
    move({dx * time, dy * time});
    if (state != CLIMB) {
        dy = dy + 0.0015*time;
    }
}