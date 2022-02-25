//Romashka

#ifndef __OCEANOB_H__
#define __OCEANOB_H__

class OceanOb{
protected:
    HDC d;                          /// <-  ƒескриптор приемного DC
    HDC sprite;                     /// <-  —прайты объекта
    double xD;                      /// <-  ’-координата верхнего левого угла изображени€-приемника
    double yD;                      /// <-  Y-координата верхнего левого угла изображени€-приемника
    double w;                       /// <-  Ўирина копируемого изображени€, неотрицательна€
    double h;                       /// <-  ¬ысота копируемого изображени€, неотрицательна€
    double xScr;                    /// <-  ’-координата верхнего левого угла изображени€-источника
    double yScr;                    /// <-  Y-координата верхнего левого угла изображени€-источника
    double wScr;                    /// <-  Ўирина источникового  пр€моугольника
    double hScr;                    /// <-  ¬ысота источникового  пр€моугольника
    double OxScr = xScr;            /// <-  ’ранит начальное значение переменной xScr
    double OyScr = yScr;            /// <-  ’ранит начальное значение переменной yScr
    COLORREF bcolor;                /// <-  ÷вет, который будет считатьс€ прозрачным
    OceanOb(HDC d0, HDC sprite0, double xD0, double yD0, double w0, double h0, double xScr0, double yScr0, double wScr0, double hScr0, COLORREF bcolor0):
        d(d0), sprite(sprite0), xD(xD0), yD(yD0), w(w0), h(h0), xScr(xScr0), yScr(yScr0), wScr(wScr0), hScr(hScr0), bcolor(bcolor0)
        {
        }
public:
    virtual ~OceanOb() {txDeleteDC(sprite);};
    virtual void change() = 0;
    virtual void change_sprite() = 0;
    virtual void draw() const = 0;

};

#endif // __OCEANOB_H__
