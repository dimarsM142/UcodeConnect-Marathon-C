char *mx_strcpy(char* dst, const char* src){
   char *copy = dst;
   while (*src) {
       *dst++ = *src++;
   }
   *dst = 0;
   return copy;
}

