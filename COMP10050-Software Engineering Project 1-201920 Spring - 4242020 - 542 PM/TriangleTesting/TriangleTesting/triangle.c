//
// Created by Lili on 23/04/2020.
//

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "triangle.h"

char * checkTriangle(int a, int b, int c){
    if(a == 90 || b == 90 || c == 90)
        return "Right";

    if(a == 60 && b == 60 && c == 60)
        return "Equilateral";

    if(a == b || b == c || c == a)
        return "Isosceles";

    return "Scalene";

}
