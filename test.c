#include <stdio.h>
void memcpy(void* src,void*dst,unsigned long len){
    char *src_ = (char *)src;
    char *dst_ = (char *)dst;
    for (int i = 0;i<len;++i){
        dst_[i] = src_[i];
    }
}
int main(){
    float arr[3] = {1.1, 2.2, 3.3};
    float brr[3];
    memcpy(arr, brr, sizeof(float) * 3);
    for (int i = 0;i<3;++i)
        printf("%f ",brr[i]);
}