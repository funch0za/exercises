#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {
  int fd;
  size_t size;
  char string[] = "Hello, World!";
  /*
   * Обнуляем маску создания файлов текущего процесса
   * для того, чтобы права доступа у создаваемого файла
   * точно соответсовали параметру вызова open()
   * */
  umask(0);
  /*
   * Попытаемся открыть файл с именем myfile в текущей
   * директории только для операции вывода. Если файла
   * не существует, попробуй его создать с правами доступа 666,
   * т.е. read-write для всех категорий
   * пользователей
   * */
  if ((fd = open("myfile", O_WRONLY | O_CREAT, 0666)) < 0) {
    /*
     * Если файл открыть не удалось, печатаем об 
     * этом сообщение и прекращаем работу
     * */
    printf("Can\'t open file\n");
    exit(-1);
  }
  /*
   * Пробуем записать в файл 14 байт из нашего
   * массива, т.е. всю строку "Hello, World!" вместе
   * с признаком конца строки
   * */
  size = write(fd, string, 14);
  if (size != 14) {
    /*
     * Если записалось меньшее количество байт,
     * сообщаем об ошибке
     * */
    printf("Can'\t write all string\n");
    exit(-1);
  }
  if (close(fd) < 0) {
    printf("Can\'t close file\n");
  }
  return 0;
}
