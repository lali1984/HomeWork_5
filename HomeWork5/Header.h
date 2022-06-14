#pragma once
namespace MyFunctions
{
	namespace ShopAssortiment
	{
		enum Other_Products : short
		{
			Meat = 1,
			Apples,
			Oranges,
			Sugar,
			Milk,
			Butter,
			Sour_Cream,
			Bread,
			White_Bread,
			Pasta
		};
	}

	//приветствие
	void HelloMessage(const double& basketPrice, const double& bp_disount);

	//цена корзины
	const double BasketPrice(std::vector<double>& basket);

	//цена корзины со скидкой
	const double BasketPrice(std::vector<double>& basket, const double& discount1, const double& discount2,
		const double& discount3, short& recomendation, const double max);

	//нахождение максимальной цены в корзине
	const double FindeMax(std::vector<double>& basket);

	//рекомендация
	void Recomendation(const short& recomend);

	//завершение покупок
	void FinishShoping(const double& basketPrice, const double& basketPriceDis);


}

