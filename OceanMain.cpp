#include "TXLib.h"
#include <vector>
#include "OceanOb.h"
#include "OceanMovingOb.h"
#include "OceanFixedOb.h"
#include "Ocean.h"
#include "OceanFunctions.h"

//const int scr_w = 1500, scr_h = 800;

/*TYPES
1 - STONE    2 - CORALL    3 - FISH    4 - HUNTER*/
int main(){
    srand(time(0));
    txCreateWindow(scr_w, scr_h);
    Ocean ocean;
    init(ocean);
    HDC fon = txLoadImage("OceanBottom.bmp");
    if(!fon){
        txMessageBox("Фоновое изображение отсутствует!", "Ошибка",  0);
        return 1;
    }
    txBegin();
    while(!GetAsyncKeyState(VK_ESCAPE)){
        Win32::TransparentBlt(txDC(), 0, 0, scr_w, scr_h, fon, 0, 0, 1500, 800, RGB(255, 255, 255));
        ocean.update();
        txSleep(70);
    }
    txDeleteDC(fon);
    txEnd();
    return 0;
}
