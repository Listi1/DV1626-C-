#include <iostream>

#include "StoreStock.hpp"
#include "EggPackage.hpp"
#include "Milk.hpp"
#include "Shovel.hpp"

/**
 * Hello! Please read the provided README.md before starting! :)
 * 
 * This main file is provided in order to test your solution on your own, and
 * will not be submitten in the assignmnent.
 * 
 * The code below utlize some of the core functionality of the classes. Feel
 * free to add your own code to test all the functions you implement.
 */

void PrintStore(const std::string& storeName, StoreStock& store)
{
    std::cout << "Products in " << storeName << ":\n";
    // "ranged-based for", possible because of StoreStock::begin() and StoreStock::end() :)
    for (auto product : store)
        std::cout << "  - " << product->GetProductDescription() << "\n";
    std::cout << std::endl;
}

void PrintStoreAdress(const std::string& storeName, StoreStock& store)
{
    std::cout << "Products in " << storeName << ":\n";
    // "ranged-based for", possible because of StoreStock::begin() and StoreStock::end() :)
    for (auto product : store)
        std::cout << "  - " << product << "\n";
    std::cout << std::endl;
}

int main()
{
    // Creating a store and filling it with products.
    StoreStock myStore;
    myStore.AddProduct(new EggPackage(35, Date(24, 12, 2022), 12));
    myStore.AddProduct(new EggPackage(22, Date(24, 12, 2022), 6));
    myStore.AddProduct(new Shovel(249.f, 30.f)); // <-- Cheapest shovel
    myStore.AddProduct(new Shovel(349.f, 75.f));
    myStore.AddProduct(new Milk(24, Date(27, 12, 2022), 500));
    myStore.AddProduct(new Milk(24, Date(27, 12, 2022), 500));
    myStore.AddProduct(new Milk(24, Date(27, 12, 2022), 500));
    
    PrintStore("myStore", myStore);

   Shovel* lowestPriceShovel = myStore.GetCheapest<Shovel>(); //getcheapest funktionen är inte deklarerad?
   std::cout << "Lowest shovel price: " << lowestPriceShovel->GetPrice() << "\n";

   Milk* lowestPriceMilk = myStore.GetCheapest<Milk>(); //getcheapest funktionen är inte deklarerad?
   std::cout << "Lowest Milk price: " << lowestPriceMilk->GetPrice() << "\n";
    
   int totalmilk = myStore.GetNumberOf<Milk>(); //getcheapest funktionen är inte deklarerad?
   std::cout << "total Milk in stock: " << totalmilk << "\n";

   std::cout << myStore.GetRequiredStorageVolume() << " storage volume" << std::endl;
   std::cout << myStore.GetTotalCost() << " total cost";
   
   {

       std::cout << std::endl << std::endl << std::endl << std::endl;
        /**
         * This is a nameless scope. The objects created in this scope will be
         * destroyed when the scope ends, as they will go "out-of-scope".
         * 
         * This way, you can easier test if object copies works as intended.
         */
    
        StoreStock yourStore(myStore);     //copy av originella storen
        PrintStore("yourStore (as a copy of myStore)", yourStore);

        //Remove some products
        EggPackage* pEggs = myStore.GetCheapest<EggPackage>();
        myStore.ReleaseProduct(pEggs);
        delete pEggs;

        Shovel* pShovel = myStore.GetCheapest<Shovel>();
        myStore.ReleaseProduct(pShovel);
        delete pShovel;

        PrintStore("yourStore (after removal)", yourStore);

        PrintStore("myStore (after removal in yourStore)", myStore);






        std::cout << std::endl << myStore.GetSize() << " size of vector" << std::endl; // eget test




        std::cout << std::endl << std::endl << std::endl << std::endl;

        PrintStoreAdress("myStore", myStore);
        std::cout << std::endl << std::endl << std::endl << std::endl;
        PrintStoreAdress("yourStore", yourStore);
    }
   
    {
        // Nameless scope

        StoreStock anotherStore; // Empty store
        PrintStore("anotherStore (should be empty)", anotherStore);

        anotherStore = myStore;
        PrintStore("anotherStore (after assigned myStore)", anotherStore);    //ska vara en kopia av mystore????????????????   equals operator i .cpp filen

        anotherStore = anotherStore;
        PrintStore("anotherStore (after assigned itself, should not have any changes)", anotherStore);

        std::cout << std::endl << std::endl << std::endl << std::endl;
        PrintStoreAdress("AnotherStore", anotherStore);
    }
    // Test more functions on your own, so they work as intended. :)
    return 0;
}