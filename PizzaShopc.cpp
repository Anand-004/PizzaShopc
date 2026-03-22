#include <iostream>
#include <thread>
#include<chrono>


std::string toppings[]={"Tomato","Mushroom","Chicken","pineapple","chocolate"};


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
void exitfunc();
void orderStatus();


int main()
    {
        char choice; 
        do 
            {
                std::system("clear");
                std::cout<<"\n\n |........WELCOME TO PIZZA Shop..........|\n\n";
                std::cout<<"\n What would you like to do sir ... \n";
                std::cout<<"\n1.Order  2.Menu \n   3.leave";
                std::cout<<"\n\nEnter your option ->YOU : ";
                std::cin>>choice;

                switch(choice){
                    case '1':
                        std::system("clear");
                        placeOrder();
                        exitfunc();
                        break;
                    case '2':
                        std::system("clear");
                        showmenu();
                        exitfunc();
                        break;
                    case '3':
                        std::system("clear");
                        Greetings(1);
                        exitfunc();
                        break;
                    default:
                        std::system("clear");
                        std::cout<<"\n\n...Please Select a Valid service ....!\n\n";
                        exitfunc();
                }
            }while(choice!='3');

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
                std::cout<<"\n\n        |..........Pizza Counter............|\n\n";
                std::cout<<"\nPlease enter no of Toppings you want(1 or 2 or 3) :";
                std::cin>>noofToppings;
                int* toppingsBowl=new int[noofToppings];
                showmenu();
                for(int i=0;i<noofToppings;i++){
                    std::cout<<"\nWhat is Your "<<i+1<<" topping(1 or 2 or 3) :";
                    std::cin>>toppingsBowl[i];
                    
                }
                orderStatus();
                // std::this_thread::sleep_for(std::chrono::seconds(2));
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

        std::system("clear");
        std::cout<<"\n\n        |..........Pizza Counter............|\n\n";
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
            default:
                std::cout<<"\n\n!!-----Sorry sir pizza with "<<topno<<" toppings cannot be provided\n  We are SORRY for disappointing you sir....!!\n\n";
                break;
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

void exitfunc()
    {
        char exitchar;
        do{
        std::cout<<"\n\nPress x to exit :";
        std::cin>>exitchar;
        }while(exitchar!='x');
    }
void orderStatus()
    {
        std::system("clear");
        std::cout<<"\n\nYour order has been placed Successfully...\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout<<"\nMaking Fresh Dough\n.\n.\n.";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout<<"\nPreparing Special Toppings  \n.\n.\n.";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout<<"\nBaking Fresh pizza in oven  \n.\n.\n.";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout<<"\nPacking Your PIZZA  !\n.\n.\n.";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout<<"\nShow your hand ! \n\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));


        // std::system("clear");
    }