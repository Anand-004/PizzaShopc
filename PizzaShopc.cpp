#include <iostream>


std::string toppings[]={"Tomatoes","Mushroom","Chicken"};


class Pizza{
    public:
        std::string topping1;
        std::string topping2;
        std::string topping3;

        Pizza(std::string top1){
            this->topping1=top1;
        }
        Pizza(std::string top1,std::string top2){
            this->topping1=top1;
            this->topping2=top2;
        }
        Pizza(std::string top1,std::string top2,std::string top3){
            this->topping1=top1;
            this->topping2=top2;
            this->topping3=top3;
        }
};

void placeOrder();
void showmenu();
void Greetings(int a);
void showOrder(int topno,int topbowl[]);
void serveOrder(std::string top1);
void serveOrder(std::string top1,std::string top2 );
void serveOrder(std::string top1,std::string top2,std::string top3);



int main()
    {
        char choice; 
        std::system("clear");
        std::cout<<"\n\n |........WELCOME TO PIZZA Shop..........|\n\n";
        std::cout<<"\n What would you like to do sir ... \n";
        std::cout<<"\n1.Order  2.Menu \n   3.leave";
        std::cout<<"\n\nEnter your option ->YOU : ";
        std::cin>>choice;

        switch(choice){
            case '1':
                placeOrder();
                break;
            case '2':
                showmenu();
                break;
            case '3':
                Greetings(1);
                break;
        }

    } 

void showmenu()
    {   

        std::cout<<"\n-----MEnu-----\n";
        for(int i=0;i<sizeof(toppings)/sizeof(toppings[0]);i++)
            {
                std::cout<<" "<<i+1<<". "<<toppings[i]<<"\n";
            }
    }
void placeOrder()
    {

                int noofToppings;
                std::cout<<"\nPlease enter no of Toppings you want(1 or 2 or 3) :";
                std::cin>>noofToppings;
                int* toppingsBowl=new int[noofToppings];
                showmenu();
                for(int i=0;i<noofToppings;i++){
                    std::cout<<"\nWhat is Your "<<i+1<<" topping(1 or 2 or 3) :";
                    std::cin>>toppingsBowl[i];
                    
                }
                showOrder(noofToppings,toppingsBowl);
                delete[] toppingsBowl;
    }
void Greetings(int a)   
    {
        switch(a){
            case 1:
                std::cout<<"\n\n\t\t!!!------Thank You ! Please Visit Again ------!!!\n\n"<<std::endl;
        }

    }

void showOrder(int topno,int topbowl[])
    {
        switch(topno){
            case 1:
                {
                Pizza pizza1(toppings[topbowl[0]-1]);
                serveOrder(pizza1.topping1);
                break;
                }
            case 2:
                {
                Pizza pizza1(toppings[topbowl[0]-1],toppings[topbowl[1]-1]);
                serveOrder(pizza1.topping1,pizza1.topping2);
                break;
                }
            case 3:
                {
                Pizza pizza1(toppings[topbowl[0]-1],toppings[topbowl[1]-1],toppings[topbowl[2]-1]);
                serveOrder(pizza1.topping1,pizza1.topping2,pizza1.topping3);
                break;
                }
        }
    }
void serveOrder(std::string top1)
    {
        std::cout<<"\n\n !...Your "<<top1<<" Pizza is Ready ...!";
    }
void serveOrder(std::string top1,std::string top2)
    {
        if(top1==top2)
            {
                std::cout<<"\n\n !...Your Double "<<top1<<" Pizza is Ready ...!";
            }
        else
            {
                std::cout<<"\n\n !...Your "<<top1<<" "<<top2<<" Pizza is Ready ...!";
            }
    }
void serveOrder(std::string top1,std::string top2,std::string top3)
    {
        if(top1==top2&&top2==top3)
            {
                std::cout<<"\n\n !...Your Triple  "<<top1<<" Pizza is Ready ...!";
            }
        else if(top1==top3)
            {

                std::cout<<"\n\n !...Your Double "<<top1<<" "<<top2<<" Pizza is Ready ...!";
            }
        else if(top2==top3)
            {

                std::cout<<"\n\n !...Your Double "<<top2<<" "<<top1<<" Pizza is Ready ...!";
            }
        else if(top1==top2)
            {

                std::cout<<"\n\n !...Your Double "<<top1<<" "<<top3<<" Pizza is Ready ...!";
            }
        else
            {
                std::cout<<"\n\n!...Your "<<top1<<" "<<top2<<" "<<top3<<" Pizza is REady ...!";
            }
    }