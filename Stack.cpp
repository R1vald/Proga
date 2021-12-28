//������������ ������ �3 ������ �1 ������� �1
//	�������� ���������, ����������� �������� �� ������. ��� ������ ���������:
//	��������� ������� ������ �����(�������� POP)
//	������� �������� �����(�������� PUSH)
//	�������� ���������� ��� ������� �������� �����(�������� SWAP)
//	����������� �������� ����� ��������� � �����
//	������� �����
//	������������� ������ �������� �� ������� �����

#include <iostream>
using namespace std;

const int SIZE_OF_MAS = 100;

struct STACK {
	int MAS[SIZE_OF_MAS]; // ��������� ��� ��������� �����
	int	count;
	int size;
};

void CREATION(STACK* P) {
	P->count = 0;
	P->size = 0;
}

int FULL(STACK* P) {
	if (P->count == 0) return 1;
	else if (P->count == SIZE_OF_MAS) return -1;
	else return 0;
}

void POP(STACK *P) //��������� ������� � ������� �����
{
	int EL_OF_STACK;
	cout << "\nEnter value`s: ";
	cin >> EL_OF_STACK;
	P->MAS[P->count] = EL_OF_STACK;
	P->count++; // ��� ������ � ������� SWAP
	P->size++; // ������� ������� �������
}

void PUSH(STACK *P) { // ������� ������� � ������� �����
	P->count--;
}

//void SWAP(STACK* P) { // �������� �� �� �� �����, ����� �� �������� �������� �������
//	int box1, box2, COUNTER; //������ ��������� ��������
//	COUNTER = P->count;
//	COUNTER--;
//	box1 = P->MAS[COUNTER];
//	COUNTER--;
//	box2 = P->MAS[COUNTER];
//
//	P->MAS[COUNTER] = box1;
//
//	//P->count++;
//
//	P->MAS[COUNTER] = box2;
//	COUNTER++;
//	cout << "\nBOX 1 = " <<  P->MAS[COUNTER];
//	COUNTER--;
//	cout << "\nBOX 2 = " << P->MAS[COUNTER];
//	cout << endl;
//}

//void SWAP(STACK* P) { // �������� �� �� �� �����, ����� �� �������� �������� �������
//	int temp , temp1 ,COUNTER; //������ ��������� ��������
//	COUNTER = P->count;
//	COUNTER--;
//	temp = P->MAS[COUNTER];
//	COUNTER--;
//	temp1 = P->MAS[COUNTER];
//	P->MAS[P->count]  = P->MAS[0];
//	P->MAS[COUNTER] = temp;
//	COUNTER++;
//
//}

void SWAP(STACK* P) { // �������� �� �� �� �����, ����� �� �������� �������� �������
	setlocale(LC_ALL, "rus");
	int TEMP, COUNTER; //������ ��������� ��������
	COUNTER = P->count;
	COUNTER--;
	TEMP= P->MAS[COUNTER];
	COUNTER--;
	P->count--;
	P->MAS[P->count] = P->MAS[COUNTER];
	P->count--;
	P->MAS[P->count] = TEMP;
	P->count += 2;

}
void SIZE_OF_STACK(STACK *P) {
	cout << "\nSize of stack = " << P->count << endl;

}

void CLEAN(STACK *P){
	P->count = 0;
	/*int size_stack = 0;
	size_stack = P->count;
	for (int i = size_stack;!P->count; i--)
	{
		P->count--;
	}*/
	cout << "\nSTACK is clean\n";
}

void READ(STACK *P) {
	cout << "________________________________________________________________\n";
	for (int i = 0; i < P->count; i++)
	{
		cout << "|" << P->MAS[i];
	}
	cout << "\n________________________________________________________________\n";
}


int main() {
	STACK A;
	CREATION(&A);
	int choose;
	do
	{
		cout << "\nmenu:\n1 - POP\n2 - PUSH\n3 - SWAP\n4 - SIZE OF STACK\n5 - CLEAN\n6 - READ\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (FULL(&A) == -1) cout << "\nStack is full\n";
			else POP(&A); break;
		case 2:
			if (FULL(&A) == 1) cout << "\nStack haven`t elements\n";
			else { PUSH(&A); cout << "\nElement has deleted\n";break; }
		case 3:
			SWAP(&A); break;
		case 4:
			SIZE_OF_STACK(&A);
			break;
		case 5:
			CLEAN(&A);
			break;
		case 6:
			READ(&A);
			break;
		default:
			break;
		}

	} while (choose!=0);

	//cout << "\n" << A.MAS[0] << "|" << A.MAS[1] << "|" << A.MAS[2];
	
}