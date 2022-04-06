#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
// https://www.cnblogs.com/chuanfengzhang/p/8447251.html

// ● strcpy 是依据 “\0” 作为结束判断的，如果 s2 的空间不够，则会引起 buffer overflow
// ● memcpy不检查“\0”，全部复制，比如"hell\0oworld";同时支持数组，整数，结构体，类的复制
// ● 使用strncpy时，确保s2的最后一个字符是“\0”，不足n，填0；复制也是以s1的“\0”终止
// ● 使用strncpy或memcpy时，n应该大于strlen(s1)，或者说最好n >= strlen(s1)+1；这个1 就是最后的“\0”

void *my_memcpy(void *dst, const void *src, int n) {  // memcpy实现，按字节byte实现
  if (dst == NULL || src == NULL || n < 0) return NULL;

  char *pdst = (char*)dst;  // dst最终需要返回，使用临时指针保存
  char *psrc = (char*)src;

  if (pdst > psrc && pdst < psrc + n) {   // 存在写覆盖的情况
    pdst = pdst + n - 1;
    psrc = psrc + n - 1;
    while (n--) *pdst = *psrc--;
  } else {
    while(n--) *pdst++ = *psrc++;
  }
  return dst;
}

char* my_strcpy(char *dst, char *src) {
  if (dst == NULL || src == NULL) return NULL;
  char *pdst = dst;
  while(*src != '\0') {
    *pdst++ = *src++;
  }
  return dst;
}

void Test1() {
  printf("----------------------start Test1----------------------\n");
  const char *t1 = "123456789";
  char *t2, *t3;
  printf("%s\n", t1);
  t2 = (char*)malloc(6);  // 必须先申请空间，否则memcpy的时候会发生段错误
  memcpy(t2, t1, 6);
  printf("%s\n", t2);
  int length = strlen(t1);
  printf("%d\n", length);
  t3 = (char*)malloc(length * sizeof(char));
  my_memcpy(t3, t1, length);   // 本地实现的memcpy
  printf("%s\n", t3);
  free(t2);
  free(t3);
  printf("----------------------end Test1----------------------\n");
}

void Test2() {
  printf("----------------------start Test2----------------------\n");
  char t1[] = "123456789";
  t1[6] = '\0';
  int length = strlen(t1);
  printf("t1 %s  %d\n", t1, length);
  char *t2, *t3, *t4;
  t2 = (char*)malloc(3 * sizeof(char));
  strcpy(t2, t1);  
  printf("t2 %s  %d\n", t2, (int)strlen(t2));
  t3 = (char*)malloc(3 * sizeof(char));
  strncpy(t3, t1, 3);
  printf("t3 %s  %d\n", t3, (int)strlen(t3));
  memcpy(t4, t1, length + 1);
  printf("t4 %s  %d\n", t4, (int)strlen(t4));
  printf("----------------------end Test2----------------------\n");
}

int CheckAudioInvalid(char *buf, size_t size) {
  int invalid_count = 0;
  for (size_t i = 0; i < size / 8; i++) {
    for (size_t j = 0; j < 4; j++) {
      if (j == 0 || j == 2) {
        uint8_t *cur_buf = reinterpret_cast<uint8_t *>(buf + j);
        if (*cur_buf == 0x00 || *cur_buf == 0xFF || *cur_buf == 0x01 ||
            *cur_buf == 0xFE) {
          invalid_count++;
        }
      }
    }
    buf += 8;
  }
  if (invalid_count > 1000) {
    return 1;
  }
  std::cout << invalid_count << std::endl;
  return 0;
}

int main(int argc, char **argv) {
  printf("hello lch\n");
  char temp[2048];
  for (int i = 0; i < 2048 / 8; i++) {
    for (int j = 0; j < 4; j++) {
      temp[i * 8 + j] = 0x12;
    }
    for (int j = 4; j < 8; j++) {
      temp[i * 8 + j] = 0x00;
    }
  }
  std::cout << CheckAudioInvalid(temp, 2048) << std::endl;
  printf("end lch\n");
  return 0;
}