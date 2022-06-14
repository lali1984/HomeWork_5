#include <iostream>
#include <vector>
#include <string>

namespace MyFunctions {
	// Приветствие
	void HelloMessage(const double& basketPrice, const double& bp_disount)
	{
		std::cout << "-----------------------------------------------------------------------------\n";
		std::cout << "|     Other products     |       Dayry            |      Flour products     |\n";
		std::cout << "|       discount 0%      |    discount 33%        |       discount 24%      |\n";
		std::cout << "-----------------------------------------------------------------------------\n";
		std::cout << "|product           |price|product           |price|product            |price|\n";
		std::cout << "-----------------------------------------------------------------------------\n";
		std::cout << "|1 -> Meat         |16.0 |5 -> Milk         | 1.3 |8  -> Bread        | 0.9 |\n";
		std::cout << "|2 -> Apples       | 2.5 |6 -> Butter       | 3.6 |9  -> White Bread  | 1.1 |\n";
		std::cout << "|3 -> Oranges      | 3.0 |7 -> Sour Cream   | 1.8 |10 -> Pasta        |1.29 |\n";
		std::cout << "|4 -> Sugar        |2.05 |******************|*****|0  -> **FINISH SHOPING** |\n";
		std::cout << "-----------------------------------------------------------------------------\n";
		std::cout << "Additional 50% discount on the product from the basket with the maximum price.\n";
		std::cout << "-----------------------------------------------------------------------------\n";
		std::cout << "Basket PRICE  = " << basketPrice << " rub.";
		std::cout << "\tBasket PRICE WITH DISCOUNT = " << bp_disount << " rub.\n";
		std::cout << "-----------------------------------------------------------------------------\n";
	}

	// выдача рекомендации для применения выгодной скидки
	void Recomendation(const short& recomend)
	{
		switch (recomend) {
		case -1:
			std::cout << "|RECOMENDATION:                                                             |\n";
			std::cout << "|To take advantage of the discounts we offer, you must have the highest     |\n";
			std::cout << "|priced product in your cart from the <OTHER PRODUCTS> or <FLOUR PRODUCTS>  |\n";
			std::cout << "|category.                                                                  |\n";
			std::cout << "-----------------------------------------------------------------------------\n";
			break;

		case 0:
			std::cout << "|RECOMENDATION:                                                             |\n";
			std::cout << "|To take advantage of the discounts we offer, you must have the highest     |\n";
			std::cout << "|priced product in your cart from the <OTHER PRODUCTS> category.            |\n";
			std::cout << "-----------------------------------------------------------------------------\n";
			break;
		case 1:
			std::cout << "|RECOMENDATION:                                                             |\n";
			std::cout << "|Good discount!                                                             |\n";
			std::cout << "-----------------------------------------------------------------------------\n";
			break;
		default:
			break;
		}
	}

	// цена корзины без учета скидок
	const double BasketPrice(std::vector<double>& basket)
	{
		double basketPrice = 0;
		for (const double& prod : basket) {
			basketPrice += prod;
		}

		return basketPrice;
	}

	// максимальная цена в карзине
	const double FindeMax(std::vector<double>& basket)
	{
		double maxPrice = 0;

		for (const double& prod : basket) {
			if (prod > maxPrice)
				maxPrice = prod;
		}

		return maxPrice;
	}

	// цена корзины с учетом всех скидок
	const double BasketPrice(std::vector<double>& basket, const double& discount1,
		const double& discount2, const double& discount3, short& recomendation, const double max)
	{
		double basketPrice = 0;
		// 1-4 other product
		for (auto it = basket.begin(); it < (basket.begin() + 4); ++it) {
			if (*it == max) {
				basketPrice += (*it - ((*it / 100) * discount1));
				recomendation = 1;
			}

			else
				basketPrice += *it;
		}

		// 5-7 dayry product (молочная продукция)
		for (auto it = (basket.begin() + 4); it < (basket.begin() + 7); ++it) {
			if (*it == max) {
				basketPrice += (*it - ((*it / 100) * discount1));
				recomendation = 0;
			}
			else
				basketPrice += (*it - ((*it / 100) * discount2));
		}

		// 8-10 flour product (мучные продукты)
		for (auto it = (basket.begin() + 7); it < (basket.begin() + 10); ++it) {
			if (*it == max) {
				basketPrice += (*it - ((*it / 100) * discount1));
				recomendation = -1;
			}
			else
				basketPrice += (*it - ((*it / 100) * discount3));
		}

		return basketPrice;
	}

	//завершение покупок
	void FinishShoping(const double& basketPrice, const double& basketPriceDis)
	{
		std::cout << "\nPrice your basket is: " << basketPrice << " rub.\n";

		std::cout << "Your discount is: " << basketPrice - basketPriceDis << " rub. ( "
			<< ((basketPrice - basketPriceDis) * 100) / basketPrice << "% )\n";

		std::cout << "Price your bascet with discount: " << basketPriceDis << " rub.\n";
	}
}


