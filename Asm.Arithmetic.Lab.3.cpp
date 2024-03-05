#include <iostream>

int main()
{
    int a, c; 
    std::cout << "Task 1:"<< std::endl << "'a' value: ";
    std::cin >> a;
    __asm
    {
        mov eax, 1;
        mov ecx, 12;
        mov ebx, 0;
    beg1:
        mul a;
        loop beg1;
        add ebx, eax;
        mov ecx, 8;
        mov eax, 1;
    beg2:
        mul a;
        loop beg2;
        add ebx, eax;
        add ebx, a;
        mov c, ebx;
    }
    std::cout << "Answer: "<< c << std::endl<<std::endl;

    std::cout << "Task 2: " << std::endl;
    short arr1[20];
    short arr2[20];
    for (int i = 0; i < 20; ++i) {
        arr1[i] = 0;
        arr2[i] = 0;
    }
    __asm
    {
        mov cx, 16;
    calc:
        mov ax, 0;
        mov al, cl;
        mov dl, 3;
        mul dl;
        mov bx, ax;
        mov ax, 50;
        sub ax, bx;
        mov dl, 2;
        div dl;
        cmp ah, 0;
        jne skip;
        mov arr1[ecx], ax;
        mov ax, bx;
        mov dl, 3;
        div dl;
        mov ah, 0;
        mov arr2[ecx], ax;
    skip:
        loop calc;                 
    }
    for (int i = 0; i < 20; i+=1) {
        if (arr1[i] != 0 && arr2[i] != 0) {
            std::cout << "3*" << arr2[i] << " + 2*" << arr1[i] << " = 50" << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "Task 3: " << std::endl;
    int arr[50];
    for (int i = 0; i < 47; ++i) {
        arr[i] = 0;
    }
    arr[0] = 0;
    arr[1] = 1;
    __asm
    {
        mov ecx, 4;
    whl:
        cmp ecx, 185;
        ja end;
        mov eax, 0;
        mov eax, arr[ecx];
        sub ecx, 4;
        add eax, arr[ecx];
        add ecx, 8;
        mov arr[ecx], eax;
        jmp whl;
    end:
    }
    for (int i = 0; i < 47; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl<< std::endl;

    std::cout << "Task 4: " << std::endl;
    int numb1, numb2;
    std::cout << "Enter numb1 and numb2 values in fraction numb1/numb2:" << std::endl;
    std::cin >> numb1 >> numb2;
    int num1 = numb1, num2 = numb2;
    std::cout << std::endl;  

    std::cout << num1 << std::endl;

   __asm
    {
       mov eax, 1
       shl eax, 31
        and eax, numb1;
        jz pos;
        neg num1;
        neg numb1;
    NOD1:
        mov edx, 0;
        mov eax, num1;
        div num2;
        cmp edx, 0;
        jz exit1;
        mov ebx, num2;
        mov num1, ebx;
        mov num2, edx;
        jmp NOD1;
    exit1:
        mov eax, numb1;
        div num2;
        mov numb1, eax;
        neg numb1;
        mov eax, numb2;
        div num2;
        jmp ex;
    pos:
    NOD2:
        mov edx, 0;
        mov eax, num1;
        div num2;
        cmp edx, 0;
        jz exit2;
        mov ebx, num2;
        mov num1, ebx;
        mov num2, edx;
        jmp NOD2;
    exit2:
        mov eax, numb1;
        div num2;
        mov numb1, eax;
        mov eax, numb2;
        div num2;
    ex:
        mov numb2, eax
    }
    
    
    std::cout << "Result: " << numb1 << "/" << numb2 << std::endl;
    return 0;
}
