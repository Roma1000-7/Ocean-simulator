//Romashka

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

/*TYPES
1 - STONE    2 - CORALL    3 - FISH    4 - HUNTER*/

void init(Ocean &ocean);
HDC rand_fish(HDC fish, HDC r_fish, HDC b_fish);
int rand_color();
int rand_corall();

void init(Ocean &ocean){
//////инициализируем картинки///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int p = 0; // 0 - картинка есть, 1 - картинка отсутствует
    HDC stone = txLoadImage("Stone.bmp");
    if(!stone){
        txMessageBox("Изображение камня отсутствует!", "Ошибка",  0);
        p = 1;
    }
    HDC corall = txLoadImage("Corall.bmp");
    if(!corall){
        txMessageBox("Изображение коралла отсутствует!", "Ошибка",  0);
        p = 1;
    }
    HDC seaweed = txLoadImage("Seaweed.bmp");
    if(!seaweed){
        txMessageBox("Изображение водорослей отсутствует!", "Ошибка",  0);
        p = 1;
    }
    HDC fish = txLoadImage("Fish.bmp");
    if(!fish){
        txMessageBox("Изображение fish отсутствует!", "Ошибка",  0);
        p = 1;
    }
    HDC r_fish = txLoadImage("RoundFish.bmp");
    if(!r_fish){
        txMessageBox("Изображение r_fish отсутствует!", "Ошибка",  0);
        p = 1;
    }
    HDC b_fish = txLoadImage("Fish2.bmp");
    if(!b_fish){
        txMessageBox("Изображение b_fish отсутствует!", "Ошибка",  0);
        p = 1;
    }
    HDC shark = txLoadImage("Shark.bmp");
    if(!shark){
        txMessageBox("Изображение акулы отсутствует!", "Ошибка",  0);
        p = 1;
    }
    if(p == 1){
        txDeleteDC(stone);
        txDeleteDC(corall);
        txDeleteDC(seaweed);
        txDeleteDC(fish);
        txDeleteDC(r_fish);
        txDeleteDC(b_fish);
        txDeleteDC(shark);
        exit(0);
    }
//////Добавляем объекты///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    double scale; //    Ширина/высота изображения на экране
    const int num_of_stones = 6;
    for(int i = 0; i < num_of_stones; i++){ ///камни/////////////////////////////////////////////
        scale = double(100 + rand()%200);
        ocean.add_object(1, RGB(237, 28, 36), txDC(), stone, double(scr_w / num_of_stones * i + rand()%200), 775 - scale / 3, scale, scale / 3, 0, 0, 169, 52);
    }
    const int num_of_fishes = 15;
    for(int i = 0; i < num_of_fishes; i++){ ///рыбы/////////////////////////////////////////////
        scale = double(48 + rand()%70);
        ocean.add_object(4, RGB(237, 28, 36), txDC(), rand_fish(fish, r_fish, b_fish), double(rand()%scr_w), double(rand()%685), scale, scale, rand_color(), 0, 48, 48, double(5 + rand()%10));
    }
    const int num_of_seaweed = 5;
    for(int i = 0; i < num_of_seaweed; i++){ ///водоросли/////////////////////////////////////////////
        scale = double(144 + rand()%288);
        ocean.add_object(3, RGB(237, 28, 36), txDC(), seaweed, double(scr_w / num_of_seaweed * i + rand()%150), 773 - scale, scale, scale, 0, 0, 144, 144);
    }
    const int num_of_corall = 8;
    for(int i = 0; i < num_of_corall; i++){ ///кораллы/////////////////////////////////////////////
        scale = double(96 + rand()%144);
        ocean.add_object(2, RGB(255, 255, 255), txDC(), corall, double(scr_w / num_of_corall * i + rand()%100), 773 - scale, scale, scale, rand_corall(), 0, 144, 144);
    }
    ocean.add_object(5, RGB(237, 28, 36), txDC(), shark, double(rand()%scr_w), double(rand()%scr_h), 380, 150, 0, 0, 152, 60, 7);  ///акула/////////////////////////////////////////////
}

HDC rand_fish(HDC fish, HDC r_fish, HDC b_fish){  //функция рандомного выбора рыбы
    int chislo;
    chislo = rand()%3;
    if(chislo == 1){
        return fish;
    }
    else if(chislo == 2){
        return r_fish;
    }
    else{
        return b_fish;
    }
}

int rand_color(){ //функция рандомного выбора цвета рыбы
    int chislo;
    chislo = rand()%4;
    if(chislo == 1)
        return 0;
    else if(chislo == 2)
        return 144;
    else if(chislo == 3)
        return 288;
    else
        return 432;
}

int rand_corall(){
    int chislo;
    chislo = rand()%2;
    if(chislo == 1)
        return 0;
    else
        return 144;
}

#endif // __FUNCTIONS_H__
