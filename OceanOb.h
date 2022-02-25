//Romashka

#ifndef __OCEANOB_H__
#define __OCEANOB_H__

class OceanOb{
protected:
    HDC d;                          /// <-  ���������� ��������� DC
    HDC sprite;                     /// <-  ������� �������
    double xD;                      /// <-  �-���������� �������� ������ ���� �����������-���������
    double yD;                      /// <-  Y-���������� �������� ������ ���� �����������-���������
    double w;                       /// <-  ������ ����������� �����������, ���������������
    double h;                       /// <-  ������ ����������� �����������, ���������������
    double xScr;                    /// <-  �-���������� �������� ������ ���� �����������-���������
    double yScr;                    /// <-  Y-���������� �������� ������ ���� �����������-���������
    double wScr;                    /// <-  ������ �������������  ��������������
    double hScr;                    /// <-  ������ �������������  ��������������
    double OxScr = xScr;            /// <-  ������ ��������� �������� ���������� xScr
    double OyScr = yScr;            /// <-  ������ ��������� �������� ���������� yScr
    COLORREF bcolor;                /// <-  ����, ������� ����� ��������� ����������
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
