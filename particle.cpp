#include <QTransform>
#include "particle.h"

using namespace std;

Particle::Particle(float radius, float angle)
{
    vec.setX(radius * cos(angle));
    vec.setY(radius * sin(angle));
}

void Particle::RandMove()
{
    QTime tim = QTime::currentTime();
    int ms = tim.msec();
    int min = tim.minute();
    vec.setX(vec.x() - 1);
    static std::default_random_engine e(min * 10 + ms);

    //vec.setY(vec.y() - 1);
    //std::random_device rd;
    //std::mt19937 gen(rd());

    static std::uniform_int_distribution<> distrib(-R, R);
    vec.setY(vec.y() - 1.0 * distrib(e));

    //if(vec.x() < 1.0) return;
    //if(vec.y() > 0.0)
    //    vec.setY(std::min<float>(vec.y(), vec.x() * std::tan(30.0)));
    //else if(vec.y() < 0.0)
    //    vec.setY(R + distrib(gen));
}

bool Particle::Intersects(const std::vector<Particle> &v) const
{
    for(const Particle& p: v) {
        if(p.vec.distanceToPoint(vec) < R) {
            return true;
        }
    }
    return false;
}

