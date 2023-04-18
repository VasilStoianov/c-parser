#pragma once

#define TC_BLU  "\033[31;44m" 



void blue_background();



void blue_background(){
    system(TC_BLU);
}