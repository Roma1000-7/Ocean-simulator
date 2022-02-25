//Romashka

#ifndef __MOVING_H__
#define __MOVING_H__
const int scr_w = 1500, scr_h = 800;

class MovingOb : public OceanOb{
protected:
    double v;        // Скорость
    int course;      // Курс в градусах
    MovingOb(HDC d0, HDC sprite0, double xD0, double yD0, double w0, double h0, double xScr0, double yScr0, double wScr0, double hScr0, double v0, COLORREF bcolor0, int course0 = 0):
        OceanOb(d0, sprite0, xD0, yD0, w0, h0, xScr0, yScr0, wScr0, hScr0, bcolor0),
        v(v0), course(course0)
        {
        }
public:
    virtual void moving(){
        double cRad = course * M_PI/180;
        xD += round(v * cos(cRad));
        yD -= round(v * sin(cRad));
        if(xD + w < 0)
            xD += scr_w;
        if(xD > scr_w)
            xD -= scr_w + w;
        if(yD + h < 0)
            yD += scr_h;
        if(yD > scr_h)
            yD -= scr_h + h;
    }
};
///Рыба//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Fish : public MovingOb{
public:
    Fish(HDC d0, HDC sprite0, double xD0, double yD0, double w0, double h0, double xScr0, double yScr0, double wScr0, double hScr0, double v0, COLORREF bcolor0, int course0 = 0):
        MovingOb(d0, sprite0, xD0, yD0, w0, h0, xScr0, yScr0, wScr0, hScr0, v0, bcolor0, course0)
        {
            xHB = xD;
            yHB = yD + h/2.4;
            wHB = w/1.65;
            hHB = h/2.53;
        }
    virtual void change() override{
        moving();
    }
    virtual void change_sprite() override{
        if(course <= 90 || course >= 270){
            yScr = OyScr;
            if(xScr >= OxScr + 2*wScr){
                xScr = OxScr;
                yScr += hScr;
                return;
            }
            xScr += wScr;
            yScr += hScr;
        }
        else{
            yScr = OyScr;
            if(xScr <= OxScr){
                xScr = OxScr + 2*wScr;
                return;
            }
            xScr += wScr;
        }
    }
    virtual void draw() const override{
        Win32::TransparentBlt(d, int(xD), int(yD), int(w), int(h), sprite, int(xScr), int(yScr), int(wScr), int(hScr), bcolor);
    }
    virtual void collied(OceanOb* other) override;
};
///Охотник//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////x Охотник лучший слешер АЗАЗАЗАЗАЗАЗА
class Hunter : public MovingOb{
public:
    Hunter(HDC d0, HDC sprite0, double xD0, double yD0, double w0, double h0, double xScr0, double yScr0, double wScr0, double hScr0, double v0, COLORREF bcolor0, int course0 = 0):
        MovingOb(d0, sprite0, xD0, yD0, w0, h0, xScr0, yScr0, wScr0, hScr0, v0, bcolor0, course0)
        {
            xHB = xD/2.2857;
            yHB = yD + h/3.75;
            wHB = w/4;
            hHB = h/2.3;
        }
    virtual void change() override{
        double MouseX = txMouseX(), MouseY = txMouseY();
        double dist = hypot((xD + w/2) - MouseX, (yD + h/2) - MouseY); //Расстояние между курсором и обЪектом
        if(dist <= 1)
            return;
        double part = double(v)/double(dist);
        if(part > 1)
            part = 1;
        xD += round(part * (MouseX - (xD + w/2)));
        yD += round(part * (MouseY - (yD + h/2)));
    }
    virtual void change_sprite() override{
        if(xD + w/2 - txMouseX() < 0){
            yScr = OyScr;
            if(xScr >= OxScr + 2*wScr){
                xScr = OxScr;
                yScr += hScr;
                return;
            }
            xScr += wScr;
            yScr += hScr;
        }
        else{
            yScr = OyScr;
            if(xScr <= OxScr){
                xScr = OxScr + 2*wScr;
                return;
            }
            xScr -= wScr;
        }
    }
    virtual void draw() const override{
        Win32::TransparentBlt(d, int(xD), int(yD), int(w), int(h), sprite, int(xScr), int(yScr), int(wScr), int(hScr), bcolor);
    }
    virtual void collied(OceanOb* other) override;
};

#endif // __MOVING_H__
