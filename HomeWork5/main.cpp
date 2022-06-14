// Асортимент магазина: хлеб, белый хлеб, молоко, масло, сметана, мясо, апельсины, яблоки, сахар, макароны;
// Цены: хлеб = 0.9, белыйхлеб = 1.1, молоко = 1.3, масло = 3.6, сметана = 1.8, 
// мясо = 16, апельсины = 3, яблоки = 2.5, сахар = 2.05, макароны = 1.29 рублей;
// Действующие акции акции: 
//	- молочные продукты скидка 33%;
//	- мучные продукты 24%; 
//	- максимальная цена на продукт в корзине 50%
// 
// ****Пример: если у нас в корзине 5 буханок хлеба, пачка масла и две упаковки макарон, то продукт с максимальной 
// стоимостью - хлеб (5 * 0.9 > 1 * 3.6 > 2 * 1.29).
// 1. расчитать стоимость корзины без акции;
// 2. расчитать стоимость корзины с учетом акций;
// ***Акция к продукту может применяться только одна. 
// ***Акция с максимально стоимостью имеет приоритет по отношению к остальным (т.е.в примере выше хлеб попадает 
// под две акции : мучные продукты и максимальный продукт соответственно учитывается только скидка,
// на максимальный продукт из корзины)
// ***Если максимальных несколько, то пользователь должен выбрать к какому будет применена максимальная акция
// (Кстати если кто-то захочет пойти дальше, то тут можно выдавать рекомендацию пользователю какой лучше выбрать,
// чтобы в некоторых случаях сократить стоимость корзины.Но это опционально).
// ***Данные для ввода : пользователь вводит число продуктов в корзине и число	единиц(тоже зависит от продукта пачки, булки, кг и т.д.) для каждого продукта по отдельности.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "Header.h"

int main()
{
	std::vector<double> basket(10, 0);
	const double genDisc = 50, dayryDisc = 33, flourDisc = 24;// скидки
	short product = 0; // идекс продукта
	short indicator = -1; // показатель эффективности для выдачи рекомендаций
	double prodPrice = 0, basketPrice = 0, basketPriceDis = 0;// цены продукта, корзины, корзины со скидкой
	std::string  unit;

	using namespace MyFunctions;

	do
	{
		HelloMessage(basketPrice, basketPriceDis);
		Recomendation(indicator);

		std::cout << "\nPlease select the product you want to buy and press 'ENTER' or '0' to FINISH:\t";
		std::cin >> product;

		if (product > 0 && product <= 10) {
			
			switch (product) {
			case ShopAssortiment::Meat:
				prodPrice = 16;
				unit = "kg.";
				break;
			case ShopAssortiment::Apples:
				prodPrice = 2.5;
				unit = "kg.";
				break;
			case ShopAssortiment::Oranges:
				prodPrice = 3.0;
				unit = "kg.";
				break;
			case ShopAssortiment::Sugar:
				prodPrice = 2.05;
				unit = "kg.";
				break;
			case ShopAssortiment::Milk:
				prodPrice = 1.3;
				unit = "but.";
				break;
			case ShopAssortiment::Butter:
				prodPrice = 3.6;
				unit = "pack.";
				break;
			case ShopAssortiment::Sour_Cream:
				prodPrice = 1.8;
				unit = "pack.";
				break;
			case ShopAssortiment::Bread:
				prodPrice = 0.9;
				unit = "loaf.";
				break;
			case ShopAssortiment::White_Bread:
				prodPrice = 1.1;
				unit = "loaf.";
				break;
			case ShopAssortiment::Pasta:
				prodPrice = 1.29;
				unit = "pack.";
				break;
			}

			int amount;
			std::cout << "Pleas enter amount " << unit << " :\t";
			std::cin >> amount;

			// складываем продукты в корзину(каждый продукт имееет свое место в корзине)
			basket[static_cast<std::vector<double, std::allocator<double>>::size_type>(product) - 1] += prodPrice * amount;

			
			// расчет корзины (без учета скидки)
			basketPrice = BasketPrice(basket);

			// перегрузка ф-ии расчета корзины (с учетом скидки)
			basketPriceDis = BasketPrice(basket, genDisc, dayryDisc, flourDisc, indicator, FindeMax(basket));
		}
		else if (product == 0)
				continue;

		//опционально для повышения читабельности вывода результата выполнения
		system("cls");
	
	} while (product != 0);


	FinishShoping(basketPrice, basketPriceDis);
}