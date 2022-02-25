//Romashka

#ifndef __OCEANOB_H__
#define __OCEANOB_H__
#include <math.h>

class OceanOb{
protected:
    HDC d;                          /// <-  Дескриптор приемного DC
    HDC sprite;                     /// <-  Спрайты объекта
    double xD;                      /// <-  Х-координата верхнего левого угла изображения-приемника
    double yD;                      /// <-  Y-координата верхнего левого угла изображения-приемника
    double w;                       /// <-  Ширина копируемого изображения, неотрицательная
    double h;                       /// <-  Высота копируемого изображения, неотрицательная
    double xScr;                    /// <-  Х-координата верхнего левого угла изображения-источника
    double yScr;                    /// <-  Y-координата верхнего левого угла изображения-источника
    double wScr;                    /// <-  Ширина источникового  прямоугольника
    double hScr;                    /// <-  Высота источникового  прямоугольника
    double OxScr = xScr;            /// <-  Хранит начальное значение переменной xScr
    double OyScr = yScr;            /// <-  Хранит начальное значение переменной yScr
    double xHB = 0;                 /// <-  X-координата верхнего левого угла хитбокса
    double yHB = 0;                 /// <-  Y-координата верхнего левого угла хитбокса
    double wHB = 0;                 /// <-  Высота хитбокса
    double hHB = 0;                 /// <-  Ширина хитбокса
    int life = 1;                   /// <-  Хранит состояние объекта: 0 - мертвый, 1 - живой
    COLORREF bcolor;                /// <-  Цвет, который будет считаться прозрачным
    OceanOb(HDC d0, HDC sprite0, double xD0, double yD0, double w0, double h0, double xScr0, double yScr0, double wScr0, double hScr0, COLORREF bcolor0):
        d(d0), sprite(sprite0), xD(xD0), yD(yD0), w(w0), h(h0), xScr(xScr0), yScr(yScr0), wScr(wScr0), hScr(hScr0), bcolor(bcolor0)
        {
        }
public:
    virtual ~OceanOb() {txDeleteDC(sprite);};
    virtual void change() = 0;
    virtual void change_sprite() = 0;
    virtual void draw() const = 0;
    virtual void collied(OceanOb* other) = 0;
    virtual bool isDead() {return (life == 0);}
    bool hasCollis(OceanOb* other) const;

};

bool OceanOb::hasCollis(OceanOb* other) const{
    if((fabs(xHB - other->xHB) < wHB) && (fabs(yHB - other->yHB) < hHB)){
        return true;
    }
    return false;
}

#endif // __OCEANOB_H__
