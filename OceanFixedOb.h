//Romashka

#ifndef __FIXED_H__
#define __FIXED_H__

///камень//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Stone : public OceanOb{
public:
    Stone(HDC d0, HDC sprite0, double xD0, double yD0, double w0, double h0, double xScr0, double yScr0, double wScr0, double hScr0, COLORREF bcolor0):
        OceanOb(d0, sprite0, xD0, yD0, w0, h0, xScr0, yScr0, wScr0, hScr0, bcolor0)
        {
        }
    virtual void change() override{}
    virtual void change_sprite() override{}
    virtual void draw() const override{
        Win32::TransparentBlt(d, int(xD), int(yD), int(w), int(h), sprite, int(xScr), int(yScr), int(wScr), int(hScr), bcolor);
    }
    virtual void collied(OceanOb* other) override{;}
};
///коралл//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Corall : public OceanOb{
public:
    Corall(HDC d0, HDC sprite0, double xD0, double yD0, double w0, double h0, double xScr0, double yScr0, double wScr0, double hScr0, COLORREF bcolor0):
        OceanOb(d0, sprite0, xD0, yD0, w0, h0, xScr0, yScr0, wScr0, hScr0, bcolor0)
        {
        }
    virtual void change() override{}
    virtual void change_sprite() override{}
    virtual void draw() const override{
        Win32::TransparentBlt(d, int(xD), int(yD), int(w), int(h), sprite, int(xScr), int(yScr), int(wScr), int(hScr), bcolor);
    }
    virtual void collied(OceanOb* other) override{;}
};
///водоросль//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Seaweed : public OceanOb{
public:
    Seaweed(HDC d0, HDC sprite0, double xD0, double yD0, double w0, double h0, double xScr0, double yScr0, double wScr0, double hScr0, COLORREF bcolor0):
        OceanOb(d0, sprite0, xD0, yD0, w0, h0, xScr0, yScr0, wScr0, hScr0, bcolor0)
        {
        }
    virtual void change() override{}
    virtual void change_sprite() override{
        if(xScr >= OxScr + 3*wScr){
            xScr = OxScr;
            return;
        }
        xScr += wScr;
    }
    virtual void draw() const override{
        Win32::TransparentBlt(d, int(xD), int(yD), int(w), int(h), sprite, int(xScr), int(yScr), int(wScr), int(hScr), bcolor);
    }
    virtual void collied(OceanOb* other) override{;}
};

#endif // __FIXED_H__
