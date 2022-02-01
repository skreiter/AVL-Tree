/*
 Sage Kreiter
 PA3
 */
 
//Instert: O(n) because the larger the data size it linearly grows.
//Printinorder: O(n) Because it also grows linearly as data increases
//Findmax: O(n) same as the others.
 
 
#include <iostream>
#include <fstream>
#include "AVLTree.hpp"
#include "cancerData.hpp"
 
int main()
{
    AVLTree<CancerData>* MF;
    AVLTree<CancerData>* M;
    AVLTree<CancerData>* F;
    
    std::ifstream infile;
    infile.open("bothcancerdata2018.csv");
    std::string country;
    std::string tempRate;
    float rate;
    getline(infile, country, ',');
    getline(infile, tempRate, '\n');
    rate = std::stof(tempRate);
    
    CancerData temp(country, rate);
 
    MF->insertHelp(temp);
    while(!infile.eof())
    {
        getline(infile, country, ',');
        getline(infile, tempRate, '\n');
        rate = std::stof(tempRate);
        
        MF->insertHelp(temp);
    }
    infile.close();
    
     infile.open("womencancerdata2018.csv");
     getline(infile, country, ',');
     getline(infile, tempRate, '\n');
     rate = std::stof(tempRate);
     
     while(!infile.eof())
     {
         getline(infile, country, ',');
         getline(infile, tempRate, '\n');
         rate = std::stof(tempRate);
         
         F->insertHelp(temp);
     }
    infile.close();
    
    infile.open("mencancerdata2018.csv");
    getline(infile, country, ',');
    getline(infile, tempRate, '\n');
    rate = std::stof(tempRate);
    
    while(!infile.eof())
    {
        getline(infile, country, ',');
        getline(infile, tempRate, '\n');
        rate = std::stof(tempRate);
        
        M->insertHelp(temp);
    }
    infile.close();
    std::string label = "Both";
    MF->printInOrder(MF->get_root(), label);
    
    
    label = "Men";
    M->printInOrder(M->get_root(), label);
    
    label = "Women";
    F->printInOrder(F->get_root(), label);
    
    
    
    
    return 0;