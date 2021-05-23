#include<stdio.h>
#include<string.h>
#include<windows.h>


// b1 ve tao menu
void MENU() {
  int luachon;
  while (12) {
    printf("\t----MENU----\n");
    printf("\n1. Chon X .");
    printf("\n2. Chon O .");
    printf("\n3. Thoat  game . ");

    scanf("%d", & luachon);

    if (luachon != 1 && luachon != 2 && luachon != 3) {
      printf(" lua chon khong hop le : ");
    } else if (luachon = 1) {
      printf("\n Nguoi choi 1 là X\n");
    } else if (luachon = 2) {
      printf("\n Nguoi choi 2 là O\n");
    } else {}
    break;
  }
}

// ve ban co 
char vebanco[3][3] = {
  {
    1,
    2,
    3
  },
  {
    4,
    5,
    6
  },
  {
    7,
    8,
    9
  }
};

char nguoichoi = 'X';
void banco() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("\t|%5d |  ", vebanco[i][j]);

    }
    printf("\n");

  }
}
// nhap x vao bang 
void nhapX() {
  int n;
  printf("Nhap vi tri tung ung ==>  ");
  scanf("%d", & n);
  switch (n) {
  case 1:
    vebanco[0][0] = nguoichoi;
    break;
  case 2:
    vebanco[0][1] = nguoichoi;
    break;
  case 3:
    vebanco[0][2] = nguoichoi;
    break;
  case 4:
    vebanco[1][0] = nguoichoi;
    break;
  case 5:
    vebanco[1][1] = nguoichoi;
    break;
  case 6:
    vebanco[1][2] = nguoichoi;
    break;
  case 7:
    vebanco[2][0] = nguoichoi;
    break;
  case 8:
    vebanco[2][1] = nguoichoi;
    break;
  case 9:
    vebanco[2][2] = nguoichoi;
    break;
  }
}
// hàm doi luot X O 
void lanluot() {
  if (nguoichoi = 'X')
    nguoichoi = 'o';
  else {
    nguoichoi == 'X';
  }

}
// ham gotoxy
void gotoxy(int x, int y) {
  static HANDLE h = NULL;
  if (!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = {
    x,
    y
  };
  SetConsoleCursorPosition(h, c);
}

int main() {
  gotoxy(35, 10);
  banco();
  while (true) {
    nhapX();
    banco();
    lanluot();
  }

  return 0;
}