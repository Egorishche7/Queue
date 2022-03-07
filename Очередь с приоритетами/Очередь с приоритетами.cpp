#include <iostream>
#include "Queue.h"
#include "QueueItem.h"

using namespace std;

int Menu(); //меню
Queue CreateExample(); //создаёт очередь для примера

int main()
{
	setlocale(LC_ALL, "russian");

	while (true)
	{
		switch (Menu())
		{
		case 1:
		{
			cout << "\nКонструктор без параметров создаёт пустую очередь q0.\n";
			Queue q0;
			cout << "Создадим очередь q1:\n";
			Queue q1 = CreateExample();
			cout << q1;
			cout << "Конструктор копирования: создадим очередь q2(q1):\n";
			Queue q2(q1);
			cout << q2;
			cout << "Конструктор перемещения: создадим очередь q3:\n";
			Queue q3 = CreateExample();
			cout << q3;
			break;
		}
		case 2:
		{
			cout << "\nСоздадим очередь q1:\n";
			Queue q1 = CreateExample();
			cout << q1;
			cout << "Копирующий оператор присваивания: создадим очередь q2=q1:\n";
			Queue q2 = q1;
			cout << q2;
			cout << "Перемещающий оператор присваивания: создадим очередь q3:\n";
			Queue q3;
			q3 = CreateExample();
			cout << q3;
			break;
		}
		case 3:
		{
			cout << "\nСоздадим очередь q1:\n";
			Queue q1 = CreateExample();
			cout << q1;
			cout << "Общее количество элементов в очереди: " << q1.getSize() << "\n";
			break;
		}
		case 4:
		{
			cout << "\nСоздадим очередь q1:\n";
			Queue q1 = CreateExample();
			cout << q1;
			cout << "Число элементов очереди\n"
				<< "с высоким (3) приоритетом: " << q1.getCount(3) << "\n"
				<< "со средним (2) приоритетом: " << q1.getCount(2) << "\n"
				<< "с низким (1) приоритетом: " << q1.getCount(1) << "\n";
			break;
		}
		case 5:
		{
			cout << "\nС помощью конструктора без параметров создадим очередь q0, а также очередь q1:\n";
			Queue q0, q1 = CreateExample();
			cout << q1;
			if (q0.isEmpty())
				cout << "Очередь q0 пуста.\n";
			else
				cout << "Очередь q0 не пуста.\n";
			if (q1.isEmpty())
				cout << "Очередь q1 пуста.\n";
			else
				cout << "Очередь q1 не пуста.\n";
			break;
		}
		case 6:
		{
			cout << "\nСоздадим очередь q1:\n";
			Queue q1 = CreateExample();
			cout << q1;
			cout << "Добавим в неё элементы со следующими значениями и приоритетами:\n"
				<< "77, средний (2)\n"
				<< "55, высокий (3)\n"
				<< "66, низкий (1)\n";
			q1.push(77, 2);
			q1.push(55, 3);
			q1.push(66, 1);
			cout << "Теперь очередь выглядит так:\n";
			cout << q1;
			break;
		}
		case 7:
		{
			try
			{
				cout << "\nСоздадим очередь q1:\n";
				Queue q1 = CreateExample();
				cout << q1;
				cout << "Удалим 2 элемента из очереди.\n";
				q1.pop();
				q1.pop();
				cout << "Теперь очередь выглядит так:\n";
				cout << q1;
				cout << "При попытке удалить элемент из пустой очереди q0 происходит выброс исключения:\n";
				Queue q0;
				q0.pop();
			}
			catch (const exception& exception)
			{
				cout << exception.what();
			}
			break;
		}
		case 8:
		{
			try
			{
				cout << "\nСоздадим очередь q1:\n";
				Queue q1 = CreateExample();
				cout << q1;
				cout << "Информация об элементе, стоящего в голове очереди:\n" << q1.getHeadInfo();
				cout << "\nЕсли очередь пуста, то происходит выброс исключения:\n";
				Queue q0;
				q0.getHeadInfo();
			}
			catch (const exception& exception)
			{
				cout << exception.what();
			}
			break;
		}
		case 0:
			return 0;
		}
		cout << endl;
	}
}

int Menu()
{
	int choose;

	do
	{
		cout << "Выберите операцию:\n";
		cout << "1 - пример работы конструкторов без параметров, копирования и перемещения\n";
		cout << "2 - пример работы копирующего и перемещающего операторов присваивания\n";
		cout << "3 - определение общего количества элементов в очереди\n";
		cout << "4 - определение числа элементов в очереди, имеющих конкретный приоритет\n";
		cout << "5 - проверка на пустоту очереди\n";
		cout << "6 - вставка элемента со значением и приоритетом\n";
		cout << "7 - удаление элемента из очереди\n";
		cout << "8 - вывод информации о приоритете и значении элемента, стоящего в голове очереди\n";
		cout << "0 - выход\n";
		cin >> choose;
	} while (choose > 8 || choose < 0);

	return choose;
}

Queue CreateExample()
{
	Queue queue;

	queue.push(11, 2);
	queue.push(22, 1);
	queue.push(33, 3);
	queue.push(44, 1);

	return queue;
}