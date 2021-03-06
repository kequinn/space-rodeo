#include <SFML/Graphics.hpp>
#include "sr-control.h"
#include "sr-hud.h"
#include <fstream>
#include <string>
#include <sstream>
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
class View{
  public:
    typedef enum {
      START,
      EXIT,
      NEXTLEVEL,
      RETRY,
      RESTART,} transtate;
    View();
    int transitionscreen(int,int,bool,bool);
    void drawAll(std::vector<CircleModel*>&, std::vector<sf::Drawable*>&);
    void drawcrash(std::vector<CircleModel*>&, std::vector<sf::Drawable*>&,HUD& hud);
    void setController(Control&);
    bool isRun();
    void drawHUD(HUD&);
    void clear();
    void display();
  private:
    sf::RenderWindow _view;
    sf::Event _event;
    Control* _controller;
    sf::Texture _bgtexture;
    sf::Sprite _bgsprite;
    sf::Sprite _mainsprite;
    sf::Texture _maintexture;
};
