#include <SFML/Graphics.hpp>

class CircleModel: public sf::CircleShape{
  public:
    bool _movable;
    bool intersects(sf::CircleShape *other);
    sf::Vector2f getSpd();
    void setSpd(sf::Vector2f);
  protected:
    sf::Vector2f _spd;
};

class Planet: public CircleModel{
  public:
    Planet(sf::Vector2f,int,int,int);
    int getCowno();
    sf::CircleShape getGravityCircle();
  private:
    int _gravitybound;
    int _cow;
};

class Ship : public CircleModel{
  public:
    typedef enum{
      REST,
      FLY,
      BURST,
      ORBIT,
      CRASH,
      FINISH
    }ShipState;
		
    Ship(sf::Vector2f, int, int);
    int getburst();
    ShipState getState();
    void setState(ShipState);
    void adjustSpd(int);
    void setOrbit(Planet*);
    sf::Vector2f getGravityPull();
		
  private:
    ShipState _shipState;
    int _burst;
		sf::Vector2f _gravityPull;
    Planet* _orbiting;
    sf::Texture _texture;
    sf::Texture* _textpointer;
};

class Cow: public CircleModel{
  public:
    typedef enum{
      FLY,
      WALK
    }CowType;
    Cow(sf::Vector2f,int,Cow::CowType);
  private:
    int _cowValue;
    CowType _cowType;
    CowType getCowType();
    int getCowValue();
};


class SpaceRanch : public CircleModel{
  public:
   SpaceRanch(sf::Vector2f, int);
};

class Models{
  public:
    Models();
    std::vector<CircleModel*> getcirmodels();
  private:
    std::vector<CircleModel*> _circlemodels;
};