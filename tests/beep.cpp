#include <dos.h>
int main() {
int x;
for(x=0;x<=13000;x++){
sound(x);
delay(100);
}
nosound();
return 0;
}