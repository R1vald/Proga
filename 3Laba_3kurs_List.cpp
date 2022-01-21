//#include<iostream>
//
//using std::cout;
//
//using std::cin;
//using std::endl;
//
//template<class Type>
//class List
//{
//protected:
//	static List<Type>* Head;
//	static List<Type>* Last;
//	static int number;
//
//	Type data;
//	List<Type>* Next;
//
//	List<Type>* Get(int number)
//	{
//		if (number < 0 || number > List<Type>::number)
//			return 0;
//
//		List<Type>* pointer = Head;
//
//		for (int i = 0; pointer->Next != NULL; i++, pointer = pointer->Next)
//		{
//			if (i == number)
//				return pointer;
//
//		}
//
//	}
//
//public:
//	void pop(Type input)
//	{
//		if (number == 0)
//		{
//			Head = new List<Type>;
//			Last = Head;
//			Head->data = input;
//
//		}
//		else
//		{
//			Last->Next = new List<Type>;
//			Last->Next->data = input;
//			Last = Last->Next;
//		}
//
//		number++;
//		/*this->data = input;
//		cout << "This data is " << this->data << " num:" << number << endl;*/
//	}
//
//	void show()
//	{
//		int i = 0;
//
//		if (number == 0)
//		{
//			cout << "List is empty" << endl;
//			return;
//
//		}
//
//		for (List<Type>* pointer = Head; pointer != NULL; pointer = pointer->Next, i++) {
//			cout << i << ": " << pointer->data << endl;
//			//if (i > number) break;
//		}
//
//
//	}
//
//	void delete_element(int num = (number - 1))
//	{
//		if (num > number)
//			exit(1);
//
//		if (num == 0)
//		{
//			List<Type>* pointer = Head;
//			Head = Head->Next != NULL ? Head->Next : NULL;
//
//			delete pointer;
//
//		}
//		else
//		{
//			List<Type>* pointer = Get(num);
//			if (Get(num) == Last)
//			{
//				pointer = Get(num);
//				Last = Get(num - 1);
//				Get(num - 1)->Next = NULL;
//			}
//			else
//				Get(num - 1)->Next = Get(num)->Next;
//
//			delete pointer;
//			/*Stack<Type>* pointer = Head;
//			Stack<Type>* pointer_pred = NULL;
//
//			for (int i = 0; i <= num; i++)
//			{
//				if (i != num)
//				{
//					pointer_pred = pointer;
//					pointer = pointer->Next;
//				}
//				else
//				{
//
//
//					if (pointer == Last)
//					{
//						Last = pointer_pred;
//						pointer_pred->Next = NULL;
//					}
//					else
//						pointer_pred->Next = pointer->Next;
//					delete pointer;
//					break;
//				}
//
//			}*/
//		}
//		number--;
//	}
//
//	void push() { delete_element(0); }
//
//	int Get_number() { return number; }
//
//	void swap(int left, int right)
//	{
//		if (left == right)
//			exit(1);
//		else
//		{
//			int left_element = std::min(left, right);
//			int right_element = std::max(left, right);
//
//
//			List<Type>* left_pred = Get(left_element - 1);
//			List<Type>* left_origin = Get(left_element);
//
//			List<Type>* right_pred = Get(right_element - 1);
//			List<Type>* right_origin = Get(right_element);
//
//			List<Type>* left_origin_next = left_origin->Next;
//			if (right_element - left_element == 1)
//				left_origin_next = left_origin;		//обработка соседних элементов
//
//			List<Type>* right_origin_next = right_origin != Last ? right_origin->Next : NULL;
//
//			if (left_pred != NULL)
//				left_pred->Next = right_origin;
//			else
//				Head = right_origin;
//
//			right_pred->Next = left_origin;
//
//			left_origin->Next = right_origin_next;
//
//			right_origin->Next = left_origin_next;
//
//		}
//
//	}
//
//	void test(int n)
//	{
//		for (int i = 0; i < number; i++)
//		{
//			cout << i << " " << Get(i) << "\t";
//			cout << i << ".Next " << Get(i)->Next << endl;
//
//		}
//	}
//
//	void clear()
//	{
//
//		if (Get_number() == 0)
//			return;
//		for (int i = Get_number() - 1; i != -1; i--)
//			delete_element();
//
//
//	}
//
//	Type Read(int n) 
//	{
//		return n > Get_number() || Get_number() == 0 ? NULL : Get(n)->data; 
//	}
//
//	~List()
//	{
//		//clear();
//	}
//
//};
//
//template<class Type>
//int List<Type>::number = 0;
//
//template<class Type>
//List<Type>* List<Type>::Head;
//
//template<class Type>
//List<Type>* List<Type>::Last;
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//
//	List<int> st11;
//
//	int choice;
//
//	do {
//		system("cls");
//		st11.show();
//		cout << "Операции" << endl;
//		cout << "1. добавить элемент в список" << endl;
//		cout << "2. удалить элемент списка" << endl;
//		cout << "3. обменять значениями два элемента в списке" << endl;
//		cout << "4. определение текущего числа элементов в списке" << endl;
//		cout << "5. очистка списка " << endl;
//		cout << "6. неразрушающее чтение элемента из списка" << endl;
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			int i;
//			cin >> i;
//			st11.pop(i);
//			st11.show();
//			break;
//		case 2:
//			cout << "Введите индексы элемента для удаления: ";
//			cin >> i;
//			st11.delete_element(i);
//			st11.show();
//			break;
//		case 3:
//			int l, r;
//			cout << "Введите индексы элементов для обмена: ";
//			cin >> l >> r;
//			st11.swap(l, r);
//			st11.show();
//			break;
//		case 4:
//			cout << "Текущее число элементов в стеке:" << st11.Get_number() << endl;
//			break;
//		case 5:
//			st11.clear();
//			st11.show();
//			break;
//		case 6:
//			int j;
//			cout << "Введите индекс считываемого элемента: "; cin >> j;
//			cout << j << ".data = " << st11.Read(j) << endl;
//			break;
//		}
//		system("pause");
//	} while (choice != 0);
//
//	system("pause");
//	return 0;
//}
