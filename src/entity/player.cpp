#include <player.hpp>

void Player::update(float time)
{
    switch (state)
    {
    case right: dx = speed; dxT = speed; 
        break;
    case left: dx = -speed;  dxT = -speed; 
        
        break;
    case up: break;
    case down: break;
    case jump:  break;
    case stay: dx = 0; CurrentFrame = 0; break;
    }
    if(state != climb)
        y += dy * time;
    if (!isMove) {
        speed = 0;
    }
    move({dx * time, dy * time});
    if (state != climb) {
        dy = dy + 0.0015*time;
    }
}