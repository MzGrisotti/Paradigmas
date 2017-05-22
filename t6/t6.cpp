#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <time.h>

class Biscoito{
    protected:
       float valor;
       float area;
       std::string shape;
    public:
        float getValor(){
            return area;
        }
        float getArea(){
            return area;
        }
        std::string getShape(){
            return shape;
        }
        //virtual double calculaArea() = 0;

        void Atendente(){
        if(this->area <= 6)
            this->valor  = 0.3;
        else if (this->area <= 12)
            this->valor  = 0.8;
        else
            this->valor  = 1.3;
        }
};

class Quadrado : public Biscoito{
    private:
        float lado;
    public:
        float CalcArea(){
            return area = lado*lado;
        }
        Quadrado(float lado){
          this->shape = "QUADRADO";
          this->lado = lado;
          CalcArea();
          Atendente();
        }
};
class Circulo : public Biscoito{
    private:
        float raio;
    public:
        float CalcArea(){
            return area = ((raio*raio)*3.14);
        }
        Circulo(float raio){
          this->shape = "CIRCULO";
          this->raio = raio;
          CalcArea();
          Atendente();
        }
};
class Triangulo : public Biscoito{
    private:
        float base;
    public:
        float CalcArea(){
            return area = (((base*base)*1.73)/4);
        }
        Triangulo(float base){
          this->shape = "TRIANGULO";
          this->base = base;
          CalcArea();
          Atendente();
        }
};

void FazerBiscoitos(std::vector<Biscoito*>& biscoitos){
    int tipo = rand()%3;
    float tamanho;
    do{
        tamanho = rand()%1000;
        tamanho /= 100;
    }while(tamanho < 2 || tamanho > 4);
    if(tipo == 0){
       Quadrado* quad =  new Quadrado(tamanho);
       biscoitos.push_back(quad);
    }
    if(tipo == 1){
       Circulo* circ =  new Circulo(tamanho);
       biscoitos.push_back(circ);
    }
    if(tipo == 2){
       Triangulo* tri =  new Triangulo(tamanho);
       biscoitos.push_back(tri);
    }
}

bool Maior(Biscoito* biscoito1, Biscoito* biscoito2){
    return biscoito1->getArea() > biscoito2->getArea();
}

void ContagemBiscoitos(std::vector<Biscoito*>& biscoitos){
    std::cout << "Biscoitos Ordenados por Area" << std::endl;
    for (auto it = biscoitos.begin(); it != biscoitos.end(); it++){
        std::cout << "Tipo -> " << (*it)->getShape();
        if((*it)->getArea() <= 6)
            std::cout << " || Tamanho -> Pequeno";
        else if ((*it)->getArea() <= 12)
            std::cout << " || Tamanho -> Medio";
        else
            std::cout << " || Tamanho -> Grande";
        std::cout.precision(4);
        std::cout << " || Area -> " <<(*it)->getArea() << std::endl;
    }
}

void ColocarBiscoitosNaSacola(std::vector<Biscoito*>& biscoitos){

    int menor, medio, maior, total;
    total = menor = medio = maior = 0;

    for (auto it = biscoitos.begin(); it != biscoitos.end(); it++){
        if((*it)->getArea() <= 6)
            menor++;
        else if ((*it)->getArea() <= 12)
            medio++;
        else
            maior++;
        total++;
    }
    std::cout << std::endl << "Biscoitos Pequenos " << menor << " Total: RS" << menor * 0.3 << std::endl;
    std::cout << "Biscoitos Medios " << medio << " Total: R$" << medio * 0.8 << std::endl;
    std::cout << "Biscoitos Grandes " << maior << " Total: RS" << maior * 1.3 << std::endl;
    std::cout << "Total de Biscoitos " << total << " Total: RS" << menor * 2.4 << std::endl;
}

int main(){

    srand (time(NULL));
    std::vector<Biscoito*> biscoitos;
    int n, i;
    std::cout << "Quantos biscoitos seram comprados" << std::endl;
    std::cin >> n;
    for(i = 0; i < n; i++)
        FazerBiscoitos(biscoitos);
    std::sort(biscoitos.begin(), biscoitos.end(), Maior);
    ContagemBiscoitos(biscoitos);
    ColocarBiscoitosNaSacola(biscoitos);
}
