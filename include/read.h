/* 
 * @file                read.h
 * @description         Dosyadan sayıları oku header
 * @author              MAHMOUD ALABDOLLA
*/

#ifndef READ_HEADER
#define READ_HEADER

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

void read(std::vector<std::vector<int>>& arrays);

int getOccurs(const std::string& str, char chr);

#endif /* READ_HEADER */
