#define __USE_MINGW_ANSI_STDIO 0
#include <string>
#include <sstream>
#include <stdexcept>
#include <FL/fl_ask.H>
#include "window.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

class Sorteio : public UserInterface {
    private:
        int start = 0;
        int ganhador = 0;
        std::vector<int> participantes;
    public:
      Sorteio() {
        btnSorteio->callback((Fl_Callback*) cbSorteio, (void*)(this));
        btnReset->callback((Fl_Callback*) cbReset, (void*)(this));
      }
      void show() {
        // Mostra janela
        w->show();
      }

    void organizar(int num){
        for(auto i = 1; i <= num; i++){
            this->participantes.push_back(i);
        }
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(this->participantes.begin(), this->participantes.end(), std::default_random_engine(seed));
    }
    // Funcao callback chamada quando pressionado botao 'Sortear'
    static void cbSorteio(Fl_Widget* btn, void* userdata) {
        Sorteio* gui = static_cast<Sorteio*>(userdata);
        try {
            int a = std::stoi(gui->inputValue1->value());
            if(a <= 0)
                 fl_alert("Digite um numero positivo");
            else{
                if(gui->start == 0 && gui->participantes.empty()){
                    gui->start = 1;
                    gui->organizar(a);
                }
                if(gui->participantes.empty()){
                    gui->start = 0;
                    gui->ganhador = 0;
                    fl_alert("Foram Todos Sorteados");
                    gui->inputValue1->value("");
                    gui->boxResult->label("");
                    gui->boxGanhador->label("");
                    gui->participantes.clear();
                }else{
                    gui->ganhador++;
                    int result = gui->participantes.back();
                    gui->participantes.pop_back();
                    gui->boxResult->copy_label(std::to_string(result).c_str());
                    std::string s = std::to_string(gui->ganhador).c_str();
                    s = s + std::string("� Ganhador");
                    gui->boxGanhador->copy_label(s.c_str());
                }

            }
        } catch (std::invalid_argument&){
            fl_alert("Digite um numero");
        }
    }

      // Funcao callback chamada quando pressionado botao 'Reset'
      static void cbReset(Fl_Widget* btn, void* userdata) {
        Sorteio* gui = static_cast<Sorteio*>(userdata);
        gui->inputValue1->value("");
        gui->boxResult->label("");
        gui->boxGanhador->label("");
        gui->participantes.clear();
        gui->start = 0;
        gui->ganhador = 0;
      }
};



int main() {
  Sorteio gui;
  gui.show();
  return Fl::run();
}


