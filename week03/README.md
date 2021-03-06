# Практикум   седмица 3

### Какво научихме предния път?

  - Типове данни
  - Променливи и константи
  - Основни оператори
  - Преобразуване на типове данни
  
### Какво ще научим днес?
  - Блок {}, видимост на данни
  - if конструкции
  - Конструкция ?:
  - switch конструкция

### Блок {}, видимост на данни
Блок в програма ще наричаме парчета код които са заградени с { <код> }. Конвенцията за писане изисква новите редове след отварящата скоба - { да започват навътре от предходния ред (в общия случай с една табулация място).  
```c++
{
	std::cout << "One tab inside" << std::endl;
}
```

Видимост на променливите, наричаме частта от програмата където можем да достъпим дадените променливи. Видимостта, спрямо това как я разглеждаме, можем да я разделим в 3 категории:
 - Вътре във функция или блок, се нарича локална променлива
 - В дефиниция на функция - нарича се формален параметър (ще го разгледаме подробно скоро) 
 - Вън от всички функции, тогава се нарича глобална

Локални - те са видими само в конкретния блок в който са декларирани и във всеки негов подблок;

Глобални - те са дефинирани извън всички функции, обикновено най - отгоре на програмата. Те могат да бъдат достъпени от всички функции.
```c++
#include<iostream>

// Глобални променливи
bool check;

int main()
{
	// Локални променливи
	int age = 19, fn = 56789;

	std::cout << age;

	{
		std::cout << " " << fn;
	}
	
	check = true;
	return 0;
}
```

### if конструкции
Възможността да контролирате потокът на програмата, да взимате решение кога дадени фрагменти ще се изпълнят, е важнен фрагмент за всеки програмист. Такъв инструмент е условният оператор, той проверява дали дадено условие е изпълнено и спрямо този резултат изпълнява зададеното от програмистта.
Условният оператор има две основни конструкции: кратка и пълна.

#### Кратка форма на if
Синтаксис:
```c++
if (<булев_израз>)
{
	// ...
	// блок от операции, които ще бъдат изпълнени
	// ...
}
```

Семантика: Проверява се резултатът от <булев_израз>, ако върнатата стойност е true тогава се изпълнява блокът от операции, ако върнатият резултат е false - няма да се изпълни нищо. 

```c++
#include <iostream>

int main()
{
	const int ALLOW_AGE = 18;
	int age = 16;
	
	if (age < ALLOW_AGE) 
		std::cout << "Drink denied" << std::endl;

	return 0;
}
```
Блок-схема:
![alt tag](https://github.com/GeorgiMinkov/FMI_IS_UP_1_2016/blob/master/week03/image/Diagram_if.png)

#### Пълна форма на if
Синтаксис:
```c++
if (<булев_израз>)
{
	// ...
	// блок от операции, които ще бъдат изпълнени
	// ...
}
else
{
	// ...
	// блок от операции, които ще бъдат изпълнени 
}
```

Семантика: Проверява се резултатът от <булев_израз>, ако върнатата стойност е true тогава се изпълнява блокът от операции, ако върнатият резултат е false - блокът от операции след else. 

```c++
#include<iostream>

int main()
{
	const int ALLOW_AGE = 18;
	int age = 16;
	
	if (age < ALLOW_AGE)
	{ 
		std::cout << "Drink denied" << std::endl;
	}	
	else
	{
		std::cout << "Drink permitted" << std::endl;
	} 

	return 0;
}
```
Блок-схема

![alt tag](https://github.com/GeorgiMinkov/FMI_IS_UP_1_2016/blob/master/week03/image/Diagram_if_else.png)

#### Вложена форма
```c++
#include<iostream>

int main()
{
	int number = 15;
	
	if (number % 3 == 0)
	{
		if (!(number % 5))
			std::cout << "Divided by 3 and 5" << std::endl;
		else
			std::cout << "Divided by 3 but not by 5" << std::endl;
	}
	
	return 0;
}
```
### Други форми - if-else-if
```c++
#include<iostream>

int main()
{
	int a = 19;
	if (a % 2 == 0)
	{
	    std::cout << "div2" << std::endl;
	}
	else if (a % 3 == 0)
	{
		std::cout << "div3" << std::endl;
	}
	else
	{
	      std::cout << "Not div2 and div3" << std::endl;
	}

	return 0;
}
```
### Форма ?:
?: е форма която наподобява конструкцията if - else. Формално ще наричаме оператора ?: тернарен оператор.

Синтаксис: <булев_израз> ? <оператор_при_истина> : <оператор_при_лъжа>

Семантика: Изчислява се булевият израз, след което се изпълнява при:
 - върнат резултат истина (true) - изпълнява се операторът след ?
 - върнат резултат лъжа (false) - изпълнява се операторът след :

```c++
#include<iostream>

int main()
{
	const int ALLOW_AGE = 18;
	int age = 19;

	std::cout << (age < ALLOW_AGE ? "Drink denied" : "Drink permitted") << std::endl;
	
	return 0; 
}
```

### Оператор switch
Операторът switch позволява тестването на дадена променлива за равенство измежду списък от стойностти. Всяка стойност за проверка се нарича случай (case).

Синтаксис:
```c++
switch(<израз|стойност>)
{
	case <стойност_за_проверка>: <операции_за_изпълнение>; break;
	...
	case <стойност_за_проверка>: <операции_за_изпълнение>; break;
	
	default: <операции_за_изпълнение>; break;
}
```
Семантика: Подаваме дадена стойност като параметът на switch, след което се проверява в кой случай стойността от този параметър ще съвпадне по стойност със стойността на променливите за проверка, при което се изпълнява операциите подадени към този случай. Ако никоя стойност не съвпадне с подадената се изпълнява случаят default.

Допълнителни правила:
 - може да имате свободен брой случаи (case), като трябва за всеки един да дадете стойност по която да се проверява;
 - стойносттите по които проверяваме трябва да бъдат от същия тип както подадената за проверка; 
 - при откриване на съвпадение се изпълняват подадените операции до срещане на оператор break, т.е ако е влезнал във втория case и няма break в него, ще се изпълнят всички оператори в останалите case-ове до достигане на оператор break;
 - при стигане до break, изпълнението на оператора switch се прекратява и продължава изпълнението на програмата след него;
 - default е опционален, т.е не е от задължителния синтаксис на оператора switch. Той се използва когато никой от изброените условия не се е изпълнило и искаме да отбележим това;

Блок-схема:

![alt tag](https://github.com/GeorgiMinkov/FMI_IS_UP_1_2016/blob/master/week03/image/Diagram_switch.png)
