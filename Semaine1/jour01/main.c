#include <unistd.h>

int main() {
    for (int i = '0'; i <= '9'; i++) {

        for (int j = '0'; j <= '9'; j++) {

            for (int k = '0'; k <= '9'; k++) {
                write(1, &i, 1);
                write(1, &j, 1);
                write(1, &k, 1);
                char c = ' ';
                write(1, &c, 1);
            }
        }
    }
}
