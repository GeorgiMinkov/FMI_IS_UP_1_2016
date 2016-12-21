#Практикум седмица 12

##Материя:
 - Масиви
 - Функции

##Днес ще научим:
 - Указатели

###Указатели
####За какво са и за какво ни трябват?
	Указателят е променлива, чиято стойност е адресът на друга променлива. Това е едно от най - мощните оръжия на езика C++. Чрез нея можем директно да променяме стойността която се намира в дадена  клетка от паметта. 
	Нещо което вероятно не сте предполагали до сега е, че масивите които използваме са всъщност указатели(ще бъде разгледано след малко). 
	Най - важната същност на указателите се крие в това, че съчетавайки ги с функциите получаваме мощно оръжие, чрез което да оперираме над дадените променливи.


####Синтаксис и семантика:
```c++
<object_type> *<object_name_pointer> = &<object_name_transmitter>;
```	
Пример:

```c++
int a = 50;
int *ptr = &a;
```
По този начин казваме следното: създали сме променлива от тип int и сме я инициализирали със стойност 50, след това създаваме променлива от тип указател към int на когото присвояваме адреса на а. Вземането на адрес на дадена променлива се прави чрез &.

Най - важното е да се разбере, че указателите пазят адреса към паметта на това с което искаме да оперираме.

Когато сме инициализирали стойност както в случая по - горе със стойност 50 и на указател ptr стойност адреса на а. Тогава ако искаме да достъпим стойността на дадения адрес пишем - *ptr, по този начин казваме дай ми това което се намира на адреса към който сочи ptr.

[!alt tag](https://github.com/GeorgiMinkov/FMI_IS_UP_1_2016/blob/master/week12/MemoryPointer.png)

Пример:
```c++
int a = 50;
int *ptr = &a;

std::cout << *ptr << std::endl; // 50
std::cout << ++*ptr << std::endl; // 51
std::cout << a << std::endl; // 51

```

####Масиви и указатели
Споменахме, че масивът е указател, трудно е да повявате? Създайте масив (да кажем от double), след това напишете:
```c++
double arr[5] = { 4, 5, 6, 7.6, 9 };
std::cout << arr << std::endl; // Ще се изпише на конзолата: 0x7ffcd4326470 
```
Това е така, защото когато създаваме масив ние всъщност създаваме указател към първия елемент на масива и когато казваме arr[index] (еквивалентно е *(arr + index)) казваме дай ми елементът, който се намира на позицията: на първия елемент + отместване

####Псевдоними и указатели във функции
Когато използваме функции(както го правим до сега) и подаваме даден аргумент (подаване по стойност), ние дефакто създаваме нова променлива някъде в паметта (виж графиката) и всички промени които осъществим се правят над новата променлива, но не и над променливата която сме подали.

За да правим промени над оригиналните променливи, които сме подали, се използват указателите и псевдонимите. 

Казано разговорно какво представляват:
	- Псевдонимът казва, когато подадеш дадена променлива, на тази която се присвоява, направо я взима по референция, т.е направо я вземи където се намира по адреса, който е и оперира в оригиналната памет.
	- Указател - подаваме адреса на променливата и оперираме над него

![alt tag](https://github.com/GeorgiMinkov/FMI_IS_UP_1_2016/blob/master/week12/1Diagram.png)

Пример: Искаме да намерим сумата на две числа, като използваме трета променлива в която да се пази резултата. (т.е за учебна цел няма да връщам сумата като резултат, а ще пазя резултата в предварително създадена променлива)

```c++
// Example program
#include <iostream>

// without reference or pointer => will lose value of sum
void sumWithoutRefOrPointer(int numL, int numR, int sum)
{
    sum = numL + numR;
}

// with reference
void sumIt(int numL, int numR, int &sum)
{
    sum = numL + numR;
}

// with pointer
void sumIt(int numL, int numR, int *sum)
{
    *sum = numL + numR;
}

int main()
{
  int numL = 4, numR = 6, sum = 0;
  
  sumWithoutRefOrPointer(numL, numR, sum);
  std::cout << "1) " << sum << std::endl; // 0
  
  sumIt(numL, numR, sum);
  std::cout << "2) " << sum << std::endl; // 10
  
  sumIt(numL + 1, numR, &sum); // we must put adress of sum
  std::cout << "3) " << sum << std::endl; // 11

  return 0;

}
```

Виждаме това което коментираме до сега. Там къде сме подали по стойност (т.е. първата функция), правим копие и след края на изпълнение се трие това копие, като стойността на sum (това е main) не е променена.
Когато подаваме по референция ние работим директно в паметта и от там идва и промяната на стойността на променливата sum.
При използването на указател наблюдаваме същото, вземи адреса на променливата и след това с * казваме влез вътре и промени стойността.
