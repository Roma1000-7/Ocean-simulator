//Romashka

#ifndef __OCEAN_H__
#define __OCEAN_H__
using std::vector;

class Ocean{
private:
    vector <OceanOb*> objects{};

public:
    ~Ocean(){
        for(auto ob: objects){
            delete ob;
        }
    }
    void add_object(int type, COLORREF bcolor0, HDC d0, HDC sprite0, double xD0, double yD0, double w0, double h0, double xScr0, double yScr0, double wScr0, double hScr0, double v0 = 0, int course0 = 0);
    void update();
    void checkCollis() const;
    void removeDead();
};
void Ocean::add_object(int type, COLORREF bcolor0,  HDC d0, HDC sprite0, double xD0, double yD0, double w0, double h0, double xScr0, double yScr0, double wScr0, double hScr0, double v0, int course0){
    OceanOb* newOb = nullptr;
    if(type == 1)
        newOb = new Stone(d0, sprite0, xD0, yD0, w0, h0, xScr0, yScr0, wScr0, hScr0, bcolor0);
    else if(type == 2)
        newOb = new Corall(d0, sprite0, xD0, yD0, w0, h0, xScr0, yScr0, wScr0, hScr0, bcolor0);
    else if(type == 3)
        newOb = new Seaweed(d0, sprite0, xD0, yD0, w0, h0, xScr0, yScr0, wScr0, hScr0, bcolor0);
    else if(type == 4)
        newOb = new Fish(d0, sprite0, xD0, yD0, w0, h0, xScr0, yScr0, wScr0, hScr0, v0, bcolor0, course0);
    else
        newOb = new Hunter(d0, sprite0, xD0, yD0, w0, h0, xScr0, yScr0, wScr0, hScr0, v0, bcolor0);
    if(newOb)
        objects.push_back(newOb);
}
void Ocean::update(){
    for(auto ob: objects){
        ob->change();
        ob->change_sprite();
        ob->draw();
        checkCollis();
        removeDead();
    }
}

void Ocean::checkCollis() const{
    for(int i = objects.size(); i > 0; i--){
        for(int j = objects.size() - 1; j > 0; j--){
            if(objects[i]->hasCollis(objects[j])){
                objects[i]->collied(objects[j]);
                objects[j]->collied(objects[i]);
            }
        }
    }
}

void Ocean::removeDead(){
    for(int i = objects.size(); i > 0; i--){
        if(objects[i]->isDead()){
            delete objects[i];
            objects.erase(objects.begin() + i);
        }
    }
}

#endif // __OCEAN_H__
